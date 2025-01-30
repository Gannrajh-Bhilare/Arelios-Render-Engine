#pragma once

#ifdef AS_PLATFORM_WINDOWS
#if DLL_BUILD
	#ifdef AS_BUILD_DLL
		#define   __declspec(dllexport)
	#else
		#define   __declspec(dllimport)
	#endif
#endif
#else
	#error Platform Not Supported!
#endif

#ifdef AS_ENABLE_ASSERTS
	#define AS_ASSERT(x, ...) { if(!(x)) {__debugbreak();}}
#endif


#define Bit(x) (1 << x)