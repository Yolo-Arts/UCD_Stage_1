#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 80
#define MAX_SONGS 12

void update_recently_played(char recentSongs[5][MAX_LENGTH], char *songTitle) {
    for (int k = 4; k > 0; k--) {
        strcpy(recentSongs[k], recentSongs[k - 1]);
    }
    strcpy(recentSongs[0], songTitle);
}

int is_recently_played(char recentSongs[5][MAX_LENGTH], char *songTitle) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(recentSongs[i], songTitle) == 0) {
            return 1;
        }
    }

    return 0;
}

void parallel_swap(char songs[][MAX_LENGTH], char artists[][MAX_LENGTH], int i, int j) {
    char tempArtist[MAX_LENGTH];
    char tempSong[MAX_LENGTH];

    strcpy(tempArtist, artists[i]);
    strcpy(tempSong, songs[i]);

    strcpy(artists[i], artists[j]);
    strcpy(songs[i], songs[j]);

    strcpy(artists[j], tempArtist);
    strcpy(songs[j], tempSong);
}

void shufflePlaylist(char songsList[][MAX_LENGTH], char artistList[][MAX_LENGTH], int numOfSongs) {
    int totalItems = numOfSongs * 2;

    char poolArtists[MAX_SONGS * 2][MAX_LENGTH];
    char poolSongs[MAX_SONGS * 2][MAX_LENGTH];
    int used[MAX_SONGS * 2] = {0};

    char resultsArtists[MAX_SONGS * 2][MAX_LENGTH];
    char resultsSongs[MAX_SONGS * 2][MAX_LENGTH];
    char recentlyPlayed[5][MAX_LENGTH];

    for (int i = 0; i < 5; i++) {
        strcpy(recentlyPlayed[i], "");
    }

    for (int i = 0; i < numOfSongs; i++) {
        strcpy(poolArtists[i], artistList[i]);
        strcpy(poolArtists[i + numOfSongs], artistList[i]);
        strcpy(poolSongs[i], songsList[i]);
        strcpy(poolSongs[i + numOfSongs], songsList[i]);
    }

    for (int i = totalItems - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        parallel_swap(poolSongs, poolArtists, i, j);
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

        strcpy(resultsArtists[i], poolArtists[random_index]);
        strcpy(resultsSongs[i], poolSongs[random_index]);

        update_recently_played(recentlyPlayed, poolSongs[random_index]);
    }

    // INSERT FUNCTION THAT PRINTS OUT THE RESULT SONGS AND RESULT ARTIST ARRAY

}