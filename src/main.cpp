#include "SpotifyService.h"
#include "AmazonMusicService.h"
#include <iostream>

int main() {
    SpotifyService spotify;
    AmazonMusicService amazonMusic;

    if (spotify.authenticate("spotify_token")) {
        std::cout << "Spotify search result: "
        << spotify.search("artist:Radiohead") << "\n";
    }

    if (amazonMusic.authenticate("amazon_token")) {
        std::cout << "Amazon Music search result: "
        << amazonMusic.search("artist:Radiohead") << "\n";
    }
    return 0;
}
