#include "audiolibrary.h"
#include <fstream>
#include <sstream>
#include <iostream>

/*
    audioLibrary.cpp
    Authors: M00851681,
    Created: 
    Updated: 
*/


void AudioLibrary::addTrack(const AudioTrack& track) {
    std::string audioName = track.getAudioName();
    tracks[audioName] = track;
}

void AudioLibrary::userAddTrack() {
    std::string authorName, audioName, albumName, genre, duration,
                datePublished, playlist;

    std::cout << "Please insert track details below:" << std::endl;
    std::cout << "Author Name: ";
    std::getline(std::cin, authorName);
    std::cout << "Audio Name: ";
    std::getline(std::cin, audioName);
    std::cout << "Album Name: ";
    std::getline(std::cin, albumName);
    std::cout << "Genre: ";
    std::getline(std::cin, genre);
    std::cout << "Duration: ";
    std::getline(std::cin, duration);
    std::cout << "Date Published: ";
    std::getline(std::cin, datePublished);
    std::cout << "Playlist: ";
    std::getline(std::cin, playlist);

    AudioTrack track(authorName, audioName, albumName, genre, duration,
                     datePublished, playlist);
    addTrack(track);

    std::cout << "Audio track added successfully!" << std::endl;
}