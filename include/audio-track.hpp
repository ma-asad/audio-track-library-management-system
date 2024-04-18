#ifndef AUDIOTRACK_H
#define AUDIOTRACK_H

#include <string>

/*
    audiotrack.hpp
    Created:
    Updated:
*/

/**
 * @class AudioTrack
 * @brief Represents an audio track with its associated metadata.
 */

class AudioTrack {
 private:
  // Member datas
  std::string authorName;
  std::string audioName;
  std::string albumName;
  std::string genre;
  std::string duration;
  std::string datePublished;
  std::string playlist;
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

  std::string getAuthorName() const;
  std::string getAudioName() const;
  std::string getAlbumName() const;
  std::string getGenre() const;
  std::string getDuration() const;
  std::string getDatePublished() const;
  std::string getPlaylist() const;
};
#endif