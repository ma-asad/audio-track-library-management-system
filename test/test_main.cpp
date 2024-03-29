#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "validation.h"
#include <sstream>

TEST_CASE("Simulate user input", "[input]") {
  // Save the original buffer that cin uses
  std::streambuf* original_cin = std::cin.rdbuf();

  SECTION("Test valid menu choice") {
    std::istringstream simulated_input("1\n");
    std::cin.rdbuf(simulated_input.rdbuf());

    // Call your function that reads from cin here
    REQUIRE(getValidChoice() == 1);
  }

  SECTION("Test invalid menu choice") {
    std::istringstream simulated_input("7\n");
    std::cin.rdbuf(simulated_input.rdbuf());

    // Call your function that reads from cin here
    REQUIRE(getValidChoice() == -1);
  }

  // Restore cin to its original state
  std::cin.rdbuf(original_cin);
}