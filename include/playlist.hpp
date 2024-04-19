#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include "audio-track.hpp"
#include "dynamic-array.hpp"

class Playlist {
private:
    std::string name;
    vectorDynamicArray<AudioTrack> tracks;

public:
    Playlist();
    Playlist(const std::string& name);
    ~Playlist();

    void addTrack(const AudioTrack& track);
    AudioTrack& getTrack(int index);
    int getNumTracks() const;
    std::string getName() const;
};

#endif