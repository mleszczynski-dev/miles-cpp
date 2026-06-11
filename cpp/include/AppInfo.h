#pragma once

#include <nlohmann/json.hpp>
#include <string>

class AppInfo
{
public:
    AppInfo() = delete;

    static const nlohmann::ordered_json& toJson();
    static const std::string& toString();

private:
    static const std::string compiler_name;
    static const std::string compiler_version;
    static const std::string build_type;
    static const std::string cpu_architecture;

    static const std::string nlohmann_json_version;
    static const std::string spdlog_version;
};

