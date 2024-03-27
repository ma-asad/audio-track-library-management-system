# Audio Track Library Management System

This is a command-line interface (CLI) based application written in C++ for managing an audio track library. The application allows users to perform various operations such as searching, adding, deleting, creating playlists or albums, and listing music tracks.

## Features

- Search: Users can search for specific audio tracks by title, artist, album, or genre.
- Add: Users can add new audio tracks to the library by providing the necessary details such as title, artist, album, genre, and file path.
- Delete: Users can delete existing audio tracks from the library based on their unique identifier.
- Create Playlist or Album: Users can create playlists or albums by selecting multiple audio tracks from the library.
- List Music: Users can view a list of all the audio tracks in the library.

## Usage

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/audio-track-library-management-system.git
    ```

2. Navigate to the project directory:

    ```bash
    cd audio-track-library-management-system
    ```

3. Build the application using the provided Makefile:

    ```bash
    make
    ```

4. Run the application with the desired audio file:
    ```bash
    ./audio-library.exe filename
    ```

5. Run the make clean command for cleaning up the project
    ```bash
    make clean
    ```

6. Follow the on-screen instructions to navigate through the menu and perform various operations.

## Dependencies

This application has the following dependencies:

- C++ compiler (e.g., g++)
- Standard Template Library (STL)