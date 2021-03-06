/**
 * Author: Crownstone Team
 * Date: 21 Sep., 2013
 * License: LGPLv3+, Apache License 2.0, and/or MIT (triple-licensed)
 */
#pragma once

#ifdef	NDEBUG

//! for release version ignore asserts
#define assert(expr, message) \
	if (!(expr)) { \
		LOGe("%s", message); \
	}

#else

#define assert(expr, message) \
	if (!(expr)) { \
		LOGe("%s", message); \
		exit(1); \
	}

#endif

#define NRF51_CRASH(x) __asm("BKPT"); \
	while (1) {}
