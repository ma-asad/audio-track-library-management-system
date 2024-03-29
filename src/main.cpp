#include "main.h"
#include "validation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>


void clearScreen(const std::string& message)
{
    std::cout << "\033[2J\033[1;1H";
    std::cout << message << std::endl;
}

void mainMenu() {
    std::cout << std::endl;
    clearScreen("Menu\n");
    std::cout << std::endl;
    std::cout << "*=============================================*" << std::endl;
    std::cout << "|                  MAIN MENU                  |" << std::endl;
    std::cout << "*=============================================*" << std::endl;
    std::cout << "| Choose an option below :                    |" << std::endl;
    std::cout << "| 1. Add Music File                           |" << std::endl;
    std::cout << "| 2. Search Music or Album                    |" << std::endl;
    std::cout << "| 3. List All Music, Sort by Artist, Album,   |" << std::endl;
    std::cout << "|    Date, Release, Duration                  |" << std::endl;
    std::cout << "| 4. Create Playlist                          |" << std::endl;
    std::cout << "| 5. Delete Albums or Music, Add Track to     |" << std::endl;
    std::cout << "|    Playlist                                 |" << std::endl;
    std::cout << "| 6. Exit                                     |" << std::endl;
    std::cout << "*=============================================*" << std::endl;
}

int main()
{
    std::cout << std::endl << "Audio Track Library Management System" << std::endl
              << "Group Coursework" << std::endl
              << std::endl;

    int choice;
    do
    {
        mainMenu();
        choice = getValidChoice();

        if (choice == 1)
        {
            
        }
        else if (choice == 2)
        {
    
        }
        else if (choice == 3)
        {

        }
        else if (choice == 4)
        {
            
        }
        else if (choice == 5)
        {
            
        }
        else if (choice == 6)
        {
             std::cout << "Exiting the program. Goodbye!" << std::endl;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout << std::endl;
    } while (choice != 6);

    return 0;
}

