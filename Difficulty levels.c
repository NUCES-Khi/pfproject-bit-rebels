#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 100

// Function to choose a random word based on difficulty level from a file
void takeWordFromFile(char *word, int difficulty) {
    FILE *file = fopen("/Users/urooj/Desktop/hangman.txt", "r");//read the file which 
    //difficulty levels and the words of each level
    if (file == NULL) {
        printf("File does not exists.\n");
        exit(EXIT_FAILURE);
    }

    char line[100];
    char *token;

    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, ":");
        int currentDifficulty = atoi(token);

        if (currentDifficulty == difficulty) {
            token = strtok(NULL, " \n");

            // Tokenize the words using space as a delimiter
            char *words[MAX_WORD_LENGTH];
            int count = 0;
            while (token != NULL) {
                words[count++] = token;
                token = strtok(NULL, " \n");
            }

            // code for to select the words randomly according to user given difficulty level
            if (count > 0) {
                int randomIndex = rand() % count;
                strcpy(word, words[randomIndex]);
            } else {
                printf("No words found for difficulty level %d.\n", difficulty);
                exit(EXIT_FAILURE);
            }

            break;
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    char word[MAX_WORD_LENGTH];
    int difficulty, incorrectAttempts = 0;
    printf("\n");

    printf("***************   WELCOME TO HANGMAN  **************\n");
    printf("\n");
    printf("Choose the difficulty level\n");
    printf("1:Easy\n");
    printf("2:Medium\n");
    printf("3:Hard\n");
    printf("\n");
    printf("Press 1 for EASY, 2 for MEDIUM, and 3 for Hard:\n");
    printf("\n");
    scanf("%d", &difficulty);

    takeWordFromFile(word, difficulty);

    printf("\n");

    printf("Here you go, guess the word: %s\n", word);

    return 0;
}
