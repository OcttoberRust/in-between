#ifndef SPOTIFYSERVICE_H
#define SPOTIFYSERVICE_H

#include "MusicService.h"
#include <string>

class SpotifyService : public MusicService {
public:
	bool authenticate(const std::string &token) override;
	std::string search(const std::string &query) override;
};

#endif
