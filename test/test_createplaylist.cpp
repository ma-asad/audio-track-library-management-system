#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>

#include "audio-library.hpp"
#include "audio-track.hpp"
#include "catch.hpp"
#include "hash-table.hpp"

TEST_CASE("Creating and Managing Playlists") {
  AudioLibrary library;

  // sample tracks added to the library's hash tables
  AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                    "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
  AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                    "2016 - 10 - 10", "Over off");
  AudioTrack track3("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                    "2016 - 10 - 10", "Over off");
  AudioTrack track4("John McLean", "Call", "Boom", "Jazz", "0 : 03 : 42",
                    "2014 - 08 - 23", "Karaoke");

  library.addTrackToHashTables(track1);
  library.addTrackToHashTables(track2);
  library.addTrackToHashTables(track4);

  // This section test the functionality of creating a new playlist
  // It tests user input to create a playlist and add two tracks to it
  SECTION("Create a new playlist") {
    std::istringstream input(
        "My Playlist\nCampaign eye interview\n1\nCall\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());

    library.createPlaylist();
    // retrieces the tracks from the newly created playlist from the hash table
    std::pair<int, std::pair<std::string, AudioTrack>*> playlistTracks =
        library.getPlaylistTable().findAllTracks("My Playlist");

    REQUIRE(playlistTracks.first == 2);
    REQUIRE(playlistTracks.second[0].second.getAudioName() ==
            "Campaign eye interview");
    REQUIRE(playlistTracks.second[1].second.getAudioName() == "Call");

    delete[] playlistTracks.second;
  }

  // This section tests the functionality of adding tracks to an existing playlist
  SECTION("Add tracks to an existing playlist") {
    std::istringstream input(
        "Existing Playlist\nCampaign eye interview\n1\nCall\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());
    library.createPlaylist();

    std::istringstream input2("Existing Playlist\nCall\n0\n");
    std::cin.rdbuf(input2.rdbuf());
    library.createPlaylist();

    std::pair<int, std::pair<std::string, AudioTrack>*> playlistTracks =
        library.getPlaylistTable().findAllTracks("Existing Playlist");

    REQUIRE(playlistTracks.first == 2);
    REQUIRE(playlistTracks.second[0].second.getAudioName() ==
            "Campaign eye interview");
    REQUIRE(playlistTracks.second[1].second.getAudioName() == "Call");

    delete[] playlistTracks.second;
  }

  // This section tests the functionality of viewing an existing playlist
  SECTION("View an existing playlist") {
    std::istringstream input(
        "Existing Playlist\nCampaign eye interview\nCall\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());
    library.createPlaylist();

    // Redirect cout to a stringstream to capture the output of viewPlaylist
    std::stringstream outputStream;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(outputStream.rdbuf());

    std::istringstream input2("Existing Playlist\nCall\n0\n");
    std::cin.rdbuf(input2.rdbuf());
    library.viewPlaylist();

    // restore cout to its original buffer
    std::cout.rdbuf(oldCoutBuf);

    // get the captured output as a string
    std::string output = outputStream.str();

    std::cout << "Captured Output:\n" << output << std::endl;

    // Assert that the output contains the expected playlist
    REQUIRE(output.find("Playlist: Existing Playlist") != std::string::npos);
    REQUIRE(output.find("Track 1: Campaign eye interview") != std::string::npos);

  }
  // This section tests the functionality of deleting an existing playlist
  SECTION("Delete an existing playlist") {
    std::istringstream input(
        "Existing Playlist\nCampaign eye interview\nCall\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());
    library.createPlaylist();

    std::istringstream input2("Existing Playlist\nCall\n0\n");
    std::cin.rdbuf(input2.rdbuf());
    library.deletePlaylist();

    std::pair<int, std::pair<std::string, AudioTrack>*>
    playlistTracks
    =
    library.getPlaylistTable().findAllTracks("Existing Playlist");

    REQUIRE(playlistTracks.first == 0);
    delete[] playlistTracks.second;
  }
}