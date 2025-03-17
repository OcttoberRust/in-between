cmake_minimum_required(VERSION 3.10)
project(in-between)

set(CMAKE_CXX_STANDARD 20)

# Include source files
add_executable(in-between
    src/main.cpp
    src/SpotifyService.cpp
    src/AmazonMusicService.cpp
)
