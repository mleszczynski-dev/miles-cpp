project("miles-cpp-lib" LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC
    #"include/AppInfo.h"
    #"include/JsonFile.h"
    #"include/LoggerFilesystemPath.h"
    #"include/LoggerInitializer.h"
    #"src/AppInfo.cpp"
    #"src/JsonFile.cpp"
    #"src/LoggerInitializer.cpp"
    "include/Dummy.h"
    "src/Dummy.cpp"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE
)

target_include_directories(${PROJECT_NAME} PUBLIC
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

