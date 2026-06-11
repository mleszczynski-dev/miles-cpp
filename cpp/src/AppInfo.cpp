#include "AppInfo.h"

#include <nlohmann/json.hpp>
#include <spdlog/version.h>
#include <format>

const std::string AppInfo::nlohmann_json_version = std::format("{}.{}.{}", NLOHMANN_JSON_VERSION_MAJOR, NLOHMANN_JSON_VERSION_MINOR, NLOHMANN_JSON_VERSION_PATCH);
const std::string AppInfo::spdlog_version = std::format("{}.{}.{}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);

const std::string AppInfo::compiler_name =
#if defined(__clang__)
    "clang";
#elif defined(__GNUC__) || defined(__GNUG__)
    "gcc";
#elif defined(_MSC_VER)
    "msvc";
#else
#error "Unknown compiler"
#endif

const std::string AppInfo::compiler_version =
#if defined(__clang__)
    std::format("{}.{}.{}", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined(__GNUC__) || defined(__GNUG__)
    std::format("{}.{}.{}", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif defined(_MSC_VER)
    std::format("{}.{}.{}", _MSC_VER / 100, _MSC_VER % 100, _MSC_FULL_VER % 100000);
#else
#error "Unknown compiler"
#endif

const std::string AppInfo::build_type =
#if defined(_DEBUG) || !defined(NDEBUG)
    "debug";
#else
    "release";
#endif

const std::string AppInfo::cpu_architecture =
#if defined(__x86_64__) || defined(__amd64__) || defined(_M_X64)
    "x64";
#elif defined(__i386__) || defined(_M_IX86)
    "x86";
#elif defined(__aarch64__) || defined(_M_ARM64)
    "ARM64";
#elif defined(__arm__) || defined(_M_ARM)
    "ARM32";
#else
#error "Unknown cpu architecture"
#endif

const nlohmann::ordered_json& AppInfo::toJson()
{
    static nlohmann::ordered_json app_info_json = []
    {
        nlohmann::ordered_json app_info;
        app_info["compiler name"] = compiler_name;
        app_info["compiler version"] = compiler_version;
        app_info["cpu architecture"] = cpu_architecture;
        app_info["build type"] = build_type;
        app_info["nlohmann/json version"] = nlohmann_json_version;
        app_info["spdlog version"] = spdlog_version;
        return app_info;
    }();

    return app_info_json;
}

const std::string& AppInfo::toString()
{
    static std::string str = toJson().dump(4);

    return str;
}
