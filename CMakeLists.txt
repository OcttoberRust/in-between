cmake_minimum_required(VERSION 3.15)
project(in-between)

set(CMAKE_CXX_STANDARD 20)

# Find packages via Conan
find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

# Add your executable and all source files clearly:
add_executable(in-between
    src/main.cpp
    src/SpotifyService.cpp
)

# Link your dependencies explicitly:
target_link_libraries(in-between PRIVATE cpr::cpr nlohmann_json::nlohmann_json)

