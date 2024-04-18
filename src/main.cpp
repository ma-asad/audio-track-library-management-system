#include "main.hpp"

void exitProgram(bool* stopProgram) {
  std::cout << "Exiting the program. Goodbye!" << std::endl;
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

void displaySearchMenu() {
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
}

void displayMainMenu() {
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
}

void searchMenuSelector(AudioLibrary& library) {
  std::system(CLEAR);

  displaySearchMenu();

  int searchOptionSelected;
  std::cout << "Enter your choice: ";
  std::cin >> searchOptionSelected;

  switch (searchOptionSelected) {
    case 1:
      newWindow("Search by Artist");
      break;
    case 2:
      newWindow("Search by Audio Title");
      break;
    case 3:
      newWindow("Search by Album");
      break;
    case 4:
      newWindow("Search by Genre");
      break;
    case 5:
      newWindow("Search by Playlist");
      break;
    case 6:
      break;
    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
      std::cin.get();
      searchMenuSelector(library);
      break;
  }
}

void mainMenuSelector(bool* stopProgram, AudioLibrary& library) {
  std::system(CLEAR);

  displayMainMenu();

  int menuOptionSelected;
  std::cout << "Enter your choice: ";
  std::cin >> menuOptionSelected;

  switch (menuOptionSelected) {
    case 1:
      newWindow("Add Audio File");
      library.addTrackFromCSV();
      break;
    case 2:
      newWindow("List Audio");
      break;
    case 3:
      searchMenuSelector(library);
      break;
    case 4:
      newWindow("Create Playlist");
      break;
    case 5:
      newWindow("Delete Audio");
      break;
    case 6:
      exitProgram(stopProgram);
      break;

    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
      std::cin.get();
      break;
  }
}

int main() {
  AudioLibrary library;
  bool stopProgram = false;
  do {
    mainMenuSelector(&stopProgram, library);
  } while (stopProgram == true);

  return 0;
}