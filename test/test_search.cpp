#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>

#include "audio-library.hpp"
#include "audio-track.hpp"
#include "catch.hpp"
#include "hash-table.hpp"

TEST_CASE("Search for a key in the hash table") {
  SECTION("Search for existing artist") {
    AudioLibrary library;

    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");
    AudioTrack track3("Debra Alexander", "call2", "Social age", "Country",
                      "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track4("Lori Brown", "Call4", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));
    REQUIRE(library.addTrackToHashTables(track3));
    REQUIRE(library.addTrackToHashTables(track4));

    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::istringstream input("\n");
    std::streambuf *oldCinBuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    library.searchTracks(SearchType::Artist, "Debra Alexander");
    std::cin.rdbuf(oldCinBuf);
    std::cout.rdbuf(sbuf);
    std::string output = buffer.str();

    REQUIRE(output.find("Author Name: Debra Alexander") != std::string::npos);
    REQUIRE(output.find("Author Name: Lori Brown") == std::string::npos);
  }

  SECTION("Search for existing track") {
    AudioLibrary library;

    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");
    AudioTrack track3("Debra Alexander", "call2", "Social age", "Country",
                      "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track4("Lori Brown", "Call4", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));
    REQUIRE(library.addTrackToHashTables(track3));
    REQUIRE(library.addTrackToHashTables(track4));

    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::istringstream input("\n");
    std::streambuf *oldCinBuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    library.searchTracks(SearchType::Track, "Call");
    std::cin.rdbuf(oldCinBuf);
    std::cout.rdbuf(sbuf);
    std::string output = buffer.str();

    REQUIRE(output.find("Audio Name: Call") != std::string::npos);
    REQUIRE(output.find("Author Name: Lori Brown") != std::string::npos);
    REQUIRE(output.find("Audio Name: Campaign eye interview") ==
            std::string::npos);
  }

  SECTION("Search for existing album") {
    AudioLibrary library;

    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");
    AudioTrack track3("Debra Alexander", "call2", "Social age", "Country",
                      "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track4("Lori Brown", "Call4", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));
    REQUIRE(library.addTrackToHashTables(track3));
    REQUIRE(library.addTrackToHashTables(track4));

    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::istringstream input("\n");
    std::streambuf *oldCinBuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    library.searchTracks(SearchType::Album, "Social age");
    std::cin.rdbuf(oldCinBuf);
    std::cout.rdbuf(sbuf);
    std::string output = buffer.str();

    REQUIRE(output.find("Album Name: Social age") != std::string::npos);
    REQUIRE(output.find("Author Name: Debra Alexander") != std::string::npos);
    REQUIRE(output.find("Album Name: Her") == std::string::npos);
  }

  SECTION("Search for existing genre") {
    AudioLibrary library;

    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");
    AudioTrack track3("Debra Alexander", "call2", "Social age", "Country",
                      "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track4("Lori Brown", "Call4", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));
    REQUIRE(library.addTrackToHashTables(track3));
    REQUIRE(library.addTrackToHashTables(track4));

    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::istringstream input("\n");
    std::streambuf *oldCinBuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    library.searchTracks(SearchType::Genre, "Hip Hop");
    std::cin.rdbuf(oldCinBuf);
    std::cout.rdbuf(sbuf);
    std::string output = buffer.str();

    REQUIRE(output.find("Genre: Hip Hop") != std::string::npos);
    REQUIRE(output.find("Audio Name: Call") != std::string::npos);
    REQUIRE(output.find("Genre: Country") == std::string::npos);
  }

  SECTION("Search for non existing tracks") {
    AudioLibrary library;

    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));

    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::istringstream input("\n");
    std::streambuf *oldCinBuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    library.searchTracks(SearchType::Artist, "John Doe");
    std::cin.rdbuf(oldCinBuf);
    std::cout.rdbuf(sbuf);
    std::string output = buffer.str();

    REQUIRE(output.find("No tracks found for the search query: John Doe") !=
            std::string::npos);
  }

  SECTION("Search for non existing albums") {
    AudioLibrary library;

    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));

    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::istringstream input("\n");
    std::streambuf *oldCinBuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    library.searchTracks(SearchType::Album, "Social Cage");
    std::cin.rdbuf(oldCinBuf);
    std::cout.rdbuf(sbuf);
    std::string output = buffer.str();

    REQUIRE(output.find("No tracks found for the search query: Social Cage") !=
            std::string::npos);
  }

  SECTION("Search for non existing genre") {
    AudioLibrary library;

    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));

    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::istringstream input("\n");
    std::streambuf *oldCinBuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    library.searchTracks(SearchType::Genre, "Jazz");
    std::cin.rdbuf(oldCinBuf);
    std::cout.rdbuf(sbuf);
    std::string output = buffer.str();

    REQUIRE(output.find("No tracks found for the search query: Jazz") !=
            std::string::npos);
  }

  SECTION("Search for non existing artist") {
    AudioLibrary library;

    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));

    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::istringstream input("\n");
    std::streambuf *oldCinBuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    library.searchTracks(SearchType::Artist, "John Doe");
    std::cin.rdbuf(oldCinBuf);
    std::cout.rdbuf(sbuf);
    std::string output = buffer.str();

    REQUIRE(output.find("No tracks found for the search query: John Doe") !=
            std::string::npos);
  }
}