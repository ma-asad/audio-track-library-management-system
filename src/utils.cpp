#include "utils.hpp"

void exitProgram(bool* stopProgram) {
  std::cout << "Exiting the program. Goodbye!" << std::endl;
  std::cout << std::endl;
  *stopProgram = true;
}

void newWindow(std::string windowTitle) {
  // Define the width of the banner
  const int bannerWidth = 47;

  const int titleLength = windowTitle.length();

  // Calculate the padding on the left and right of the title
  int paddingLeft = (bannerWidth - titleLength - 2) / 2;
  int paddingRight = (bannerWidth - titleLength - 2) / 2;

  if (titleLength % 2 == 0) {
    paddingRight++;
  }

  // Create strings of spaces for the left and right padding
  std::string paddingSpacesLeft(paddingLeft, ' ');
  std::string paddingSpacesRight(paddingRight, ' ');

  std::system(CLEAR);

  std::cout << "*=============================================*" << std::endl;
  std::cout << "|" << paddingSpacesLeft << windowTitle << paddingSpacesRight
            << "|" << std::endl;
  std::cout << "*=============================================*" << std::endl;

  std::cout << std::endl;
}

std::string getSearchQuery(std::string searchType) {
  std::string searchQuery = "";

  std::cout << "Search " << searchType << ": ";
  std::getline(std::cin, searchQuery);
  std::cout << std::endl;

  return searchQuery;
}

void searchMenuSelector(AudioLibrary& library) {
  std::system(CLEAR);

  std::cout << std::endl;
  std::cout << "*=============================================*" << std::endl;
  std::cout << "|                  SEARCH MENU                |" << std::endl;
  std::cout << "*=============================================*" << std::endl;
  std::cout << "| Search by, choose an option below :         |" << std::endl;
  std::cout << "| 1. Artist                                   |" << std::endl;
  std::cout << "| 2. Audio Title                              |" << std::endl;
  std::cout << "| 3. Album                                    |" << std::endl;
  std::cout << "| 4. Genre                                    |" << std::endl;
  std::cout << "| 5. Playlist                                 |" << std::endl;
  std::cout << "| 6. <- Go Back to Main Menu                  |" << std::endl;
  std::cout << "*=============================================*" << std::endl;
  std::cout << std::endl;

  int searchOptionSelected = 0;
  std::string userInput;
  std::cout << "Enter your choice (e.g. 1): ";
  std::getline(std::cin, userInput);

  // If the user input is empty, set the selected option to 0
  if (userInput.empty()) {
    searchOptionSelected = 0;
  }

  // Try to convert the user input to an integer
  try {
    searchOptionSelected = std::stoi(userInput);
  } catch (std::invalid_argument const& e) {
    // If the conversion fails due to an invalid argument, set the selected
    // option to 0
    searchOptionSelected = 0;
  } catch (std::out_of_range const& e) {
    // If the conversion fails due to out of range, set the selected option to 0
    searchOptionSelected = 0;
  }

  // Perform the action based on the selected option
  if (searchOptionSelected == 1) {
    newWindow("Search by Artist");
    library.searchTracks(SearchType::Artist, getSearchQuery("Artist"));
  } else if (searchOptionSelected == 2) {
    newWindow("Search by Audio Title");
    library.searchTracks(SearchType::Track, getSearchQuery("Audio"));
  } else if (searchOptionSelected == 3) {
    newWindow("Search by Album");
    library.searchTracks(SearchType::Album, getSearchQuery("Album"));
  } else if (searchOptionSelected == 4) {
    newWindow("Search by Genre");
    library.searchTracks(SearchType::Genre, getSearchQuery("Genre"));
  } else if (searchOptionSelected == 5) {
    newWindow("Search by Playlist");
    library.searchTracks(SearchType::Playlist, getSearchQuery("Playlist"));
  } else if (searchOptionSelected == 6) {
    // Go back to main menu
    return;
  } else {
    std::cout << "Invalid choice. Press 'Enter' to try again." << std::endl;
    std::cin.get();
  }

  searchMenuSelector(library);
}

void playlistMenuSelector(AudioLibrary& library) {
  std::system(CLEAR);

  std::cout << std::endl;
  std::cout << "*=============================================*" << std::endl;
  std::cout << "|                  PLAYLIST MENU              |" << std::endl;
  std::cout << "*=============================================*" << std::endl;
  std::cout << "| Choose an option below :                    |" << std::endl;
  std::cout << "| 1. Create Playlist and add track            |" << std::endl;
  std::cout << "| 2. Add track to Playlist                    |" << std::endl;
  std::cout << "| 3. View Playlist                            |" << std::endl;
  std::cout << "| 4. Delete Playlist                          |" << std::endl;
  std::cout << "| 5. <- Go Back to Main Menu                  |" << std::endl;
  std::cout << "*=============================================*" << std::endl;
  std::cout << std::endl;

  int playlistOptionSelected = 0;
  std::string userInput;
  std::cout << "Enter your choice (e.g. 1): ";
  std::getline(std::cin, userInput);

  if (userInput.empty()) {
    playlistOptionSelected = 0;
  }

  try {
    playlistOptionSelected = std::stoi(userInput);
  } catch (std::invalid_argument const& e) {
    playlistOptionSelected = 0;
  } catch (std::out_of_range const& e) {
    playlistOptionSelected = 0;
  }

  if (playlistOptionSelected == 1) {
    newWindow("Create Playlist and add track");
    library.createPlaylist();
  } else if (playlistOptionSelected == 2) {
    newWindow("Add track to Playlist");
    library.addTrackToExistingPlaylist();
  } else if (playlistOptionSelected == 3) {
    newWindow("View Playlist");
    library.viewPlaylist();
  } else if (playlistOptionSelected == 4) {
    newWindow("Delete Playlist");
    library.deletePlaylist();
  } else if (playlistOptionSelected == 5) {
    // Go back to main menu
    return;
  } else {
    std::cout << "Invalid choice. Press 'Enter' to try again." << std::endl;
    std::cin.get();
  }
  playlistMenuSelector(library);
}

void mainMenuSelector(bool* stopProgram, AudioLibrary& library) {
  std::system(CLEAR);

  std::cout << std::endl;
  std::cout << "*=============================================*" << std::endl;
  std::cout << "|                  MAIN MENU                  |" << std::endl;
  std::cout << "*=============================================*" << std::endl;
  std::cout << "| Choose an option below :                    |" << std::endl;
  std::cout << "| 1. Add Audio File                           |" << std::endl;
  std::cout << "| 2. List Audio                               |" << std::endl;
  std::cout << "| 3. Search                                   |" << std::endl;
  std::cout << "| 4. Create Playlist                          |" << std::endl;
  std::cout << "| 5. Delete                                   |" << std::endl;
  std::cout << "| 6. Exit                                     |" << std::endl;
  std::cout << "*=============================================*" << std::endl;
  std::cout << std::endl;

  int menuOptionSelected = 0;
  std::string userInput;
  std::cout << "Enter your choice (e.g. 1): ";
  std::getline(std::cin, userInput);

  if (userInput.empty()) {
    menuOptionSelected = 0;
  }

  try {
    menuOptionSelected = std::stoi(userInput);
  } catch (std::invalid_argument const& e) {
    menuOptionSelected = 0;
  } catch (std::out_of_range const& e) {
    menuOptionSelected = 0;
  }

  if (menuOptionSelected == 1) {
    newWindow("Add Audio File");
    library.addTrackFromCSV();
  } else if (menuOptionSelected == 2) {
    newWindow("List Audio");
    library.listAudio();
  } else if (menuOptionSelected == 3) {
    searchMenuSelector(library);
  } else if (menuOptionSelected == 4) {
    playlistMenuSelector(library);
  } else if (menuOptionSelected == 5) {
    newWindow("Delete Audio");
    library.deleteAudio();
  } else if (menuOptionSelected == 6) {
    exitProgram(stopProgram);
  } else {
    std::cout << "Invalid choice. Press 'Enter' to try again." << std::endl;
    std::cin.get();
  }
}
