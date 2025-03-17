#ifndef SPOTIFYSERVICE_H
#define SPOTIFYSERVICE_H

#include "MusicService.h"
#include <string>

class SpotifyService {
public:
    // Constructor with initialization list
    SpotifyService(const std::string& clientId, const std::string& clientSecret);

    std::string authenticate();
    std::string search(const std::string& query);
    std::string getPlaylist(const std::string& playlistId);

private:
    std::string clientId;
    std::string clientSecret;	
    std::string accessToken;
};

#endif
