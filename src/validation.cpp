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


int getValidAddChoice() {
  int addChoice;
  bool valid = false;

  do {
    std::cout << "\n1.Add from CSV \n2.Add manually \n\nEnter your choice: ";
    std::cin >> addChoice;

    if (std::cin.fail()) {
      std::cout << "\nInvalid Input! Please enter a valid integer.\n" 
                << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (addChoice != 1 && addChoice != 2) {
        std::cout << "\nInvalid Choice! Please enter 1 or 2.\n" 
                  << std::endl;
    } else {
        valid = true;
    }
  } while (!valid);

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return addChoice;
}