#include "audiotrack.h"


/*
    audioTrack.cpp
    Authors: M00851681,
    Created: 
    Updated: 
*/

// Constructor

AudioTrack::AudioTrack() 
{

}

AudioTrack::AudioTrack(const std::string authorName, 
                        const std::string audioName,
                        const std::string albumName,
                        const std::string genre,
                        const std::string duration,
                        const std::string datePublished,
                        const std::string playlist)
{
    this->authorName = authorName;
    this->audioName = audioName;
    this->albumName = albumName;
    this->genre = genre;
    this->duration = duration;
    this->datePublished = datePublished;
    this->playlist = playlist;
}

// Getter methods
std::string AudioTrack::getAuthorName() const
{
    return this->authorName;
}

std::string AudioTrack::getAudioName() const
{
    return this->audioName;
}

std::string AudioTrack::getAlbumName() const
{
    return this->albumName;
}

std::string AudioTrack::getGenre() const
{
    return this->genre;
}

std::string AudioTrack::getDuration() const
{
    return this->duration;
}

std::string AudioTrack::getDatePublished() const
{
    return this->datePublished;
}

std::string AudioTrack::getPlaylist() const
{
    return this->playlist;
}