#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 80
#define MAX_TOTAL_SONGS 12

void updateRecentlyPlayed(char recentSongs[5][MAX_LENGTH], char *newSong) {
    for (int k = 4; k > 0; k--) {
        strcpy(recentSongs[k], recentSongs[k - 1]);
    }
    strcpy(recentSongs[0], newSong);
}


int isSongRecentlyPlayed(char recentSongs[5][MAX_LENGTH], char *songTitle) {
    for (int index = 0; index < 5; index++) {
        if (strcmp(songTitle, recentSongs[index]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Fisher Yates shuffle.
void swapParallel(char artists[][MAX_LENGTH], char songs[][MAX_LENGTH], int i, int j) {
    char tempArtist[MAX_LENGTH];
    char tempSong[MAX_LENGTH];

    strcpy(tempArtist, artists[i]);
    strcpy(tempSong, songs[i]);

    strcpy(artists[i], artists[j]);
    strcpy(songs[i], songs[j]);

    strcpy(artists[j], tempArtist);
    strcpy(songs[j], tempSong);
}


void shufflePlaylist(char artists[][MAX_LENGTH], char songs[][MAX_LENGTH], int numOfSongs) {
    int totalItems = numOfSongs * 2;

    // the selection of artists and songs.
    char poolArtists[MAX_TOTAL_SONGS * 2][MAX_LENGTH];
    char poolSongs[MAX_TOTAL_SONGS * 2][MAX_LENGTH];
    int used[MAX_TOTAL_SONGS * 2] = {0};

    // the arrays of artists and songs that will be printed to console.
    char resultArtists[MAX_TOTAL_SONGS * 2][MAX_LENGTH];
    char resultSongs[MAX_TOTAL_SONGS * 2][MAX_LENGTH];

    // fills recentlyPlayed with empty strings.
    char recentlyPlayed[5][MAX_LENGTH];
    for (int i = 0; i < 5; i++)  {
        strcpy(recentlyPlayed[i], "");
    }


    // populates the selection of artists and songs.
    for (int i = 0; i < numOfSongs; i++) {
        strcpy(poolArtists[i], artists[i]);
        strcpy(poolSongs[i], songs[i]);
        strcpy(poolArtists[i + numOfSongs], artists[i]);
        strcpy(poolSongs[i + numOfSongs], songs[i]);
    }

    // Fisher Yates Shuffling the pool:
    for (int i = totalItems - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swapParallel(poolArtists, poolSongs, i, j);
    }

    // fills the resultArtists and resultSongs array and ensures 5 song gap.
    for (int i = 0; i < totalItems; i++) {
        int foundValidSong = 0;
        int randomIndex;

        while (foundValidSong == 0) {
            randomIndex = rand() % totalItems;

            if (used[randomIndex] == 0) {
                // Check if song is recentlyPlayed in the last 5 songs with the helper function.
                if (isSongRecentlyPlayed(recentlyPlayed, poolSongs[randomIndex]) == 0) {
                    foundValidSong = 1;
                }
            }
        }

        // if an index in the 'used' array is 1, it has been played and won't be played again.
        used[randomIndex] = 1;

        // adds the song to the results.
        strcpy(resultArtists[i], poolArtists[randomIndex]);
        strcpy(resultSongs[i], poolSongs[randomIndex]);

        // adds new song to the recentlyPlayed, shifts all existing songs by one.
        updateRecentlyPlayed(recentlyPlayed, resultSongs[i]);
    }

    printf("\nShuffled Playlist:\n");

    for (int i = 0; i < totalItems; i++) {
        printf("%d. %s - %s\n", i + 1, resultArtists[i], resultSongs[i]);
    }
}



int main(void) {
    char songs[MAX_TOTAL_SONGS][MAX_LENGTH];
    char artists[MAX_TOTAL_SONGS][MAX_LENGTH];
    int numOfSongs;

    shufflePlaylist(artists, songs, numOfSongs);

    return 0;
}
