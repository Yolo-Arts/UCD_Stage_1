#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 80
#define MAX_SONGS 12

int is_recently_played(char recentlyPlayed[][MAX_LENGTH], char *songTitle) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(recentlyPlayed[i], songTitle) == 0) {
            return 1;
        }
    }
    return 0;
}

void update_recently_played(char recentlyPlayed[][MAX_LENGTH], char *songTitle) {
    for (int k = 4; k > 0; k--) {
        strcpy(recentlyPlayed[k], recentlyPlayed[k - 1]);
    }
    strcpy(recentlyPlayed[0], songTitle);
}

void parallelSwap(char artistList[][MAX_LENGTH], char songList[][MAX_LENGTH], int i, int j) {
    char tempArtist[MAX_LENGTH];
    char tempSong[MAX_LENGTH];

    strcpy(tempArtist, artistList[i]);
    strcpy(tempSong, songList[i]);

    strcpy(artistList[i], artistList[j]);
    strcpy(songList[i], songList[j]);

    strcpy(songList[j], tempSong);
    strcpy(artistList[j], tempArtist);
}

void shufflePlaylist(char artistList[][MAX_LENGTH], char songList[][MAX_LENGTH], int numOfSongs) {
    int totalItems = numOfSongs * 2;

    char poolArtists[MAX_SONGS * 2][MAX_LENGTH];
    char poolSongs[MAX_SONGS * 2][MAX_LENGTH];
    int used[MAX_SONGS * 2] = {0};

    char resultArtists[MAX_SONGS * 2][MAX_LENGTH];
    char resultSongs[MAX_SONGS * 2][MAX_LENGTH];
    char recentlyPlayed[5][MAX_LENGTH];

    for (int i = 0; i < 5; i++) {
        strcpy(recentlyPlayed[i], "");
    }

    for (int i = 0; i < numOfSongs; i++) {
        strcpy(poolArtists[i], artistList[i]);
        strcpy(poolArtists[i + numOfSongs], artistList[i]);
        strcpy(poolSongs[i], songList[i]);
        strcpy(poolSongs[i + numOfSongs], songList[i]);
    }

    for (int i = totalItems - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        parallelSwap(poolArtists, poolSongs, i, j);
    }

    for (int i = 0; i < totalItems; i++) {
        int random_index = 0;
        int valid_index = 0;

        while (valid_index == 0) {
            random_index = rand() % totalItems;

            if (used[random_index] == 0) {
                if (is_recently_played(recentlyPlayed, poolSongs[random_index]) == 0) {
                    valid_index = 1;
                }
            }

        }
        used[random_index] = 1;

        strcpy(resultArtists[i], poolArtists[random_index]);
        strcpy(resultSongs[i], poolSongs[random_index]);

        update_recently_played(recentlyPlayed, poolSongs[random_index]);
    }

    // helper function that prints out resultArtists array and resultSongs array.
}