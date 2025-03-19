#include "SpotifyService.h"
#include "AmazonMusicService.h"
#include <iostream>
#include <cstdlib>
#include <cpr/cpr.h>
#include <fstream>
#include <string>
#include <map>
#include <filesystem>

std::map<std::string, std::string> loadEnvFile(const std::string& filename) {
   std::map<std::string, std::string> envVars;
   std::ifstream file(filename);
   std::string line;
          
   while (std::getline(file, line)) {
       size_t equalsPos = line.find('=');

       if(equalsPos != std::string::npos) {
	   std::string key = line.substr(0, equalsPos);
	   std::string value = line.substr(equalsPos + 1);
	   envVars[key] = value;
	   setenv(key.c_str(), value.c_str(), 1);
	  
	   std::cout << "Loaded: " << key << " = " << value << "\n";
       }
   }
   return envVars;
}

int main() {

    loadEnvFile("../.env");
    
    const char* clientIdCStr = std::getenv("SPOTIFY_CLIENT_ID");
    const char* clientSecretCStr = std::getenv("SPOTIFY_CLIENT_SECRET");

    if (!clientIdCStr || !clientSecretCStr) {
        std::cerr << "Missing SPOTIFY_CLIENT_ID or SPOTIFY_CLIENT_SECRET environment variables!\n";
        return 1;
    }

    std::string clientId(clientIdCStr);
    std::string clientSecret(clientSecretCStr);

    try {
        SpotifyService spotify(clientId, clientSecret);

        //std::string results = spotify.search("Radiohead");
        //std::cout << "Search Results:\n" << results << "\n";
        
        std::string userPlaylists = spotify.getCurrentUsersPlaylists();
        std::cout << "User playlists:\n" << userPlaylists << "\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
