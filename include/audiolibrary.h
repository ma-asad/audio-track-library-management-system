#ifndef AUDIOLIBRARY_H
#define AUDIOLIBRARY_H


/*
    audiolibrary.h
    Authors: M00851681,
    Created: 
    Updated: 
*/

#include <string>
#include "audioTrack.h"
#include <unordered_map>

/**
 * @class AudioLibrary
 * @brief Represents a library of audio tracks.
 * The AudioLibrary class provides functionality to manage a collection of audio tracks.
 */
class AudioLibrary {
private:
    std::unordered_map<std::string, AudioTrack> tracks;

public:
    void addTrack(const AudioTrack& track);
    void loadData(const std::string& filename);
    void userAddTrack();
};

#endif