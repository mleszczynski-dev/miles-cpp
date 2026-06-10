project("miles-cpp-lib" LANGUAGES CXX)

find_package(spdlog REQUIRED)
find_package(nlohmann_json REQUIRED)

add_library(${PROJECT_NAME} STATIC
    "include/AppInfo.h"
    "src/AppInfo.cpp"
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    spdlog::spdlog
    nlohmann_json::nlohmann_json
)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)

