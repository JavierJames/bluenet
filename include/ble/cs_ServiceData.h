/**
 * @file
 * Service data.
 *
 * @authors Crownstone Team, Christopher Mason.
 * @copyright Crownstone B.V.
 * @date May 4, 2016
 * @license LGPLv3+, Apache License, or MIT, your choice
 */
#pragma once

#include <events/cs_EventListener.h>
#include <events/cs_EventDispatcher.h>
#include <storage/cs_Settings.h>
#include <storage/cs_State.h>
#include "drivers/cs_Timer.h"
#include "cfg/cs_Config.h"

#include <cstring>

#if BUILD_MESHING == 1
#include <protocol/cs_MeshMessageTypes.h>
#endif

#define SERVICE_DATA_PROTOCOL_VERSION 1

//! bitmask map (if bit is true, then):
//! [0] New Data Available
//! [1] ID shown is from external Crownstone
//! [2] ....
//! [3] ....
//! [4] ....
//! [5] ....
//! [6] ....
//! [7] operation mode setup
enum ServiceBitmask {
	NEW_DATA_AVAILABLE    = 0,
	SHOWING_EXTERNAL_DATA = 1,
	SERVICE_BITMASK_ERROR = 2,
	RESERVED2             = 3,
	RESERVED3             = 4,
	RESERVED4             = 5,
	RESERVED5             = 6,
	SETUP_MODE_ENABLED    = 7
};

union service_data_t {
	struct __attribute__((packed)) {
		uint8_t  protocolVersion;
		uint16_t crownstoneId;
		uint8_t  switchState;
		uint8_t  eventBitmask;
		int8_t   temperature;
		int32_t  powerUsage;
		int32_t  accumulatedEnergy;
		uint8_t  rand;
		uint16_t counter;
	} params;
	uint8_t array[sizeof(params)] = {};
};

class ServiceData : EventListener {

public:
	ServiceData();

	void updatePowerUsage(int32_t powerUsage) {
		_serviceData.params.powerUsage = powerUsage;
	}

	void updateAccumulatedEnergy(int32_t accumulatedEnergy) {
		_serviceData.params.accumulatedEnergy = accumulatedEnergy;
	}

	void updateCrownstoneId(uint16_t crownstoneId) {
		_serviceData.params.crownstoneId = crownstoneId;
	}

	void updateSwitchState(uint8_t switchState) {
		_serviceData.params.switchState = switchState;
	}

	void updateEventBitmask(uint8_t bitmask) {
		_serviceData.params.eventBitmask = bitmask;
	}

	void updateTemperature(int8_t temperature) {
		_serviceData.params.temperature = temperature;
	}

	// Set initial to true when this is just the initial data,
	// when there's no need to send out the event EVT_ADVERTISEMENT_UPDATED.
	void updateAdvertisement(bool initial);

	void updateEventBitmask(uint8_t bit, bool set) {
		if (set) {
			_serviceData.params.eventBitmask |= 1 << bit;
		} else {
			_serviceData.params.eventBitmask &= ~(1 << bit);
		}
	}

	uint8_t* getArray() {
		if (Settings::getInstance().isSet(CONFIG_ENCRYPTION_ENABLED) && _operationMode != OPERATION_MODE_SETUP) {
			return _encryptedArray;
		}
		else {
			return _serviceData.array;
		}

	}

	uint16_t getArraySize() {
		return sizeof(service_data_t);
	}

	void sendMeshState(bool event);

private:

	app_timer_t    _updateTimerData;
	app_timer_id_t _updateTimerId;

	uint8_t _operationMode;
	bool _connected;

	/* Static function for the timeout */
	static void staticTimeout(ServiceData *ptr) {
		ptr->updateAdvertisement(false);
	}

	bool isBitSet(uint8_t bitMask, uint8_t bit) {
		return bitMask & (1 << bit);
	}

	// Decide which crownstone's state to advertise.
	// Fills the given serviceData.
	// Returns false if there's no external state to advertise.
	bool getExternalAdvertisement(uint16_t ownId, service_data_t& serviceData);

	service_data_t _serviceData;
	service_data_t _serviceDataExt;

	union {
		struct __attribute__((packed)) {
			uint8_t  protocolVersion;
			uint8_t  payload[16];
		} _encryptedParams;
		uint8_t _encryptedArray[sizeof(service_data_t)] = {};
	};

	//! Counter that keeps up the number of times that the advertisement has been updated.
	uint32_t _updateCount;

#if BUILD_MESHING == 1
	struct __attribute__((packed)) advertised_ids_t {
		uint8_t size;
		int8_t head; // Index of last crownstone ID that was advertised
		id_type_t list[MESH_STATE_HANDLE_COUNT * MAX_STATE_ITEMS];
	};

	struct __attribute__((packed)) last_seen_id_t {
		uint16_t id;
		uint32_t timestamp;
		uint16_t hash;
	};

	void onMeshStateMsg(id_type_t ownId, state_message_t* stateMsg);

	void onMeshStateSeen(id_type_t ownId, state_item_t* stateItem);

	id_type_t chooseExternalId(id_type_t ownId, state_message_t stateMsgs[], bool hasStateMsg[], bool eventOnly);

	//! List of external crownstone IDs that have been advertised, used to determine which external crownstone to advertise.
	advertised_ids_t _advertisedIds;

	//! List of external crownstone IDs with timestamp when they were last seen, and a hash of its data.
	last_seen_id_t _lastSeenIds[MESH_STATE_HANDLE_COUNT * 5];

//	//! List of external crownstone IDs which changed due to and event and that have been advertised
//	//! Used to determine which external crownstone to advertise.
//	advertised_ids_t _eventAdvertisedIds;

	//! List that is used temporarily
	advertised_ids_t _tempAdvertisedIds;

	//! Number of times we should still only advertise states triggered by events.
	//! This is set to some number when a state triggered by event was received, and then counts down.
	uint8_t _numAdvertiseChangedStates;
#endif

	void handleEvent(uint16_t evt, void* p_data, uint16_t length);

#if BUILD_MESHING == 1
	app_timer_t    _meshStateTimerData;
	app_timer_id_t _meshStateTimerId;

	/* Static function for the timeout */
	static void meshStateTick(ServiceData *ptr) {
		ptr->sendMeshState(false);
	}
#endif

};

