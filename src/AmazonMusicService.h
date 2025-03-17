#ifndef AMAZONMUSICSERVICE_H
#define AMAZONMUSICSERVICE_H

#include "MusicService.h"
#include <string>

class AmazonMusicService : public MusicService {
public:
    bool authenticate(const std::string &token) override;
    std::string search(const std::string &query) override;
};

#endif
