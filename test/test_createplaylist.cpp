#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>

#include "audio-library.hpp"
#include "audio-track.hpp"
#include "catch.hpp"
#include "hash-table.hpp"

TEST_CASE("Creating and Managing Playlists") {
  AudioLibrary library;

  // tracks
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

  SECTION("Create a new playlist") {
    std::istringstream input(
        "My Playlist\nCampaign eye interview\n1\nCall\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());

    library.createPlaylist();

    std::pair<int, std::pair<std::string, AudioTrack>*> playlistTracks =
        library.getPlaylistTable().findAllTracks("My Playlist");

    REQUIRE(playlistTracks.first == 2);
    REQUIRE(playlistTracks.second[0].second.getAudioName() ==
            "Campaign eye interview");
    REQUIRE(playlistTracks.second[1].second.getAudioName() == "Call");

    delete[] playlistTracks.second;
  }

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

  SECTION("View an existing playlist") {
    std::istringstream input(
        "Existing Playlist\nCampaign eye interview\nCall\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());
    library.createPlaylist();

    std::istringstream input2("Existing Playlist\nCall\n0\n");
    std::cin.rdbuf(input2.rdbuf());
    library.viewPlaylist();
  }

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