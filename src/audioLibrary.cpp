#include "audiolibrary.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

/*
    audioLibrary.cpp
    Created: 
    Updated: 
*/


void AudioLibrary::addTrackToHashTable(const AudioTrack& track) {
    std::string audioName = track.getAudioName();
    tracks.insert(audioName, track);
}


void AudioLibrary::loadData(const std::string& filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string authorName, audioName, albumName, genre, 
                    duration, datePublished, playlist;

        if (std::getline(iss, authorName, ',') &&
            std::getline(iss, audioName, ',') &&
            std::getline(iss, albumName, ',') &&
            std::getline(iss, genre, ',') &&
            std::getline(iss, duration, ',') &&
            std::getline(iss, datePublished, ',') &&
            std::getline(iss, playlist)) {
            AudioTrack track(authorName, audioName, albumName, genre, duration,
                            datePublished, playlist);
            addTrackToHashTable(track);
        }
    }
    file.close();
}


void AudioLibrary::addTrackFromCSV() {
    std::string filename;
    bool validFile = false;

    while (!validFile) {
        std::cout << "Please enter the filename (csv format only): ";
        std::getline(std::cin, filename);

        // Check if the file has a .csv extension
        if (filename.size() >= 5 && filename.substr(filename.size() - 4) == ".csv") {
            if (checkFileExistence(filename)) {
                validFile = true;
            } else {
                std::cerr << "File does not exist: " << filename << std::endl;
            }
        } else {
            std::cerr << "Invalid file format. Please provide a CSV file." 
                      << std::endl;
        }
    }

    loadData(filename);
    std::cout << "Audio tracks added successfully from " << filename <<  "!" 
              << std::endl;
}


void AudioLibrary::addTrackManually() {
    std::string authorName, audioName, albumName, genre, duration,
                datePublished, playlist;

    std::cout << "Enter author name: ";
    std::getline(std::cin, authorName);

    std::cout << "Enter audio name: ";
    std::getline(std::cin, audioName);

    std::cout << "Enter album name: ";
    std::getline(std::cin, albumName);

    std::cout << "Enter genre: ";
    std::getline(std::cin, genre);

    std::cout << "Enter duration: ";
    std::getline(std::cin, duration);

    std::cout << "Enter date published: ";
    std::getline(std::cin, datePublished);

    std::cout << "Enter playlist: ";
    std::getline(std::cin, playlist);

    AudioTrack track(authorName, audioName, albumName, genre, duration,
                    datePublished, playlist);
    addTrackToHashTable(track);

    std::cout << "Audio track added successfully!" << std::endl;
}

bool AudioLibrary::checkFileExistence(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}


bool AudioLibrary:: deleteTrack(const std::string& audioName) {
    if (tracks.remove(audioName)) {
        std::cout << "Audio track '" << audioName << "' deleted successfully!" 
                  << std::endl;
        return true;
    } else {
        std::cout << "Audio track '" << audioName << "' not found." 
                  << std::endl;
        return false;
    }
}

