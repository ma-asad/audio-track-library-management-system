#include "utils.hpp"

int main() {
  AudioLibrary library;
  bool stopProgram = false;

  // Main program loop
  do {
    mainMenuSelector(&stopProgram, library);
  } while (!stopProgram);

  return 0;
}