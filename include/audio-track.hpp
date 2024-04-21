#ifndef _AUDIOTRACK_H
#define _AUDIOTRACK_H

#include <sstream>

/**
 * @class AudioTrack
 * @brief Represents an audio track with various properties such as author name,
 * audio name, album name, genre, duration, date published, and playlist.
 */
class AudioTrack {
 private:
  std::string authorName;
  std::string audioName;
  std::string albumName;
  std::string genre;
  std::string duration;
  std::string datePublished;
  std::string playlist;

  /**
   * @brief Overloaded equality operator for comparing two AudioTrack objects.
   *
   * @param lhs The left-hand side AudioTrack object to compare.
   * @param rhs The right-hand side AudioTrack object to compare.
   * @return true if the two AudioTrack objects are equal, false otherwise.
   */
  friend bool operator==(const AudioTrack& lhs, const AudioTrack& rhs);

 public:
  /**
   * @brief Default constructor for the AudioTrack class.
   */
  AudioTrack();

  /**
   * @brief Constructor for the AudioTrack class.
   * @param authorName The name of the author of the audio track.
   * @param audioName The name of the audio track.
   * @param albumName The name of the album the audio track belongs to.
   * @param genre The genre of the audio track.
   * @param duration The duration of the audio track.
   * @param datePublished The date the audio track was published.
   * @param playlist The playlist the audio track belongs to.
   */
  AudioTrack(const std::string authorName, const std::string audioName,
             const std::string albumName, const std::string genre,
             const std::string duration, const std::string datePublished,
             const std::string playlist);

  /**
   * @brief Destructor for the AudioTrack class.
   *
   * This destructor is responsible for cleaning up any resources
   * allocated by an AudioTrack object.
   */
  ~AudioTrack();

  /**
   * @brief Retrieves the name of the author of the audio track.
   *
   * @return The name of the author as a std::string.
   */
  std::string getAuthorName() const;

  /**
   * @brief Returns the name of the audio track.
   *
   * @return std::string The name of the audio track.
   */
  std::string getAudioName() const;

  /**
   * @brief Returns the album name of the audio track.
   *
   * @return The album name as a std::string.
   */
  std::string getAlbumName() const;

  /**
   * @brief Gets the genre of the audio track.
   *
   * @return The genre of the audio track as a string.
   */
  std::string getGenre() const;

  /**
   * @brief Gets the duration of the audio track.
   *
   * @return The duration of the audio track as a string.
   */
  std::string getDuration() const;

  /**
   * @brief Gets the date when the audio track was published.
   *
   * @return The date when the audio track was published as a string.
   */
  std::string getDatePublished() const;

  /**
   * @brief Retrieves the playlist associated with the audio track.
   *
   * @return The playlist of the audio track.
   */
  std::string getPlaylist() const;
};

#endif