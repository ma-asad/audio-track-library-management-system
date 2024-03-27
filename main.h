#ifndef MAIN_H
#define MAIN_H

#include <string>


/*
    check the number of arguments passed from the command line
    @param argc The number of command line arguments
    @param argv The array of command line arguments
    @param FILENAME Reference to a string where the filename will be stored
    @return bool
*/
bool checkNumberOfArguments(int argc, char* argv[], std::string& FILENAME);


/*
    clear the screeen and display title of task
    @param message
    @return void
*/
void clearScreen(const std::string& message);


/*
    Display the main menu where different options will be displayed
*/
void mainMenu();

#endif