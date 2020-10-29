#pragma once

#include <memory>

#include "spdlog/spdlog.h"

namespace Willow
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
    private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
} // namespace Willow


// Core Log Macros
#define WI_CORE_TRACE(...)  ::Willow::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WI_CORE_INFO(...)   ::Willow::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WI_CORE_WARN(...)   ::Willow::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WI_CORE_ERROR(...)  ::Willow::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WI_CORE_FATAL(...)  ::Willow::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client Log Macros
#define WI_TRACE(...)  ::Willow::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WI_INFO(...)   ::Willow::Log::GetClientLogger()->info(__VA_ARGS__)
#define WI_WARN(...)   ::Willow::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WI_ERROR(...)  ::Willow::Log::GetClientLogger()->error(__VA_ARGS__)
#define WI_FATAL(...)  ::Willow::Log::GetClientLogger()->fatal(__VA_ARGS__)

