#ifndef AUDIOLIBRARY_H
#define AUDIOLIBRARY_H

#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <vector>

#include "audio-track.hpp"
#include "hash-table.hpp"

/*
    audiolibrary.hpp
    Created:
    Updated:
*/

/**
 * @class AudioLibrary
 * @brief Represents a library of audio tracks.
 * The AudioLibrary class provides functionality to manage a collection of audio
 * tracks.
 */

class AudioLibrary {
 private:
  HashTable<std::string, AudioTrack> tracks;

  // Quicksort helper function
  void quickSort(std::pair<std::string, AudioTrack> *items, int low, int high);

  // Partition function for Quicksort
  int partition(std::pair<std::string, AudioTrack> *items, int low, int high);

  // Helper function to convert a string to lowercase
  std::string toLowercase(const std::string &str);

 public:
  AudioLibrary();

  void addTrackToHashTable(const AudioTrack &track);
  void loadData(const std::string &filename);
  void addTrackFromCSV();
  bool checkFileExistence(const std::string &filename);
  void addTrackManually();
  bool deleteTrack(const std::string &audioName);
  void listAudio();

  void createPlaylist();
  void addTrackToPlaylist();
  void removeTrackFromPlaylist();
  void deletePlaylist();
  void viewPlaylist();
};

#endif