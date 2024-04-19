#include "utils.hpp"

void exitProgram(bool* stopProgram) {
  std::cout << "Exiting the program. BLYAT CYKA!" << std::endl;
  std::cout << std::endl;
  *stopProgram = true;
}

void newWindow(std::string windowTitle) {
  const int bannerWidth = 47;
  const int titleLength = windowTitle.length();

  int paddingLeft = (bannerWidth - titleLength - 2) / 2;
  int paddingRight = paddingLeft;
  if (bannerWidth + titleLength % 2 != 0) paddingRight++;

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

  int searchOptionSelected;
  std::cout << "Enter your choice: ";
  std::cin >> searchOptionSelected;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // TODO: check if enter key is pressed without any value

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
    std::cout << "Invalid choice. Please try again." << std::endl;
    std::cin.get();
  }
  searchMenuSelector(library);
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

  int menuOptionSelected;
  std::cout << "Enter your choice: ";
  std::cin >> menuOptionSelected;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // TODO: check if enter key is pressed without any value

  if (menuOptionSelected == 1) {
    newWindow("Add Audio File");
    library.addTrackFromCSV();
  } else if (menuOptionSelected == 2) {
    newWindow("List Audio");
    library.listAudio();
  } else if (menuOptionSelected == 3) {
    searchMenuSelector(library);
  } else if (menuOptionSelected == 4) {
    newWindow("Create Playlist");
  } else if (menuOptionSelected == 5) {
    newWindow("Delete Audio");
    library.deleteAudio();
  } else if (menuOptionSelected == 6) {
    exitProgram(stopProgram);
  } else {
    std::cout << "Invalid choice. Please try again." << std::endl;
    std::cin.get();
  }
}
