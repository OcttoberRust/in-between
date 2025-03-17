#include "SpotifyService.h"
#include <iostream>

bool SpotifyService::authenticate(const std::string &token) {
    std::cout << "Authenticating with token: " << token << std::endl;
    return true;
}

std::string SpotifyService::search(const std::string &query) {
    std::cout << "Searching Spotify for: " << query << std::endl;
    return "{\"result\": \"example\"}";
}
