/**
 * @brief This test case verifies the functionality of the main menu selection.
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "utils.hpp"

TEST_CASE("Main Menu Selection")
{
    /**
     * @brief This section tests the scenario when an invalid option is selected.
     */
    SECTION("Selecting invalid option")
    {
        AudioLibrary library;
        bool stopProgram = false;
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());

        std::istringstream input("51\n6\n");
        std::streambuf *oldCinBuf = std::cin.rdbuf();
        std::cin.rdbuf(input.rdbuf());

        mainMenuSelector(&stopProgram, library);
        std::cin.rdbuf(oldCinBuf);
        std::cout.rdbuf(sbuf);
        std::string output = buffer.str();
        REQUIRE(output.find("Invalid choice. Press 'Enter' to try again.") != std::string::npos);
    }

    /**
     * @brief This section tests the scenario when the program is stopped.
     */
    SECTION("Stopping the program")
    {
        AudioLibrary library;
        bool stopProgram = false;
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());

        std::istringstream input("6\n");
        std::streambuf *oldCinBuf = std::cin.rdbuf();
        std::cin.rdbuf(input.rdbuf());

        mainMenuSelector(&stopProgram, library);

        std::cin.rdbuf(oldCinBuf);
        std::cout.rdbuf(sbuf);
        std::string output = buffer.str();

        REQUIRE(output.find("Exiting the program. Goodbye!") != std::string::npos);
        REQUIRE(stopProgram == true);
    }

    /**
     * @brief This section tests if the main menu is correctly displayed.
     */
    SECTION("Checking if menu is correctly displayed")
    {
        AudioLibrary library;
        bool stopProgram = false;
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());

        std::istringstream input("6");
        std::streambuf *oldCinBuf = std::cin.rdbuf();
        std::cin.rdbuf(input.rdbuf());

        mainMenuSelector(&stopProgram, library);

        std::cin.rdbuf(oldCinBuf);
        std::cout.rdbuf(sbuf);
        std::string output = buffer.str();

        REQUIRE(output.find("| 1. Add Audio File                           |") != std::string::npos);
        REQUIRE(output.find("| 2. List Audio                               |") != std::string::npos);
        REQUIRE(output.find("| 3. Search                                   |") != std::string::npos);
        REQUIRE(output.find("| 4. Create Playlist                          |") != std::string::npos);
        REQUIRE(output.find("| 5. Delete                                   |") != std::string::npos);
        REQUIRE(output.find("| 6. Exit                                     |") != std::string::npos);
    }
}