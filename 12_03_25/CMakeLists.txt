cmake_minimum_required(VERSION 3.10) # Specifies the minimum required CMake version

project(webRequest CXX) # Defines the project name and language (C++ in this case)

set(CMAKE_CXX_STANDARD 17) # Sets the C++ standard to use (e.g., C++17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE) # Ensures the specified C++ standard is enforced
find_package(OpenSSL REQUIRED)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG c492b4fed1fd7288eacec6fe8d89e37df78d373a) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)


add_executable(main main.cpp)
target_link_libraries(main PRIVATE cpr::cpr crypto ssl)
