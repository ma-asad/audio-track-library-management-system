#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "audio-track.hpp"
#include "hash-table.hpp"
#include "validation.hpp"

// Assuming AudioTrack class has relevant constructors and getters/setters

TEST_CASE("Adding and Deleting Audio Tracks in HashTable") {
  HashTable<std::string, AudioTrack> tracksTable;
  HashTable<std::string, AudioTrack> artistTable;
  HashTable<std::string, AudioTrack> albumNameTable;
  HashTable<std::string, AudioTrack> genreTable;
  HashTable<std::string, AudioTrack> playlistTable;

  SECTION("Adding Audio Tracks") {
    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");
    REQUIRE(tracksTable.insert(track1.getAudioName(), track1));
    REQUIRE(tracksTable.insert(track2.getAudioName(), track2));

    // // Duplicate track
    // AudioTrack track3("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
    //                   "2016 - 10 - 10", "Over off");
    // // Track with same name but different author
    // AudioTrack track4("John McLean", "Call", "Boom", "Jazz", "0 : 03 : 42",
    //                   "2014 - 08 - 23", "Karaoke");

    // // Duplicate track
    // REQUIRE_FALSE(tracksTable.insert(track3.getAudioName(), track3));
    // // Track with same name but different author
    // REQUIRE_FALSE(tracksTable.insert(track4.getAudioName(), track4));

    // Retrieve items and check count
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result =
        hashTable.listItems();
    size_t count = result.first;
    std::pair<std::string, AudioTrack>* items = result.second;

    REQUIRE(count == 4);

    // Check if tracks are present and have correct data
    bool foundTrack1 = false;
    bool foundTrack2 = false;

    AudioTrack* value = hashTable.findTrack("Campaign eye interview");

    if (value->getAudioName() == "Campaign eye interview") {
      foundTrack1 = true;
      REQUIRE(value->getAuthorName() == "Debra Alexander");
      REQUIRE(value->getAudioName() == "Campaign eye interview");
      REQUIRE(value->getAlbumName() == "Social age");
      REQUIRE(value->getGenre() == "Country");
      REQUIRE(value->getDuration() == "0 : 09 : 51");
      REQUIRE(value->getDatePublished() == "2023 - 04 - 14");
      REQUIRE(value->getPlaylist() == "Home");
    }

    value = hashTable.findTrack("Call");

    if (value->getAudioName() == "Call") {
      foundTrack2 = true;
      REQUIRE(value->getAuthorName() == "Lori Brown");
      REQUIRE(value->getAudioName() == "Call");
      REQUIRE(value->getAlbumName() == "Her");
      REQUIRE(value->getGenre() == "Hip Hop");
      REQUIRE(value->getDuration() == "0 : 09 : 45");
      REQUIRE(value->getDatePublished() == "2016 - 10 - 10");
      REQUIRE(value->getPlaylist() == "Over off");
    }

    REQUIRE(foundTrack1);
    REQUIRE(foundTrack2);

    delete[] items;
  }

  SECTION("Deleting Audio Tracks") {
    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(hashTable.insert(track1.getAudioName(), track1));
    REQUIRE(hashTable.insert(track2.getAudioName(), track2));

    std::pair<size_t, std::pair<std::string, AudioTrack>*> result =
        hashTable.listItems();
    size_t count = result.first;
    std::pair<std::string, AudioTrack>* items = result.second;

    REQUIRE(count == 2);

    REQUIRE(hashTable.remove("Call"));  // Removing existing track
    REQUIRE_FALSE(
        hashTable.remove("Nonexistent Track"));  // Removing non-existing track

    result = hashTable.listItems();
    count = result.first;
    items = result.second;

    REQUIRE(count == 1);

    delete[] items;
  }
}