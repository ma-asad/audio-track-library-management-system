#include "validation.hpp"

/*
    validation.cpp
    Created: 
    Updated: 
*/


int getValidChoice() {
  int choice;
  bool valid = false;

  do {
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (std::cin.fail()) {
      std::cout << "\nInvalid input. Please enter a valid integer.\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (choice < 1 || choice > 6) {
      std::cout << "\nInvalid choice. Please enter a number between 1 and 6.\n"
                << std::endl;
    } else {
      valid = true;
    }
  } while (!valid);

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return choice;
}