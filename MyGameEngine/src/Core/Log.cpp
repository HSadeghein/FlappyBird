#include "pch.h"
#include "Log.h"

namespace Immortal
{
	std::shared_ptr<spdlog::logger> Log::ms_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::ms_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		ms_CoreLogger = spdlog::stderr_color_mt("Immortal Engine", spdlog::color_mode::automatic);
		ms_CoreLogger->set_level(spdlog::level::trace);
		ms_ClientLogger = spdlog::stderr_color_mt("Flappy Bird", spdlog::color_mode::automatic);
		ms_ClientLogger->set_level(spdlog::level::trace);
	}
}