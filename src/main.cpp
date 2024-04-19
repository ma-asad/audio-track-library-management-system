#include "utils.hpp"

int main() {
  AudioLibrary library;
  bool stopProgram = false;

  do {
    mainMenuSelector(&stopProgram, library);
  } while (!stopProgram);

  return 0;
}