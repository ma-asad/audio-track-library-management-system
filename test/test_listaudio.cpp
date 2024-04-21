#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>

#include "audio-library.hpp"
#include "audio-track.hpp"
#include "catch.hpp"
#include "hash-table.hpp"

TEST_CASE("Listing Audio Tracks in HashTable") {
  AudioLibrary library;

  SECTION("Listing Audio Tracks") {
    // Add tracks to the library
    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));

    // Redirect cout to buffer
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    // Simulate pressing 'Enter'
    std::istringstream input("\n");
    std::streambuf *oldCinBuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    library.listAudio();

    // Restore original buffers
    std::cin.rdbuf(oldCinBuf);
    std::cout.rdbuf(sbuf);

    std::string output = buffer.str();
    // Require for Track 1
    REQUIRE(output.find("Campaign eye interview") != std::string::npos);
    REQUIRE(output.find("Debra Alexander") != std::string::npos);
    REQUIRE(output.find("Social age") != std::string::npos);
    REQUIRE(output.find("Country") != std::string::npos);
    REQUIRE(output.find("0 : 09 : 51") != std::string::npos);
    REQUIRE(output.find("2023 - 04 - 14") != std::string::npos);
    REQUIRE(output.find("Home") != std::string::npos);

    // Require for Track 2
    REQUIRE(output.find("Call") != std::string::npos);
    REQUIRE(output.find("Lori Brown") != std::string::npos);
    REQUIRE(output.find("Her") != std::string::npos);
    REQUIRE(output.find("Hip Hop") != std::string::npos);
    REQUIRE(output.find("0 : 09 : 45") != std::string::npos);
    REQUIRE(output.find("2016 - 10 - 10") != std::string::npos);
    REQUIRE(output.find("Over off") != std::string::npos);
  }
}