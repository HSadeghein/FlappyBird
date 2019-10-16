#pragma once

#ifdef IMMORTAL_PLATFORM_WINDOWS
	#ifdef IMMORTAL_BUILD_DLL
		#define IMMORTAL_API __declspec(dllexport)
	#else
		#define IMMORTAL_API __declspec(dllimport)
	#endif
#else
	#error Immortal only supports Windows
#endif
