#include "validation.h"
#include <iostream>
#include <limits>

/*
    validation.cpp
    Authors: M00851681,
    Created: 
    Updated: 
*/


int getValidChoice() {

    int choice;
    bool validInput = false;

    do
    {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (choice < 1 || choice > 6)
        {
            std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
        }
        else
        {
            validInput = true;
        }
    } while (!validInput);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}