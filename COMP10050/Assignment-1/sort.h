//max number of songs
#define MAX_SONGS_PER_ARTIST 3
//max length of each song
#define MAX_LENGHT 80
#define MAX_ARTISTS 4
#define MAX_TOTAL_SONGS 12

/*
 * This function sorts the songs provided as input alphabetically
 *
 * Inputs:
 *   char songs[][MAX_LENGHT]: The songs to be sorted
 *   int numOfSongs: the number of songs to be sorted
 *
 */
void sortSongs(char artists[][MAX_LENGHT], char songs[][MAX_LENGHT], int numOfSongs);
