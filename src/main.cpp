#include "main.h"
#include "validation.h"
#include "audiolibrary.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>


/*
    main.cpp
    Authors: M00851681,
    Created: 
    Updated: 
*/


void clearScreen(const std::string& message)
{
    std::cout << "\033[2J\033[1;1H";
    std::cout << message << std::endl;
}

bool checkNumberOfArguments(int& argumentsCount, char* argv[], std::string& filename)
{
    if (argumentsCount != 2)
    {
        std::cerr << "Invalid number of arguments." << std::endl;
        std::cerr << "Program Execution: " << argv[0] << " <filename>" << std::endl;
        std::cout << "Please enter the filename: ";
        std::getline(std::cin, filename);
        argumentsCount = 2; 
        return true;
    }
    filename = argv[1];
    return true;
}


void mainMenu() 
{
    std::cout << std::endl;
    clearScreen("\n");
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


void userChoice(int choice, AudioLibrary& library)
{
    if (choice == 1)
    {
        library.userAddTrack();
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
}

int main(int argc, char* argv[])
{
    std::cout << std::endl << "Audio Track Library Management System" << std::endl
              << "Group Coursework" << std::endl
              << std::endl;

    std::string filename;
    int argumentCount = argc;

    if (!checkNumberOfArguments(argumentCount, argv, filename))
    {
        return 1;
    }

    AudioLibrary library;
    int choice;

    do
    {
        mainMenu();
        choice = getValidChoice();
        userChoice(choice, library);
        std::cout << std::endl;
    } while (choice != 6);

    return 0;
}


