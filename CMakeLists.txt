cmake_minimum_required (VERSION 3.21.1)

project("miles-cpp" LANGUAGES CXX)

message(STATUS "C++ compiler path: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")

#set(CMAKE_OBJECT_PATH_MAX 300)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

#set(ASIO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/asio/asio")
#set(GOOGLE_MOCK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/googletest/googlemock")
#set(GOOGLE_TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/googletest/googletest")
#set(NLOHMANN_JSON_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/json")
#set(SPDLOG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/spdlog")

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_compile_definitions(
    SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE   
)

if (WIN32)
    add_compile_definitions(
        _WIN32_WINNT=0x0601
        UNICODE
        _UNICODE
        WIN32_LEAN_AND_MEAN
        NOMINMAX
        SPDLOG_WCHAR_TO_UTF8_SUPPORT
    )
endif()

add_library(${PROJECT_NAME} STATIC
    "include/AppInfo.h"
    "include/JsonFile.h"
    "include/LoggerFilesystemPath.h"
    "include/LoggerInitializer.h"
    "src/AppInfo.cpp"
    "src/JsonFile.cpp"
    "src/LoggerInitializer.cpp"
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    #${ASIO_DIR}/include
    #${NLOHMANN_JSON_DIR}/include
    #${SPDLOG_DIR}/include
)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)

