#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>

#include "audiotrack.hpp"
#include "catch.hpp"
#include "hashtable.hpp"
#include "validation.hpp"

// Assuming AudioTrack class has relevant constructors and getters/setters

TEST_CASE("Adding and Deleting Audio Tracks in HashTable") {
  HashTable<std::string, AudioTrack> hashTable;

  SECTION("Adding Audio Tracks") {
    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");
    // Duplicate track
    AudioTrack track3("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");
    // Track with same name but different author
    AudioTrack track4("John McLean", "Call", "Boom", "Jazz", "0 : 03 : 42",
                      "2014 - 08 - 23", "Karaoke");

    REQUIRE(hashTable.insert(track1.getAudioName(), track1));
    REQUIRE(hashTable.insert(track2.getAudioName(), track2));
    // Duplicate track
    REQUIRE_FALSE(hashTable.insert(track3.getAudioName(), track3));
    // Track with same name but different author
    REQUIRE_FALSE(hashTable.insert(track4.getAudioName(), track4));

    // Retrieve items and check count
    std::pair<std::string, AudioTrack>* items;
    size_t count;
    hashTable.getItems(items, count);

    REQUIRE(count == 4);

    // Check if tracks are present and have correct data
    bool foundTrack1 = false;
    bool foundTrack2 = false;

    if (items[0].second.getAudioName() == "Campaign eye interview") {
      foundTrack1 = true;
      REQUIRE(items[0].second.getAuthorName() == "Debra Alexander");
      REQUIRE(items[0].second.getAudioName() == "Campaign eye interview");
      REQUIRE(items[0].second.getAlbumName() == "Social age");
      REQUIRE(items[0].second.getGenre() == "Country");
      REQUIRE(items[0].second.getDuration() == "0 : 09 : 51");
      REQUIRE(items[0].second.getDatePublished() == "2023 - 04 - 14");
      REQUIRE(items[0].second.getPlaylist() == "Home");
    }

    if (items[1].second.getAudioName() == "Call") {
      foundTrack2 = true;
      REQUIRE(items[1].second.getAuthorName() == "Lori Brown");
      REQUIRE(items[1].second.getAudioName() == "Call");
      REQUIRE(items[1].second.getAlbumName() == "Her");
      REQUIRE(items[1].second.getGenre() == "Hip Hop");
      REQUIRE(items[1].second.getDuration() == "0 : 09 : 45");
      REQUIRE(items[1].second.getDatePublished() == "2016 - 10 - 10");
      REQUIRE(items[1].second.getPlaylist() == "Over off");
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

    std::pair<std::string, AudioTrack>* items;
    size_t count;
    hashTable.getItems(items, count);

    REQUIRE(count == 2);

    REQUIRE(hashTable.remove("Call"));  // Removing existing track
    REQUIRE_FALSE(
        hashTable.remove("Nonexistent Track"));  // Removing non-existing track

    hashTable.getItems(items, count);

    REQUIRE(count == 1);

    delete[] items;
  }
}