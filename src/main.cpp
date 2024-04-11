#include "main.hpp"
#include "validation.hpp"
#include "audiolibrary.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>


/*
    main.cpp
    Created: 
    Updated: 
*/

void enter(){
    std::cout << "\nPress Enter two to go back to menu";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void clearScreen(const std::string& message)
{
    std::cout << "\033[2J\033[1;1H";
    std::cout << message << std::endl;
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
    std::cout << "| 2. Delete                                   |" << std::endl;
    std::cout << "| 3. Search                                   |" << std::endl;
    std::cout << "| 4. Create Playlist                          |" << std::endl;
    std::cout << "| 5. List Audio                               |" << std::endl;
    std::cout << "| 6. Exit                                     |" << std::endl;
    std::cout << "*=============================================*" << std::endl;
}


void userChoice(int choice, AudioLibrary& library)
{
    std::string audioName;
    if (choice == 1){
        clearScreen("Add: Users can add new audio tracks to the library \n");
        int addChoice = getValidAddChoice();
        if (addChoice == 1){
            library.addTrackFromCSV();
        } else if (addChoice == 2){
            library.addTrackManually();
        }
        enter();
    }
    else if (choice == 2){
        clearScreen("Delete: Users can delete existing audio tracks from the library \n");
        std::cout << "Enter the name of the audio track to delete: ";
        std::getline(std::cin, audioName);
        library.deleteTrack(audioName);
        enter();

    }
    else if (choice == 3){
            enter();
    }
    else if (choice == 4){
            enter();
    }
    else if (choice == 5){
            enter();
    }
    else if (choice == 6){
        std::cout << "Exiting the program. Goodbye!" << std::endl;
    }
    else{
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


