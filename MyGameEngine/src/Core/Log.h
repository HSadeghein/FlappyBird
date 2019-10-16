#pragma once
#include <memory>
#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Immortal
{
	class IMMORTAL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return ms_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ms_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> ms_CoreLogger;
		static std::shared_ptr<spdlog::logger> ms_ClientLogger;
	};
}

//Core logs Macros
#define IMMORTAL_CORE_ERROR(...)	::Immortal::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IMMORTAL_CORE_WARN(...)		::Immortal::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IMMORTAL_CORE_TRACE(...)	::Immortal::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IMMORTAL_CORE_INFO(...)		::Immortal::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IMMORTAL_CORE_CRITICAL(...) ::Immortal::Log::GetCoreLogger()->critical(__VA_ARGS__)
//Client logs Macros
#define CLIENT_ERROR(...)		::Immortal::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_WARN(...)		::Immortal::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_TRACE(...)		::Immortal::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_INFO(...)		::Immortal::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_CRITICAL(...)	::Immortal::Log::GetClientLogger()->critical(__VA_ARGS__)