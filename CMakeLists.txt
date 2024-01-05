cmake_minimum_required(VERSION 3.15)
project(caverun CXX)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED IMPORTED_TARGET glib-2.0>=2.78.3)
pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk4)

file (GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PkgConfig::GLIB PkgConfig::GTK)