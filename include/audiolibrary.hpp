#ifndef AUDIOLIBRARY_H
#define AUDIOLIBRARY_H


/*
    audiolibrary.hpp
    Created: 
    Updated: 
*/

#include <string>
#include "audioTrack.hpp"
#include "hashtable.hpp"

/**
 * @class AudioLibrary
 * @brief Represents a library of audio tracks.
 * The AudioLibrary class provides functionality to manage a collection of audio tracks.
 */
class AudioLibrary {
private:
    HashTable<std::string, AudioTrack> tracks;

public:
    AudioLibrary() {}
    void addTrackToHashTable(const AudioTrack& track);
    void loadData(const std::string& filename);
    void addTrackFromCSV();
    bool checkFileExistence(const std::string& filename);
    void addTrackManually();
    bool deleteTrack(const std::string& audioName);
};

#endif