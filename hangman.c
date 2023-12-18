#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>



#define MAX_LENGTH 100
#define MAX_WORDS 50

void clearConsole() {
    printf("\033[2J\033[H");
}

//Declaring a structure
typedef struct {
    int randomIndex;
    char words[MAX_WORDS][MAX_LENGTH];
} WordData;

    
// Function to choose a random word from a file
WordData takeWordFromFile(char *filename) {
    WordData result = { -1, {""} };
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File does not exist.\n");
        //return NULL;
    }

    int wordCount = 0;
    char line[MAX_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL && wordCount < MAX_WORDS) {
        line[strcspn(line, "\n")] = '\0'; //Remove newline character
        strcpy(result.words[wordCount], line);
        wordCount++;
    }
    fclose(file);

    if (wordCount > 0) {
        result.randomIndex = rand() % wordCount;
        if (result.randomIndex >= 0 && result.randomIndex < wordCount) {
            printf("Word to guess is:\n%s\n", result.words[result.randomIndex]);
	    //printf("Actual actual random is : %d", result.randomIndex);
        }
    }

    return result;
}

void takeCorrectWordFromAnotherFile(char *filename, char words[MAX_WORDS][MAX_LENGTH]){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File does not exist.\n");
        //return NULL;
    }

    int wordCount = 0;
    char line[MAX_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL && wordCount < 44) {
        line[strcspn(line, "\n")] = '\0'; //Remove newline character
	 //printf("Word %d: %s\n", wordCount, line); // Print the word being read
        strcpy(words[wordCount], line);
        wordCount++;
    }
    fclose(file);
}


void printHangman(int mistakes) {
    switch (mistakes) {
        case 6:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        O\n");
            printf("  |       /|\\\n");
            printf("  |       / \\\n");
            printf("__|__\n");
            break;
        case 5:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        O\n");
            printf("  |       /|\\\n");
            printf("  |       /\n");
            printf("__|__\n");
            break;
        case 4:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        0\n");
            printf("  |       /|\\\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 3:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        O\n");
            printf("  |       /|\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 2:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        0\n");
            printf("  |        |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 1:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        O\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
	case 0:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        default:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
    }
}

void checkEnteredLetter(char *filename1, char*filename2){
   	int chances = 6, mistake = 0;
    	int index = 0;
	int found, repeatFlag;
    	char wrongLetters[MAX_LENGTH];
  
	WordData wordData = takeWordFromFile(filename1);
		int random = wordData.randomIndex;
		char guessWord[50];
                strcpy(guessWord, wordData.words[random]); //guessWord is the word with missing letters
		char checkWordData[MAX_WORDS][MAX_LENGTH];
		takeCorrectWordFromAnotherFile(filename2, checkWordData);
                char actualWord[30];
		strcpy(actualWord, checkWordData[random]);//actualWord is the same word but with complete letters
		
		//printf("\nActual Word is : %s", actualWord);

		char letter;
		while (chances > 0 && chances < 7){
			printf("\nEnter letter: ");
			scanf(" %c", &letter);
			system("cls");
			found = 0;
			repeatFlag = 0;
			int j = 0;
			for (j; j < strlen(actualWord); ++j){
				if (actualWord[j] == letter && guessWord[j] == '_'){
					guessWord[j] = letter;
					found = 1;
				}
			}
			
			j= 0;
			for (j; j < index; ++j){
				if (wrongLetters[j] == letter) 
					repeatFlag = 1;
			}

		printf("\nCurrent status: %s\n", guessWord);

               		 //checking mistakes so that hangman can be drawn accordingly
                	 if(found == 0 && repeatFlag == 0) {
                    	 	wrongLetters[index] = letter;
                    		++mistake;
                    		--chances;
                    		++index;
                    		printf("Entered wrong letters are: ");
                    		int i = 0;
                    		for(i; i < index; ++i){
                        		printf(" %c ", wrongLetters[i]);
                    		  }
                    		printf("\nRemaining chances are : %d\n", chances);
                    		printHangman(mistake);
                    		
				if(strcmp(actualWord, guessWord) == 0){
                    		printf("\n\nCONGRATULATION! YOU WON THE GAME!\n\n");
                    		break;
                    	 }		
	
                	}// end found
        
                	else{
                    	printf("Entered wrong letters are: ");
                    	int i = 0;
                    	for(i; i < index; ++i){
                        	printf("%c ", wrongLetters[i]);
                    	}
                    	printf("\nRemaining chances are : %d\n", chances);
                    	printHangman(mistake);
                    	//system("cls");
			if(strcmp(actualWord, guessWord) == 0){
                    		printf("\n\nCONGRATULATION! YOU WON THE GAME!\n\n");
                    		//system("cls");
		    		//clearConsole();
                    		break;
                    	 }			

		  	}
			
			
		}
            
                	//declaring game over
                	if(chances == 0) 
                	printf("\n\nGAME OVER! YOU LOST!\n");
		   	printf("\nThe word was : %s\n", actualWord);
			//break;
}



int main(){
    int choice;
    char input[4];
    char compare[] = "yes";
    int level = 1;
 
    srand(time(NULL));
    system("cls");
    //clearConsole();

    
    printf("\n");
    printf("      _   _                                          \n");
    printf("     | | | |                                         \n");
    printf("     | |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __   \n");
    printf("     |  _  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\  \n");
    printf("     | | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
    printf("     \\_| |_/\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("                          __/ |                      \n");
    printf("                         |___/                       \n");

    printf("      -------\n");
    printf("      |     |\n");
    printf("      |     @\n");
    printf("      |    /|\\\n");
    printf("      |     |\n");
    printf("      |    / \\\n");
    printf(" _____|_________\n");
    printf("/     |         /|\n");
    printf("______________ / /\n");
    printf("             |  /\n");
    printf("______________ /\n");


printf("\n\n---------- WELCOME TO HANGMAN GAME ----------\n\n");
printf("Instructions:\n\n");
printf("* A word will be displayed with missing letters. Your goal is to guess the missing letters.\n");
printf("* All letters are in lowercase.\n");
printf("* You have 6 chances to guess the missing letters correctly. If the hangman figure is completely drawn, you lose.\n");
printf("* Press 0 to exit the game.\n");
printf("              OR \n");
printf("* Enter 'yes' to begin the game.\n\n");
	
while(level > 0 && level < 4){
	fgets(input, sizeof(input), stdin);
        if (strcmp(input, compare) == 0 || choice == 1) {
			printf("\n* Choose a level:\n");
			printf("    - Enter 1 for Easy\n");
			printf("    - Enter 2 for Medium\n");
			printf("    - Enter 3 for Hard\n");
			scanf(" %d", &level);
			if (level > 3) {
                printf("Invalid input. Please enter a valid level.\n");
                while (getchar() != '\n'); // Clear input buffer
                //continue; // Go back to the beginning of the loop
	        }
		
	     	while (getchar() != '\n');
 			if(level == 0){
				printf("\nExiting the game. Goodbye!\n");
			 	return 0;
			}
	
            if(level == 1){
				checkEnteredLetter("easy.txt", "checkeasy.txt");
		            }

            if(level == 2){
                 checkEnteredLetter("medium.txt", "checkmedium.txt");
            }

            if(level == 3){
		 		checkEnteredLetter("hard.txt", "checkhard.txt");
            }
        } 
        
        else{
        	printf("\nExiting the Game!\n\n");
        	return 0;
		}
		
        printf("\nPress 0 to exit.\n");
 		printf("\nPress 1 to continue.\n\n");
 		scanf("%d", &choice); 
 		if(choice == 0){
			return 0;
   		}
 		else continue;	

   }//end of while loop
    
}
   		
		
		
