#ifndef MUSIC_SERVICE_H
#define MUSIC_SERVICE_H

#include <string>

class MusicService {
public:
    virtual bool authenticate(const std::string &token) = 0;
    virtual std::string search(const std::string &query) = 0;
    virtual ~MusicService() = default;
};

#endif
