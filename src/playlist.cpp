#include "playlist.hpp"

Playlist::Playlist() : name("") {}

Playlist::Playlist(const std::string& name) : name(name) {}

Playlist::~Playlist() {}

void Playlist::addTrack(const AudioTrack& track) {
    tracks.push(track);
}

AudioTrack& Playlist::getTrack(int index) {
    return tracks[index];
}


int Playlist::getNumTracks() const {
    return tracks.getSize();
}

std::string Playlist::getName() const {
    return name;
}

