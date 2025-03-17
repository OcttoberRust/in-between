#include "SpotifyService.h"
#include <iostream>
#include <cpr/cpr.h>
#include <stdexcept>
#include <nlohmann/json.hpp>

SpotifyService::SpotifyService(const std::string& clientId, const std::string& clientSecret) 
    : clientId(clientId), clientSecret(clientSecret), accessToken("") {}

std::string SpotifyService::authenticate() {
    if (!accessToken.empty()) {
        return accessToken;
    }

    auto response = cpr::Post(
        cpr::Url{"https://accounts.spotify.com/api/token"},
        cpr::Header{{"Content-Type", "application/x-www-form-urlencoded"}},
        cpr::Payload{
            {"grant_type", "client_credentials"},
            {"client_id", clientId},
            {"client_secret", clientSecret}
        }
    );

    if (response.status_code == 200) {
        auto json = nlohmann::json::parse(response.text);
        accessToken = json["access_token"];
        return accessToken;
    } else {
        throw std::runtime_error("Failed to authenticate with Spotify: " + response.text);
    }
}

std::string SpotifyService::search(const std::string &query) {
    std::string token = authenticate();
    
    auto response = cpr::Get(
        cpr::Url{"https://api.spotify.com/v1/search"},
        cpr::Header{
            {"Authorization", "Bearer " + token}
        },
        cpr::Parameters{
            {"q", query},
            {"type", "artist"},
            {"limit", "5"}
        }
    );
    
    if (response.status_code == 200) {
        return response.text;
    } else {
        throw std::runtime_error("Spotify search failed: " + response.text);
    }
}
