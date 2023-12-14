#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20

// Function to choose a random word based on difficulty level from a file
void chooseWordFromFile(char *word, int difficulty) {
    FILE *file = fopen("hangman.rtf", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(EXIT_FAILURE);
    }

    char line[100];
    char *token;

    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, ":");
        int currentDifficulty = atoi(token);

        if (currentDifficulty == difficulty) {
            token = strtok(NULL, " \n");
            strcpy(word, token);
            break;
        }
    }

    fclose(file);
}

int main() {
    char word[MAX_WORD_LENGTH];
    char guessedLetters[MAX_WORD_LENGTH] = "";
    int difficulty, incorrectAttempts = 0;
;
    
    printf("Select difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    scanf("%d", &difficulty);

    chooseWordFromFile(word, difficulty);

    return 0;
}
