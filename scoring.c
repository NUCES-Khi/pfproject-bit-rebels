
#include<stdio.h>
int main() {
   

    while (level > 0 && level < 4) {
        
        printf("Get ready to play! Enter 'yes' to begin: ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, compare) == 0) {
            printf("\nEnter level to proceed with the game: ");
            scanf(" %d", &level);
            if (level > 3) {
                printf("Invalid input. Please enter a valid level.\n");
                while (getchar() != '\n');
            }

            while (getchar() != '\n');

            if (level == 0) {
                printf("\nExiting the game. Goodbye!\n");
                break;
            }

            int result = checkEnteredLetter("easy.txt", "checkeasy.txt");
            if (result == 1) {
                gamesWon++;
                printf("You won! Your current score: %d\n", gamesWon);
            } else {
                printf("You lost! Your current score: %d\n", gamesWon);
            }

            result = checkEnteredLetter("medium.txt", "checkmedium.txt");
            if (result == 1) {
                gamesWon++;
                printf("You won! Your current score: %d\n", gamesWon);
            } else {
                printf("You lost! Your current score: %d\n", gamesWon);
            }

            result = checkEnteredLetter("hard.txt", "checkhard.txt");
            if (result == 1) {
                gamesWon++;
                printf("You won! Your current score: %d\n", gamesWon);
            } else {
                printf("You lost! Your current score: %d\n", gamesWon);
            }
        }
    }

    printf("\nGames won: %d\n", gamesWon);

    return 0;
}
