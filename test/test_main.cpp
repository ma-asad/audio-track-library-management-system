#define CATCH_CONFIG_MAIN
#include <sstream>

#include "catch.hpp"
#include "validation.hpp"

TEST_CASE("Get Valid Choice", "[input]") {
  std::streambuf* cinBuffer = std::cin.rdbuf();

  SECTION("Test valid menu choice") {
    std::istringstream iss("1\n");

    std::cin.rdbuf(iss.rdbuf());

    int choice = getValidChoice();

    REQUIRE(choice == 1);
  }

  SECTION("Test invalid menu choice - Out of range") {
    std::istringstream iss("7\n1\n");

    std::cin.rdbuf(iss.rdbuf());

    int choice = getValidChoice();

    REQUIRE(choice == 1);
  }

  SECTION("Test invalid menu Choice - Invalid input") {
    std::istringstream iss("abc\n1\n");

    std::cin.rdbuf(iss.rdbuf());

    int choice = getValidChoice();

    REQUIRE(choice == 1);
  }

  std::cin.rdbuf(cinBuffer);
}