#include "audio-library.hpp"

/*
    audioLibrary.cpp
    Created:
    Updated:
*/

AudioLibrary::AudioLibrary() : tracks() {}

void AudioLibrary::addTrackToHashTable(const AudioTrack &track) {
  std::string audioName = track.getAudioName();
  tracks.insert(audioName, track);
}

void AudioLibrary::loadData(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Unfortunately failed to open file: " << filename << std::endl;
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string authorName, audioName, albumName, genre, duration,
        datePublished, playlist;

    if (std::getline(iss, authorName, ',') &&
        std::getline(iss, audioName, ',') &&
        std::getline(iss, albumName, ',') && std::getline(iss, genre, ',') &&
        std::getline(iss, duration, ',') &&
        std::getline(iss, datePublished, ',') && std::getline(iss, playlist)) {
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
    if (filename.size() >= 5 &&
        filename.substr(filename.size() - 4) == ".csv") {
      if (checkFileExistence(filename)) {
        validFile = true;
      } else {
        std::cerr << "This file does not exist!: " << filename << std::endl;
      }
    } else {
      std::cerr << "Invalid file format! Please only csv are allowed"
                << std::endl;
    }
  }

  loadData(filename);
  std::cout << "Audio tracks have been added successfully from " << filename
            << "!" << std::endl;
}

void AudioLibrary::addTrackManually() {
  std::string authorName, audioName, albumName, genre, duration, datePublished,
      playlist;

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

  std::cout << "The Audio tracks have been added successfully!" << std::endl;
}

bool AudioLibrary::checkFileExistence(const std::string &filename) {
  std::ifstream file(filename);
  return file.good();
}

bool AudioLibrary::deleteTrack(const std::string &audioName) {
  if (tracks.remove(audioName)) {
    std::cout << " The Audio track '" << audioName
              << "' has been deleted successfully!" << std::endl;
    return true;
  } else {
    std::cout << "The Audio track '" << audioName << "'was not found."
              << std::endl;
    return false;
  }
}

void AudioLibrary::listAudio() {
  std::pair<size_t, std::pair<std::string, AudioTrack> *> result =
      tracks.listItems();

  size_t counter = result.first;
  std::pair<std::string, AudioTrack> *items = result.second;
  
  int count = 0;

  // Quicksort algorithm to sort the audio tracks by name (A-Z)
  quickSort(items, 0, counter - 1);

  // Iterate over the sorted audio tracks and display their details
  for (size_t c = 0; c < counter; ++c) {
    const AudioTrack &track = items[c].second;
    std::cout << "Track number: " << count << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Author Name: " << track.getAuthorName() << std::endl;
    std::cout << "Audio Name: " << track.getAudioName() << std::endl;
    std::cout << "Album Name: " << track.getAlbumName() << std::endl;
    std::cout << "Genre: " << track.getGenre() << std::endl;
    std::cout << "Duration: " << track.getDuration() << std::endl;
    std::cout << "Date Published: " << track.getDatePublished() << std::endl;
    std::cout << "Playlist: " << track.getPlaylist() << std::endl;
    std::cout << "-----------------------------" << std::endl;

    ++count;
  }
}

// Quicksort helper function
void AudioLibrary::quickSort(std::pair<std::string, AudioTrack> *items, int low,
                             int high) {
  if (low < high) {
    int pivotIndex = partition(
        items, low, high);  // Partition the array and get the pivot index
    quickSort(items, low,
              pivotIndex - 1);  // Recursively sort the left subarray
    quickSort(items, pivotIndex + 1,
              high);  // Recursively sort the right subarray
  }
}

// Partition function for Quicksort
int AudioLibrary::partition(std::pair<std::string, AudioTrack> *items, int low,
                            int high) {
  std::string pivot =
      items[high]
          .first;   // Use the key (audio name) of the last element as the pivot
  int i = low - 1;  // Index of the smaller element

  // Iterate over the subarray and partition it around the pivot
  for (int j = low; j < high; ++j) {
    // Convert both strings to lowercase before comparing
    if (toLowercase(items[j].first) <= toLowercase(pivot)) {
      ++i;  // Increment the index of the smaller element
      std::swap(items[i],
                items[j]);  // Swap the current element with the smaller element
    }
  }

  std::swap(items[i + 1],
            items[high]);  // Swap the pivot with the element at index i+1
  return i + 1;            // Return the index of the pivot element
}

// Helper function to convert a string to lowercase
std::string AudioLibrary::toLowercase(const std::string &str) {
  std::string lowercaseStr = str;
  // Transform each character in the string to lowercase using std::transform
  // and std::tolower
  std::transform(lowercaseStr.begin(), lowercaseStr.end(), lowercaseStr.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return lowercaseStr;
}