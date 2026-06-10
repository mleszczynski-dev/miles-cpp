#pragma once

#include <filesystem>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

inline std::ostream& operator<<(std::ostream& out, const std::filesystem::path& path)
{
    return out << path.u8string();
}

template <>
struct fmt::formatter<std::filesystem::path> : ostream_formatter {};
