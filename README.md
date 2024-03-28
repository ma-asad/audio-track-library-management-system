# Audio Track Library Management System

This is a command-line interface (CLI) based application written in C++ for managing an audio track library. The application allows users to perform various operations such as searching, adding, deleting, creating playlists, and listing audio tracks.

## Features

- Search: Users can search for specific audio tracks by title, artist, album, genre, or playlist.
- Add: Users can add new audio tracks to the library by providing the necessary details such as title, artist, album, genre, and a csv file path.
- Delete: Users can delete existing audio tracks from the library based on their unique identifier.
- Create Playlist: Users can create playlists by selecting multiple audio tracks from the library.
- List Audio: Users can view a list of all the audio tracks and their details in the library.

## Usage

1. Clone the repository:

https: 
```bash
git clone https://github.com/ma-asad/audio-track-library-management-system.git
```

ssh: 
```bash
git clone git@github.com:ma-asad/audio-track-library-management-system.git
```

2. Build the application using the provided Makefile:

```bash
make
```

3. Run the application:

```bash
make run
```

4. To clean the build artifacts (object files and executable):

```bash
make clean
```

5. Follow the on-screen instructions to navigate through the menu and perform various operations.

## Dependencies

This application has the following dependencies:

- C++ compiler (e.g., g++)
- Standard Template Library (STL)

