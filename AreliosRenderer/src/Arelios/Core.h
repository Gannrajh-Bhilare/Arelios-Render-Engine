#pragma once

#ifdef AS_PLATFORM_WINDOWS
	#ifdef AS_BUILD_DLL
		#define ARELIOS_API __declspec(dllexport)
	#else
		#define ARELIOS_API __declspec(dllimport)
	#endif
#else
	#error Platform Not Supported!
#endif

#define Bit(x) (1 << x)