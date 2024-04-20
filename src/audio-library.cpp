#include "audio-library.hpp"

/*
    audioLibrary.cpp
    Created:
    Updated:
*/

void AudioLibrary::quickSort(std::pair<std::string, AudioTrack> *items, int low,
                             int high) {
  // Partition the array and get the pivot index
  if (low < high) {
    int pivotIndex = partition(items, low, high);

    // Recursively sort the left subarray
    quickSort(items, low, pivotIndex - 1);

    // Recursively sort the right subarray
    quickSort(items, pivotIndex + 1, high);
  }
}

int AudioLibrary::partition(std::pair<std::string, AudioTrack> *items, int low,
                            int high) {
  // Use the key (audio name) of the last element as the pivot
  std::string pivot = items[high].first;

  // Index of the smaller element
  int i = low - 1;

  // Iterate over the subarray and partition it around the pivot
  for (int j = low; j < high; ++j) {
    // Convert both strings to lowercase before comparing
    if (toLowercase(items[j].first) <= toLowercase(pivot)) {
      // Increment the index of the smaller element
      ++i;

      // Swap the current element with the smaller element
      std::swap(items[i], items[j]);
    }
  }

  // Swap the pivot with the element at index i+1
  std::swap(items[i + 1], items[high]);

  // Return the index of the pivot element
  return i + 1;
}

std::string AudioLibrary::toLowercase(const std::string &str) {
  std::string lowercaseStr = str;
  // Transform each character in the string to lowercase using std::transform
  // and std::tolower
  std::transform(lowercaseStr.begin(), lowercaseStr.end(), lowercaseStr.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  return lowercaseStr;
}

AudioLibrary::AudioLibrary()
    : tracksTable(),
      artistTable(),
      albumNameTable(),
      genreTable(),
      playlistTable() {}

AudioLibrary::~AudioLibrary() {}

bool AudioLibrary::addTrackToHashTables(const AudioTrack &track) {
  std::string authorName = track.getAuthorName();
  std::string audioName = track.getAudioName();
  std::string albumName = track.getAlbumName();
  std::string genre = track.getGenre();
  std::string playlist = track.getPlaylist();

  bool trackInserted = tracksTable.insert(audioName, track);
  bool artistInserted = artistTable.insert(authorName, track);
  bool albumInserted = albumNameTable.insert(albumName, track);
  bool genreInserted = genreTable.insert(genre, track);
  bool playlistInserted = playlistTable.insert(playlist, track);

  return trackInserted && artistInserted && albumInserted && genreInserted &&
         playlistInserted;
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
      addTrackToHashTables(track);
    }
  }
  file.close();
}

void AudioLibrary::addTrackFromCSV() {
  bool fileInputCompleted = false;

  std::cout << "<- (Go Back: Input 'C')" << std::endl;

  std::string filename = "";

  filename = "./data/audio_file.csv";
  loadData(filename);

  return;

  do {
    std::cout << "\n" << std::endl;
    std::cout << "Please input the full path to the CSV file." << std::endl;
    std::cout << "(e.g., \"C:\\Users\\<username>\\Documents\\mydata.csv)\""
              << std::endl;
    std::cout << "\n";
    std::cout << "Input Path ('C' to go back): ";
    std::getline(std::cin, filename);

    // check if filename is empty
    if (filename == "C") {
      fileInputCompleted = true;
    }

    if (filename.empty()) {
      std::cerr << "Filename can't be empty! Please try again." << std::endl;
      continue;
    }

    if (!checkFileExistence(filename)) {
      std::cerr << "File can't be found! Please try again." << std::endl;
      continue;
    }

    if (filename.size() >= 5 &&
        filename.substr(filename.size() - 4) == ".csv") {
      loadData(filename);
      fileInputCompleted = true;
    } else {
      std::cerr << "Wrong file format! Please try again" << std::endl;
    }

  } while (!fileInputCompleted);
}

bool AudioLibrary::checkFileExistence(const std::string &filename) {
  std::ifstream file(filename);
  return file.good();
}

void AudioLibrary::deleteAudio() {
  bool deleteAudioCompleted = false;

  std::cout << "<- (Go Back: Input 'C')" << std::endl;

  std::string audioName = "";

  do {
    std::cout << "\n" << std::endl;
    std::cout << "Please input the name of the audio track you want to delete."
              << std::endl;
    std::cout << "\n";
    std::cout << "Input Audio Name ('C' to go back): ";
    std::getline(std::cin, audioName);

    if (audioName == "C") {
      deleteAudioCompleted = true;
    }

    if (audioName.empty()) {
      std::cerr << "Audio name can't be empty! Please try again." << std::endl;
      continue;
    }

    if (deleteTrackFromTable(audioName)) {
      std::cout << "Track \"" << audioName << "\" Deleted Successfully."
                << std::endl;

      continue;
    } else {
      std::cout << "Error occured while deleting track! Please try again."
                << std::endl;
    };

  } while (!deleteAudioCompleted);
}

bool AudioLibrary::deleteTrackFromTable(const std::string &audioName) {
  AudioTrack *trackContent = tracksTable.findTrack(audioName);

  if (trackContent == nullptr) {
    return false;
  }

  // Get the metadata of the audio track
  std::string artistName = trackContent->getAuthorName();
  std::string albumName = trackContent->getAlbumName();
  std::string genre = trackContent->getGenre();
  std::string playlist = trackContent->getPlaylist();

  // Remove the audio track from all hash tables
  bool tracksTableResult = tracksTable.remove(audioName);
  bool artistTableResult = artistTable.remove(artistName);
  bool albumNameTableResult = albumNameTable.remove(albumName);
  bool genreTableResult = genreTable.remove(genre);
  bool playlistTableResult = playlistTable.remove(playlist);

  // Return false if any of the removal operations failed
  if (!tracksTableResult && !artistTableResult && !albumNameTableResult &&
      !genreTableResult && !playlistTableResult) {
    return false;
  }
  return true;
}

void AudioLibrary::listAudio() {
  std::pair<size_t, std::pair<std::string, AudioTrack> *> result =
      tracksTable.listItems();

  size_t counter = result.first;
  std::pair<std::string, AudioTrack> *items = result.second;

  int count = 0;

  // Quicksort algorithm to sort the audio tracks by name (A-Z)
  quickSort(items, 0, counter - 1);

  // Iterate over the sorted audio tracks and display their details
  std::cout << "-----------------------------" << std::endl;
  for (size_t c = 0; c < counter; ++c) {
    const AudioTrack &track = items[c].second;
    std::cout << "No. " << count << std::endl;
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

  std::cout << "\n";
  std::cout << "<- (Go Back, Press 'Enter')" << std::endl;
  std::cin.get();
}

void AudioLibrary::searchTracks(const SearchType searchType,
                                const std::string &searchQuery) {
  std::pair<size_t, std::pair<std::string, AudioTrack> *> searchResults;

  if (searchType == SearchType::Track) {
    searchResults = tracksTable.findAllTracks(searchQuery);
  } else if (searchType == SearchType::Artist) {
    searchResults = artistTable.findAllTracks(searchQuery);
  } else if (searchType == SearchType::Album) {
    searchResults = albumNameTable.findAllTracks(searchQuery);
  } else if (searchType == SearchType::Genre) {
    searchResults = genreTable.findAllTracks(searchQuery);
  } else if (searchType == SearchType::Playlist) {
    searchResults = playlistTable.findAllTracks(searchQuery);
  }

  size_t counter = searchResults.first;

  if (counter == 0) {
    std::cout << "No tracks found for the search query: " << searchQuery
              << std::endl;
    std::cin.get();
    return;
  }

  std::cout << "-----------------------------" << std::endl;
  for (size_t count = 0; count < counter; count++) {
    const AudioTrack &track = searchResults.second[count].second;
    std::cout << "No. " << count << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Author Name: " << track.getAuthorName() << std::endl;
    std::cout << "Audio Name: " << track.getAudioName() << std::endl;
    std::cout << "Album Name: " << track.getAlbumName() << std::endl;
    std::cout << "Genre: " << track.getGenre() << std::endl;
    std::cout << "Duration: " << track.getDuration() << std::endl;
    std::cout << "Date Published: " << track.getDatePublished() << std::endl;
    std::cout << "Playlist: " << track.getPlaylist() << std::endl;
    std::cout << "-----------------------------" << std::endl;
  }

  std::cout << "\n";
  std::cout << "<- (Go Back, Press 'Enter')" << std::endl;
  std::cin.get();
}

void AudioLibrary::addTrackToPlaylist(const std::string& playlistName){
  int choice = 1;
    while (choice != 0) {
      std::string trackName;
      std::cout << "Enter the name of the track to add (or enter 0 to finish): ";
      std::getline(std::cin, trackName);

        if (trackName == "0") {
            choice = 0;
        } else{
          AudioTrack* track = findTrackByName(trackName);
          if (track != nullptr){
            playlistTable.insert(playlistName, *track);
            std::cout << "The track has been added to the playliss" << std::endl;
          } else {
            std::cout << "The Track was not found" << std::endl;
          }
        }

        if (choice != 0){
          bool validChoice = false;
          while (!validChoice){
              std::cout << "Do you want to add another track?" << std::endl;
              std::cout << "1. Yes" << std::endl;
              std::cout << "0. No" << std::endl;
              std::cout << "Enter your choice: " << std::endl;
              std::string input;
              std::getline(std::cin, input);
              if (input.length() == 1 && std::isdigit(input[0])) {
                choice = std::stoi(input);
                if (choice == 0 || choice == 1) {
                  validChoice = true;
                } else {
                  std::cout << "Invalid choice. Please enter either 0 or 1." 
                            << std::endl;
                }
              } else {
                std::cout << "Invalid choice. Please enter a valid choice." 
                          << std::endl;
              }
          }
        }
    }
}

void AudioLibrary::addTrackToExistingPlaylist(){
  std::string playlistName;
  std::cout << "Enter the name of playlist where to add tracks: ";
  std::getline(std::cin, playlistName);

  // check if the playlist alredy exists and tracks to it
  std::pair<int, std::pair<std::string, AudioTrack>*> existingPlaylist = playlistTable.findAllTracks(playlistName);
  if (existingPlaylist.first > 0) {
      addTrackToPlaylist(playlistName);
  } else {
      std::cout << "The playlist with name \"" << playlistName 
                << "\" does not exists." << std::endl;
      std::cout << "Please create the playlist first or enter a valid playlist.";
      std::cout << "Press enter to go  back to playlist menu.";
      std::cin.ignore();
  }
}

void AudioLibrary::createPlaylist(){
  std::string playlistName;
  std::cout << "Enter the name of the new playlist: ";
  std::getline(std::cin, playlistName);

  if (playlistName.empty()) {
    std::cout << "Playlist creation canceled. " << std::endl;
    return;
  }
  // check if the playlist already exists
    std::pair<int, std::pair<std::string, AudioTrack>*> existingPlaylist 
            = playlistTable.findAllTracks(playlistName);
    if (existingPlaylist.first > 0) {
        std::cout << "The playlist with name \"" << playlistName 
                  << "\" already exists." << std::endl;
        std::cout << "Press enter to go  back to playlist menu.";
        std::cin.ignore();
        return;
    }
    
    addTrackToPlaylist(playlistName);
    
    std::cout << "Playlist created successfully." << std::endl;
    std::cout << "Press Enter to go back to the playlist menu." << std::endl;
    std::cin.ignore();
}



void AudioLibrary::deletePlaylist() {
  std::string playlistName;
  std::cout << "Enter the name of the playlist to delete: ";
  std::getline(std::cin, playlistName);
  std::pair<int, std::pair<std::string, AudioTrack>*>
          playlistTracks = playlistTable.findAllTracks(playlistName);
  int numTracks = playlistTracks.first;

  if (numTracks == 0){
    std::cout << "Playlist not found." << std::endl;
  } else {
    for (int c = 0; c < numTracks; ++c){
      playlistTable.remove(playlistName);
    }
    std::cout << "The Playlist has been deleted successfully." << std::endl;
  }
  std::cout << "Press Enter to go back to the playlist menu." << std::endl;
  std::cin.ignore();
}

void AudioLibrary::viewPlaylist() {
    std::string playlistName;
    std::cout << "Enter the name of the playlist to view: ";
    std::getline(std::cin, playlistName);

    std::pair<int, std::pair<std::string, AudioTrack>*> playlistTracks 
                    = playlistTable.findAllTracks(playlistName);

    int numTracks = playlistTracks.first;
    std::pair<std::string, AudioTrack>* tracks = playlistTracks.second;
    
    if (numTracks == 0){
      std::cout << "The Playlist not found or empty. " << std::endl;
    } else {
      std::cout << "Playlist: " << playlistName << std::endl;
      for (int c = 0; c <numTracks; ++c){
        const AudioTrack& track = tracks[c].second;
        std::cout << "Track " << (c + 1) << ": " << track.getAudioName() 
                  << std::endl;
      }
    }
    std::cout << "Press Enter to go back to the playlist menu ";
    std::cin.ignore(); 
}





