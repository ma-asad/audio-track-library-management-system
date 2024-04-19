#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>

#include "audio-track.hpp"
#include "catch.hpp"
#include "audio-library.hpp"
#include "hash-table.hpp"

// Assuming AudioTrack class has relevant constructors and getters/setters

TEST_CASE("Adding and Deleting Audio Tracks in HashTable") {
  AudioLibrary library;

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

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));
    REQUIRE_FALSE(library.addTrackToHashTables(track3));
    REQUIRE(library.addTrackToHashTables(track4));

    // Retrieve items and check count
    // Get count and items for tracksTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result1 =
        library.getTracksTable().listItems();
    size_t tracksCount = result1.first;
    std::pair<std::string, AudioTrack>* tracksItems = result1.second;

    // Get count and items for artistTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result2 =
        library.getArtistTable().listItems();
    size_t artistCount = result2.first;
    std::pair<std::string, AudioTrack>* artistItems = result2.second;

    // Get count and items for albumNameTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result3 =
        library.getAlbumNameTable().listItems();
    size_t albumCount = result3.first;
    std::pair<std::string, AudioTrack>* albumItems = result3.second;

    // Get count and items for genreTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result4 =
        library.getGenreTable().listItems();
    size_t genreCount = result4.first;
    std::pair<std::string, AudioTrack>* genreItems = result4.second;

    // Get count and items for playlistTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result5 =
        library.getPlaylistTable().listItems();
    size_t playlistCount = result5.first;
    std::pair<std::string, AudioTrack>* playlistItems = result5.second;

    REQUIRE(tracksCount == 3);
    REQUIRE(artistCount == 3);
    REQUIRE(albumCount == 3);
    REQUIRE(genreCount == 3);
    REQUIRE(playlistCount == 3);

    AudioTrack* value1 = library.getTracksTable().findTrack("Campaign eye interview");
    AudioTrack* value2 = library.getArtistTable().findTrack("Debra Alexander");
    AudioTrack* value3 = library.getAlbumNameTable().findTrack("Social age");
    AudioTrack* value4 = library.getGenreTable().findTrack("Country");
    AudioTrack* value5 = library.getPlaylistTable().findTrack("Home");

    REQUIRE(value1 != nullptr);
    REQUIRE(value2 != nullptr);
    REQUIRE(value3 != nullptr);
    REQUIRE(value4 != nullptr);
    REQUIRE(value5 != nullptr);

    REQUIRE(value1->getAudioName() == value2->getAudioName());
    REQUIRE(value1->getAudioName() == value3->getAudioName());
    REQUIRE(value1->getAudioName() == value4->getAudioName());
    REQUIRE(value1->getAudioName() == value5->getAudioName());

    REQUIRE(value1->getAuthorName() == value2->getAuthorName());
    REQUIRE(value1->getAuthorName() == value3->getAuthorName());
    REQUIRE(value1->getAuthorName() == value4->getAuthorName());
    REQUIRE(value1->getAuthorName() == value5->getAuthorName());

    REQUIRE(value1->getAlbumName() == value2->getAlbumName());
    REQUIRE(value1->getAlbumName() == value3->getAlbumName());
    REQUIRE(value1->getAlbumName() == value4->getAlbumName());
    REQUIRE(value1->getAlbumName() == value5->getAlbumName());

    REQUIRE(value1->getGenre() == value2->getGenre());
    REQUIRE(value1->getGenre() == value3->getGenre());
    REQUIRE(value1->getGenre() == value4->getGenre());
    REQUIRE(value1->getGenre() == value5->getGenre());

    REQUIRE(value1->getPlaylist() == value2->getPlaylist());
    REQUIRE(value1->getPlaylist() == value3->getPlaylist());
    REQUIRE(value1->getPlaylist() == value4->getPlaylist());
    REQUIRE(value1->getPlaylist() == value5->getPlaylist());

    delete[] tracksItems;
    delete[] artistItems;
    delete[] albumItems;
    delete[] genreItems;
    delete[] playlistItems;
  }

  SECTION("Deleting Audio Tracks") {
    AudioTrack track1("Debra Alexander", "Campaign eye interview", "Social age",
                      "Country", "0 : 09 : 51", "2023 - 04 - 14", "Home");
    AudioTrack track2("Lori Brown", "Call", "Her", "Hip Hop", "0 : 09 : 45",
                      "2016 - 10 - 10", "Over off");

    REQUIRE(library.addTrackToHashTables(track1));
    REQUIRE(library.addTrackToHashTables(track2));

    // Retrieve items and check count
    // Get count and items for tracksTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result1 =
        library.getTracksTable().listItems();
    size_t tracksCount = result1.first;
    std::pair<std::string, AudioTrack>* tracksItems = result1.second;

    // Get count and items for artistTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result2 =
        library.getArtistTable().listItems();
    size_t artistCount = result2.first;
    std::pair<std::string, AudioTrack>* artistItems = result2.second;

    // Get count and items for albumNameTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result3 =
        library.getAlbumNameTable().listItems();
    size_t albumCount = result3.first;
    std::pair<std::string, AudioTrack>* albumItems = result3.second;

    // Get count and items for genreTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result4 =
        library.getGenreTable().listItems();
    size_t genreCount = result4.first;
    std::pair<std::string, AudioTrack>* genreItems = result4.second;

    // Get count and items for playlistTable
    std::pair<size_t, std::pair<std::string, AudioTrack>*> result5 =
        library.getPlaylistTable().listItems();
    size_t playlistCount = result5.first;
    std::pair<std::string, AudioTrack>* playlistItems = result5.second;

    REQUIRE(tracksCount == 2);
    REQUIRE(artistCount == 2);
    REQUIRE(albumCount == 2);
    REQUIRE(genreCount == 2);
    REQUIRE(playlistCount == 2);

    REQUIRE(library.deleteTrackFromTable("Call"));  // Removing existing track
    REQUIRE_FALSE(
        library.deleteTrackFromTable("Nonexistent Track"));  // Removing non-existing track

    result1 = library.getTracksTable().listItems();
    tracksCount = result1.first;
    tracksItems = result1.second;

    result2 = library.getArtistTable().listItems();
    artistCount = result2.first;
    artistItems = result2.second;

    result3 = library.getAlbumNameTable().listItems();
    albumCount = result3.first;
    albumItems = result3.second;

    result4 = library.getGenreTable().listItems();
    genreCount = result4.first;
    genreItems = result4.second;

    result5 = library.getPlaylistTable().listItems();
    playlistCount = result5.first;
    playlistItems = result5.second;

    REQUIRE(tracksCount == 1);
    REQUIRE(artistCount == 1);
    REQUIRE(albumCount == 1);
    REQUIRE(genreCount == 1);
    REQUIRE(playlistCount == 1);

    delete[] tracksItems;
    delete[] artistItems;
    delete[] albumItems;
    delete[] genreItems;
    delete[] playlistItems;
  }
}