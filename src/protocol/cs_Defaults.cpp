#include <protocol/cs_Defaults.h>

void getDefaults(CS_TYPE configurationType, void* default_value, size16_t & default_size) {

    default_size = TypeSize(configurationType);
    // LOGd("Get default, size=%i", default_size);

    switch(configurationType) {
	case CS_TYPE::CONFIG_NAME: {
	    default_size = MIN(default_size, sizeof(STRINGIFY(BLUETOOTH_NAME)));
	    memcpy(default_value, STRINGIFY(BLUETOOTH_NAME), default_size);
	    break;
	}
	case CS_TYPE::CONFIG_MESH_ENABLED: 
	    *(TYPIFY(CONFIG_MESH_ENABLED)*)default_value = CONFIG_MESH_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_ENCRYPTION_ENABLED: 
	    *(TYPIFY(CONFIG_ENCRYPTION_ENABLED)*)default_value = CONFIG_ENCRYPTION_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_IBEACON_ENABLED: 
	    *(TYPIFY(CONFIG_IBEACON_ENABLED)*)default_value = CONFIG_IBEACON_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_SCANNER_ENABLED: 
	    *(TYPIFY(CONFIG_SCANNER_ENABLED)*)default_value = CONFIG_SCANNER_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_CONT_POWER_SAMPLER_ENABLED: 
	    *(TYPIFY(CONFIG_CONT_POWER_SAMPLER_ENABLED)*)default_value = CONFIG_POWER_SAMPLER_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_DEFAULT_ON: 
	    *(TYPIFY(CONFIG_DEFAULT_ON)*)default_value = CONFIG_RELAY_START_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_PWM_ALLOWED: 
	    *(TYPIFY(CONFIG_PWM_ALLOWED)*)default_value = CONFIG_PWM_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_SWITCH_LOCKED: 
	    *(TYPIFY(CONFIG_SWITCH_LOCKED)*)default_value = CONFIG_SWITCH_LOCK_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_SWITCHCRAFT_ENABLED: 
	    *(TYPIFY(CONFIG_SWITCHCRAFT_ENABLED)*)default_value = CONFIG_SWITCHCRAFT_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_FLOOR: 
	    *(TYPIFY(CONFIG_FLOOR)*)default_value = CONFIG_FLOOR_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_NEARBY_TIMEOUT: 
	    *(TYPIFY(CONFIG_NEARBY_TIMEOUT)*)default_value = CONFIG_SCANNER_NEARBY_TIMEOUT_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_IBEACON_MAJOR: 
	    *(TYPIFY(CONFIG_IBEACON_MAJOR)*)default_value = BEACON_MAJOR;
	    break;
	case CS_TYPE::CONFIG_IBEACON_MINOR: 
	    *(TYPIFY(CONFIG_IBEACON_MINOR)*)default_value = BEACON_MINOR;
	    break;
	case CS_TYPE::CONFIG_IBEACON_UUID: 
	    default_size = MIN(default_size, sizeof(STRINGIFY(BEACON_UUID)));
	    memcpy(default_value, STRINGIFY(BEACON_UUID), default_size);
	    break;
	case CS_TYPE::CONFIG_IBEACON_TXPOWER: 
	    *(TYPIFY(CONFIG_IBEACON_TXPOWER)*)default_value = BEACON_RSSI;
	    break;
	case CS_TYPE::CONFIG_TX_POWER: 
	    *(TYPIFY(CONFIG_TX_POWER)*)default_value = TX_POWER;
	    break;
	case CS_TYPE::CONFIG_ADV_INTERVAL: 
	    *(TYPIFY(CONFIG_ADV_INTERVAL)*)default_value = ADVERTISEMENT_INTERVAL;
	    break;
	case CS_TYPE::CONFIG_PASSKEY:
	    default_size = MIN(default_size, sizeof(STRINGIFY(STATIC_PASSKEY)));
	    memcpy(default_value, STRINGIFY(CONFIG_PASSKEY), default_size);
	    break;
	case CS_TYPE::CONFIG_MIN_ENV_TEMP:
	    *(TYPIFY(CONFIG_MIN_ENV_TEMP)*)default_value = MIN_ENV_TEMP;
	    break;
	case CS_TYPE::CONFIG_MAX_ENV_TEMP:
	    *(TYPIFY(CONFIG_MAX_ENV_TEMP)*)default_value = MAX_ENV_TEMP;
	    break;
	case CS_TYPE::CONFIG_SCAN_DURATION:
	    *(TYPIFY(CONFIG_SCAN_DURATION)*)default_value = SCAN_DURATION;
	    break;
	case CS_TYPE::CONFIG_SCAN_SEND_DELAY:
	    *(TYPIFY(CONFIG_SCAN_SEND_DELAY)*)default_value = SCAN_SEND_DELAY;
	    break;
	case CS_TYPE::CONFIG_SCAN_BREAK_DURATION:
	    *(TYPIFY(CONFIG_SCAN_BREAK_DURATION)*)default_value = SCAN_BREAK_DURATION;
	    break;
	case CS_TYPE::CONFIG_BOOT_DELAY:
	    *(TYPIFY(CONFIG_BOOT_DELAY)*)default_value = CONFIG_BOOT_DELAY_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_MAX_CHIP_TEMP:
	    *(TYPIFY(CONFIG_MAX_CHIP_TEMP)*)default_value = MAX_CHIP_TEMP;
	    break;
	case CS_TYPE::CONFIG_SCAN_FILTER:
	    *(TYPIFY(CONFIG_SCAN_FILTER)*)default_value = SCAN_FILTER;
	    break;
	case CS_TYPE::CONFIG_SCAN_FILTER_SEND_FRACTION:
	    *(TYPIFY(CONFIG_SCAN_FILTER_SEND_FRACTION)*)default_value = SCAN_FILTER_SEND_FRACTION;
	    break;
	case CS_TYPE::CONFIG_CROWNSTONE_ID:
	    *(TYPIFY(CONFIG_CROWNSTONE_ID)*)default_value = CONFIG_CROWNSTONE_ID_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_KEY_ADMIN:
	    break;
	case CS_TYPE::CONFIG_KEY_MEMBER:
	    break;
	case CS_TYPE::CONFIG_KEY_GUEST:
	    break;
	case CS_TYPE::CONFIG_SCAN_INTERVAL:
	    *(TYPIFY(CONFIG_SCAN_INTERVAL)*)default_value = SCAN_INTERVAL;
	    break;
	case CS_TYPE::CONFIG_SCAN_WINDOW:
	    *(TYPIFY(CONFIG_SCAN_WINDOW)*)default_value = SCAN_WINDOW;
	    break;
	case CS_TYPE::CONFIG_RELAY_HIGH_DURATION:
	    *(TYPIFY(CONFIG_RELAY_HIGH_DURATION)*)default_value = RELAY_HIGH_DURATION;
	    break;
	case CS_TYPE::CONFIG_LOW_TX_POWER:
	    *(TYPIFY(CONFIG_LOW_TX_POWER)*)default_value = CONFIG_LOW_TX_POWER_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_VOLTAGE_MULTIPLIER:
	    *(TYPIFY(CONFIG_VOLTAGE_MULTIPLIER)*)default_value = CONFIG_VOLTAGE_MULTIPLIER_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_CURRENT_MULTIPLIER:
	    *(TYPIFY(CONFIG_CURRENT_MULTIPLIER)*)default_value = CONFIG_CURRENT_MULTIPLIER_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_VOLTAGE_ZERO:
	    *(TYPIFY(CONFIG_VOLTAGE_ZERO)*)default_value = CONFIG_VOLTAGE_ZERO_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_CURRENT_ZERO:
	    *(TYPIFY(CONFIG_CURRENT_ZERO)*)default_value = CONFIG_CURRENT_ZERO_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_POWER_ZERO:
	    *(TYPIFY(CONFIG_POWER_ZERO)*)default_value = CONFIG_POWER_ZERO_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_MESH_ACCESS_ADDRESS:
	    *(TYPIFY(CONFIG_MESH_ACCESS_ADDRESS)*)default_value = MESH_ACCESS_ADDRESS;
	    break;
	case CS_TYPE::CONFIG_PWM_PERIOD:
	    *(TYPIFY(CONFIG_PWM_PERIOD)*)default_value = PWM_PERIOD;
	    break;
	case CS_TYPE::CONFIG_SOFT_FUSE_CURRENT_THRESHOLD:
	    *(TYPIFY(CONFIG_SOFT_FUSE_CURRENT_THRESHOLD)*)default_value = CURRENT_USAGE_THRESHOLD;
	    break;
	case CS_TYPE::CONFIG_SOFT_FUSE_CURRENT_THRESHOLD_PWM:
	    *(TYPIFY(CONFIG_SOFT_FUSE_CURRENT_THRESHOLD_PWM)*)default_value = CURRENT_USAGE_THRESHOLD_PWM;
	    break;
	case CS_TYPE::CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_UP:
	    *(TYPIFY(CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_UP)*)default_value = CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_UP_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_DOWN:
	    *(TYPIFY(CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_DOWN)*)default_value = CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_DOWN_DEFAULT;
	    break;
	case CS_TYPE::CONFIG_SWITCHCRAFT_THRESHOLD:
	    *(TYPIFY(CONFIG_SWITCHCRAFT_THRESHOLD)*)default_value = SWITCHCRAFT_THRESHOLD;
	    break;
	case CS_TYPE::CONFIG_MESH_CHANNEL:
	    *(TYPIFY(CONFIG_MESH_CHANNEL)*)default_value = MESH_CHANNEL;
	    break;
	case CS_TYPE::CONFIG_UART_ENABLED:
	    *(TYPIFY(CONFIG_UART_ENABLED)*)default_value = UART_ENABLED;
	    break;
	case CS_TYPE::STATE_RESET_COUNTER:
	    *(TYPIFY(STATE_RESET_COUNTER)*)default_value = STATE_RESET_COUNTER_DEFAULT;
	    break;
	case CS_TYPE::STATE_SWITCH_STATE:
	    *(TYPIFY(STATE_SWITCH_STATE)*)default_value = STATE_SWITCH_STATE_DEFAULT;
	    break;
	case CS_TYPE::STATE_ACCUMULATED_ENERGY:
	    *(TYPIFY(STATE_ACCUMULATED_ENERGY)*)default_value = STATE_ACCUMULATED_ENERGY_DEFAULT;
	    break;
	case CS_TYPE::STATE_POWER_USAGE:
	    *(TYPIFY(STATE_POWER_USAGE)*)default_value = STATE_POWER_USAGE_DEFAULT;
	    break;
	case CS_TYPE::STATE_TRACKED_DEVICES:
	    *(TYPIFY(STATE_TRACKED_DEVICES)*)default_value = STATE_TRACKED_DEVICES_DEFAULT;
	    break;
	case CS_TYPE::STATE_SCHEDULE:
	    *(TYPIFY(STATE_SCHEDULE)*)default_value = STATE_SCHEDULE_DEFAULT;
	    break;
	case CS_TYPE::STATE_OPERATION_MODE:
	    *(TYPIFY(STATE_OPERATION_MODE)*)default_value = STATE_OPERATION_MODE_DEFAULT;
	    break;
	case CS_TYPE::STATE_TEMPERATURE:
	    *(TYPIFY(STATE_TEMPERATURE)*)default_value = STATE_TEMPERATURE_DEFAULT;
	    break;
	case CS_TYPE::STATE_TIME:
	    *(TYPIFY(STATE_TIME)*)default_value = STATE_TIME_DEFAULT;
	    break;
	case CS_TYPE::STATE_FACTORY_RESET:
	    *(TYPIFY(STATE_FACTORY_RESET)*)default_value = STATE_FACTORY_RESET_DEFAULT;
	    break;
	case CS_TYPE::STATE_LEARNED_SWITCHES:
	    *(TYPIFY(STATE_LEARNED_SWITCHES)*)default_value = STATE_LEARNED_SWITCHES_DEFAULT;
	    break;
	case CS_TYPE::STATE_ERRORS:
	    *(TYPIFY(STATE_ERRORS)*)default_value = STATE_ERRORS_DEFAULT;
	    break;
	case CS_TYPE::STATE_ERROR_OVER_CURRENT:
	    *(TYPIFY(STATE_ERROR_OVER_CURRENT)*)default_value = STATE_ERROR_OVER_CURRENT_DEFAULT;
	    break;
	case CS_TYPE::STATE_ERROR_OVER_CURRENT_PWM:
	    *(TYPIFY(STATE_ERROR_OVER_CURRENT_PWM)*)default_value = STATE_ERROR_OVER_CURRENT_PWM_DEFAULT;
	    break;
	case CS_TYPE::STATE_ERROR_CHIP_TEMP:
	    *(TYPIFY(STATE_ERROR_CHIP_TEMP)*)default_value = STATE_ERROR_CHIP_TEMP_DEFAULT;
	    break;
	case CS_TYPE::STATE_ERROR_PWM_TEMP:
	    *(TYPIFY(STATE_ERROR_PWM_TEMP)*)default_value = STATE_ERROR_PWM_TEMP_DEFAULT;
	    break;
	case CS_TYPE::STATE_IGNORE_BITMASK:
	    *(TYPIFY(STATE_IGNORE_BITMASK)*)default_value = STATE_IGNORE_BITMASK_DEFAULT;
	    break;
	case CS_TYPE::STATE_IGNORE_ALL:
	    *(TYPIFY(STATE_IGNORE_ALL)*)default_value = STATE_IGNORE_ALL_DEFAULT;
	    break;
	case CS_TYPE::STATE_IGNORE_LOCATION:
	    *(TYPIFY(STATE_IGNORE_LOCATION)*)default_value = STATE_IGNORE_LOCATION_DEFAULT;
	    break;
	case CS_TYPE::STATE_ERROR_DIMMER_ON_FAILURE:
	    *(TYPIFY(STATE_ERROR_DIMMER_ON_FAILURE)*)default_value = STATE_ERROR_DIMMER_ON_FAILURE_DEFAULT;
	    break;
	case CS_TYPE::STATE_ERROR_DIMMER_OFF_FAILURE:
	    *(TYPIFY(STATE_ERROR_DIMMER_OFF_FAILURE)*)default_value = STATE_ERROR_DIMMER_OFF_FAILURE_DEFAULT;
	    break;
	default:
	    LOGw("Unknown default for %i", configurationType);
	    break;

    }
}
