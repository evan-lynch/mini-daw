# Says the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.20)

# Says the name of the project and the programming languages it uses
project(mini_daw LANGUAGES CXX)

# Sets the C++ version to version 17 and makes it required to build this 
# project, so that the compiler will throw an error if something doesn't
# work on this specific version, such as libraries that don't support it
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetches the webview library from its Git repository, and makes it available
# for use in the project
include(FetchContent)
FetchContent_Declare(
    webview
    GIT_REPOSITORY https://github.com/webview/webview.git
    GIT_TAG 0.12.0
)
FetchContent_MakeAvailable(webview)

# Like a Makefile, says that an executable mini_daw will be made from the
# source file engine/main.cpp
add_executable(mini_daw engine/main.cpp)

# Links the webview library to the mini_daw executable
target_link_libraries(mini_daw PRIVATE webview::core)