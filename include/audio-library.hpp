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
 * @enum SearchType
 * @brief Enum class for defining the different types of searches that can be
 * performed in the audio library.
 *
 * This enum class is used to specify the type of search to be performed when
 * looking for audio tracks. The search can be performed based on the track
 * name, artist name, album name, genre, or playlist.
 */
enum class SearchType { Track, Artist, Album, Genre, Playlist };

/**
 * @class AudioLibrary
 * @brief Represents a library of audio tracks.
 *
 * The AudioLibrary class provides functionality to manage and manipulate a
 * collection of audio tracks. It includes methods to add, delete, and search
 * for tracks based on various criteria such as track name, artist, album,
 * genre, and playlist. The class also supports loading data from a file,
 * creating playlists, and performing sorting operations on the tracks.
 */
class AudioLibrary {
 private:
  HashTable<std::string, AudioTrack> tracksTable;
  HashTable<std::string, AudioTrack> artistTable;
  HashTable<std::string, AudioTrack> albumNameTable;
  HashTable<std::string, AudioTrack> genreTable;
  HashTable<std::string, AudioTrack> playlistTable;

  /**
   * Sorts an array of AudioTrack objects using the QuickSort algorithm.
   *
   * @param items The array of AudioTrack objects to be sorted.
   * @param low The starting index of the subarray to be sorted.
   * @param high The ending index of the subarray to be sorted.
   */
  void quickSort(std::pair<std::string, AudioTrack>* items, int low, int high);

  /**
   * Partitions the given array of audio tracks based on the audio name.
   * Uses the last element as the pivot and rearranges the elements such that
   * all elements smaller than or equal to the pivot are placed before it,
   * and all elements greater than the pivot are placed after it.
   *
   * @param items The array of audio tracks to be partitioned.
   * @param low The starting index of the subarray to be partitioned.
   * @param high The ending index of the subarray to be partitioned.
   * @return The index of the pivot element after partitioning.
   */
  int partition(std::pair<std::string, AudioTrack>* items, int low, int high);

  /**
   * Converts a given string to lowercase.
   *
   * @param str The string to be converted to lowercase.
   * @return The lowercase version of the input string.
   */
  std::string toLowercase(const std::string& str);

 public:
  /**
   * @brief Constructs an instance of the AudioLibrary class.
   *
   * This constructor initializes the tracksTable, artistTable, albumNameTable,
   * genreTable, and playlistTable data members of the AudioLibrary class.
   */
  AudioLibrary();

  /**
   * @brief Destructor for the AudioLibrary class.
   *
   * This destructor is responsible for cleaning up any resources
   * allocated by the AudioLibrary class.
   */
  ~AudioLibrary();

  /**
   * Adds an audio track to the hash tables in the audio library.
   *
   * @param track The audio track to be added.
   * @return True if the track was successfully added to all hash tables, false
   * otherwise.
   */
  bool addTrackToHashTables(const AudioTrack& track);

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
  void deleteAudio();

  /**
   * @brief Deletes an audio track from the library.
   *
   * This function deletes an audio track from the library by removing it from
   * all relevant hash tables.
   *
   * @param audioName The name of the audio track to be deleted.
   * @return True if the audio track was successfully deleted, false otherwise.
   */
  bool deleteTrackFromTable(const std::string& audioName);

  /**
   * Lists all the audio tracks in the library.
   */
  void listAudio();

  void createPlaylist();
  void addTrackToPlaylist();
  void removeTrackFromPlaylist();
  void deletePlaylist();
  void viewPlaylist();

  /**
   * Finds an AudioTrack by its name.
   *
   * @param track The name of the track to find.
   * @return A pointer to the found AudioTrack, or nullptr if not found.
   */
  AudioTrack* findTrackByName(const std::string& track) {
    return tracksTable.findTrack(track);
  };

  /**
   * Finds an audio track by artist.
   *
   * @param artist The name of the artist to search for.
   * @return A pointer to the found AudioTrack object, or nullptr if not found.
   */
  AudioTrack* findTrackByArtist(const std::string& artist) {
    return artistTable.findTrack(artist);
  }

  /**
   * Finds an audio track by album.
   *
   * @param album The name of the album to search for.
   * @return A pointer to the found AudioTrack object, or nullptr if not found.
   */
  AudioTrack* findTrackByAlbum(const std::string& album) {
    return albumNameTable.findTrack(album);
  }

  /**
   * Finds an audio track by genre.
   *
   * @param genre The genre of the audio track to find.
   * @return A pointer to the found AudioTrack object, or nullptr if not found.
   */
  AudioTrack* findTrackByGenre(const std::string& genre) {
    return genreTable.findTrack(genre);
  }

  /**
   * Finds an audio track by playlist.
   *
   * @param playlist The name of the playlist to search for.
   * @return A pointer to the AudioTrack object if found, nullptr otherwise.
   */
  AudioTrack* findTrackByPlaylist(const std::string& playlist) {
    return playlistTable.findTrack(playlist);
  }

  void searchTracks(const SearchType searchType,
                    const std::string& searchQuery);

  /**
   * Returns a constant reference to the tracks table.
   *
   * @return A constant reference to the tracks table.
   */
  const HashTable<std::string, AudioTrack>& getTracksTable() const {
    return tracksTable;
  }

  /**
   * Returns a constant reference to the artist table.
   *
   * @return A constant reference to the artist table.
   */
  const HashTable<std::string, AudioTrack>& getArtistTable() const {
    return artistTable;
  }

  /**
   * Returns a constant reference to the album name table.
   *
   * @return A constant reference to the album name table.
   */
  const HashTable<std::string, AudioTrack>& getAlbumNameTable() const {
    return albumNameTable;
  }

  /**
   * Returns a constant reference to the genre table.
   *
   * @return A constant reference to the genre table.
   */
  const HashTable<std::string, AudioTrack>& getGenreTable() const {
    return genreTable;
  }

  /**
   * Returns a constant reference to the playlist table.
   *
   * @return A constant reference to the playlist table.
   */
  const HashTable<std::string, AudioTrack>& getPlaylistTable() const {
    return playlistTable;
  }
};

#endif