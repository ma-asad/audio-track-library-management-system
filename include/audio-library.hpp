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
  // tracksTable uses audio name as key
  HashTable<std::string, AudioTrack> tracksTable;
  HashTable<std::string, AudioTrack> artistTable;
  HashTable<std::string, AudioTrack> albumNameTable;
  HashTable<std::string, AudioTrack> genreTable;
  HashTable<std::string, AudioTrack> playlistTable;

  // Quicksort helper function
  void quickSort(std::pair<std::string, AudioTrack>* items, int low, int high);

  // Partition function for Quicksort
  int partition(std::pair<std::string, AudioTrack>* items, int low, int high);

  // Helper function to convert a string to lowercase
  std::string toLowercase(const std::string& str);

 public:
  AudioLibrary();

  /**
   * @brief Adds an audio track to the hash table.
   *
   * This function takes an AudioTrack object as a parameter and adds it to the
   * hash table. The hash table is used to store and manage audio tracks in the
   * library.
   *
   * @param track The audio track to be added.
   */
  void addTrackToHashTables(const AudioTrack& track);

  /**
   * @brief Loads data from a file into the audio library.
   *
   * This function takes a filename as input and loads the data from the file
   * into the audio library. The file should be in a specific format that is
   * compatible with the audio library.
   *
   * @param filename The name of the file to load data from.
   */
  void loadData(const std::string& filename);

  /**
   * Adds a track to the audio library from a CSV file.
   * The CSV file should contain the necessary information for the track, such
   * as the title, artist, duration, etc. This function reads the CSV file,
   * parses the data, and adds the track to the audio library. If the CSV file
   * is not found or the data is invalid, an error message is displayed.
   */
  void addTrackFromCSV();

  /**
   * @brief Checks if a file exists.
   *
   * This function takes a filename as input and checks if the file exists in
   * the file system.
   *
   * @param filename The name of the file to check.
   * @return true if the file exists, false otherwise.
   */
  bool checkFileExistence(const std::string& filename);

  /**
   * @brief Deletes a track from the audio library.
   *
   * This function takes the name of the audio track as a parameter and deletes
   * it from the audio library.
   *
   * @param audioName The name of the audio track to be deleted.
   * @return True if the track was successfully deleted, false otherwise.
   */
  bool deleteTrack(const std::string& audioName);

  /**
   * Lists all the audio tracks in the library.
   */
  void listAudio();

  AudioTrack* findTrackByName(const std::string& track) {
    return tracksTable.findTrack(track);
  };

  AudioTrack* findTrackByArtist(const std::string& artist) {
    return artistTable.findTrack(artist);
  }

  AudioTrack* findTrackByAlbum(const std::string& album) {
    return albumNameTable.findTrack(album);
  }

  AudioTrack* findTrackByGenre(const std::string& genre) {
    return genreTable.findTrack(genre);
  }

  AudioTrack* findTrackByPlaylist(const std::string& playlist) {
    return playlistTable.findTrack(playlist);
  }

  void createPlaylist();
  void addTrackToPlaylist();
  void removeTrackFromPlaylist();
  void deletePlaylist();
  void viewPlaylist();
};

#endif