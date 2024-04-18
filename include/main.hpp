#ifndef MAIN_H
#define MAIN_H

// TODO: Remove Win32 specific code
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "audio-library.hpp"

/*
    main.hpp
    Created:
    Updated:
*/

/**
 * @brief Exits the program and sets the stopProgram flag to true.
 *
 * This function prints a goodbye message and sets the stopProgram flag to true,
 * indicating that the program should stop running.
 *
 * @param stopProgram A pointer to a boolean flag indicating whether the program
 * should stop running.
 */
void exitProgram(bool* stopProgram);

/**
 * Displays a new window with a specified title.
 *
 * @param windowTitle The title of the window.
 */
void newWindow(std::string windowTitle);

/**
 * Displays the search menu and allows the user to select a search option.
 *
 * @param library The AudioLibrary object to perform the search on.
 */
void searchMenuSelector(AudioLibrary& library);

/**
 * Displays the main menu and handles user input to perform corresponding
 * actions.
 *
 * @param stopProgram A pointer to a boolean variable indicating whether the
 * program should stop.
 * @param library The AudioLibrary object used to perform operations on audio
 * tracks.
 */
void mainMenuSelector(bool* stopProgram, AudioLibrary& library);

/**
 * @brief The entry point of the program.
 *
 * @return int The exit status of the program.
 */
int main();

#endif