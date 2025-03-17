#ifndef MUSIC_SERVICE_H
#define MUSIC_SERVICE_H

#include <string>

class MusicService {
public:
    virtual std::string authenticate();
    virtual std::string search(const std::string &query) = 0;
    virtual ~MusicService() = default;
};

#endif
