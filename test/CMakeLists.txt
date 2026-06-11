project("miles-cpp-test" LANGUAGES CXX)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    "src/main.cpp"
    "src/test.cpp"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    miles-cpp-lib
    GTest::gtest
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
