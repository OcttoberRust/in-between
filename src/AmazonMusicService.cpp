#include "AmazonMusicService.h"
#include <iostream>

std::string AmazonMusicService::authenticate() {
    return "{}";
}

std::string AmazonMusicService::search(const std::string &query) {
    std::cout << "Searching Amazon Music for: " << query << std::endl;
    return "{\"result\": \"example\"}";
}
