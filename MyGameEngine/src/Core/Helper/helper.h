#pragma once
#include "pch.h"
#include "Core/Log.h"
namespace Immortal
{
	IMMORTAL_API void error_callback(int error, const char* description)
	{
		IMMORTAL_CORE_ERROR(description);
	}
}