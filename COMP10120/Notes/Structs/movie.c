#include <stdio.h>

typedef struct {
    char title[100];
    int releaseYear;
    float rating;
} Movie;

// This function takes a POINTER to a Movie
void getMovieInput(Movie *m) {
    printf("Enter movie title (no spaces): ");
    // title is an array, so 'm->title' is already an address. No & needed!
    scanf("%s", m->title);

    printf("Enter release year: ");
    // releaseYear is an int, so we need & to get its address
    // 'm->releaseYear' finds the variable, '&' gets the address for scanf
    scanf("%d", &m->releaseYear);

    printf("Enter rating (0.0 - 10.0): ");
    scanf("%f", &m->rating);
}

int main() {
    Movie myMovie; // Declare an empty movie struct

    printf("--- Movie Input System ---\n");

    // We pass the ADDRESS of myMovie using '&'
    getMovieInput(&myMovie);

    printf("\n--- Movie Saved ---\n");
    printf("Title: %s\n", myMovie.title);
    printf("Year:  %d\n", myMovie.releaseYear);
    printf("Score: %.1f/10\n", myMovie.rating);

    return 0;
}