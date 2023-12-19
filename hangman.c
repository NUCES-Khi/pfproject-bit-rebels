/*
 * Creator of this file: Amna(23K-0066)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAX_LENGTH 100
#define MAX_WORDS 100


//Declaring a structure
typedef struct {
    int randomIndex;
    char words[MAX_WORDS][MAX_LENGTH];
} WordData;

    
// Function to choose a random word from a file
WordData takeWordFromFile(char *filename) {  //This fucntion was originally writen by Urroj. I modified it.
    WordData result = { -1, {""} };
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File does not exist.\n");
        return NULL;
    }

    int wordCount = 0;
    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL && wordCount < MAX_WORDS) {
        line[strcspn(line, "\n")] = '\0'; //Remove newline character
        strcpy(result.words[wordCount], line);
        wordCount++;
    }
    fclose(file);
    if (wordCount > 0) result.randomIndex = rand() % wordCount;
    return result;
}//end of function takeWordFromFil


//function of printing hangman figure
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
}//end of function printHangman

//function to check the user attempt
void checkEnteredLetter(char *filename, int level){
   	int chances = 6, mistake = 0, counter = 0;
    	int index = 0;
	int found, repeatFlag;
    	char wrongLetters[MAX_LENGTH];
  
	WordData wordData = takeWordFromFile(filename);
		int random = wordData.randomIndex;
                char actualWord[30];
		char guessWord[30];
		strcpy(actualWord, wordData.words[random]);	
		strcpy(guessWord, actualWord);
		int wordSize = strlen(actualWord);

		//Adding underscores randomly in the selected word
		while (counter < 5){
			int randomIndex = rand() % wordSize;
			if (guessWord[randomIndex] != ' '){
				guessWord[randomIndex] = '_';
				++counter;
			}
		}

		//printing the modifed selected word
		printf("Word to guess: %s", guessWord);
		char letter;
		while (chances > 0 && chances < 7){
		    printf("\nEnter letter: ");
		    scanf(" %c", &letter);
		    system("cls");
		    found = 0;
		    repeatFlag = 0;
		    for (int j = 0; j < strlen(actualWord); ++j){
			if (actualWord[j] == letter && guessWord[j] == '_'){
			      guessWord[j] = letter;
			      found = 1;
			} //end of if statement
			    
		    }//end of checking the user input

		    //storing wrong attempts of user in a 1D array
		    for (int j = 0; j < index; ++j){
			if (wrongLetters[j] == letter) 
				repeatFlag = 1;
		     }// end of for loop

		printf("\nCurrent status: %s\n", guessWord);

               	 //checking mistakes so that hangman can be drawn accordingly
                 if(found == 0 && repeatFlag == 0) {
                        wrongLetters[index] = letter;
                    	++mistake;
                    	--chances;
                    	++index;

			 //printing wrong letters
                    	printf("Entered wrong letters are: ");
                    	for(int i = 0; i < index; ++i){
                        	printf(" %c ", wrongLetters[i]);
                    	 }
                    	printf("\nRemaining chances are : %d\n", chances);
                    	printHangman(mistake);
                    		
			if(strcmp(actualWord, guessWord) == 0){
                    	printf("\n\nCONGRATULATION! YOU WON THE GAME!\n\n");
                    	break;
			}//end of if(strcmp(actualWord, guessWord) == 0)	
	
                }// end found
        

		//printing the user mistakes
                else{
                     printf("Entered wrong letters are: ");
                     for(int i = 0; i < index; ++i){
                            printf("%c ", wrongLetters[i]);
                      }
                    	
		      printf("\nRemaining chances are : %d\n", chances);
                      printHangman(mistake);
                    	
		     //checking if user has won or not
		     if(strcmp(actualWord, guessWord) == 0){
                           printf("\n\nCONGRATULATION! YOU WON THE GAME!\n\n");
                           break;
                     }			

	        }//end of else
			
			
	   }//end of while loop
            
         //declaring game over
         if(chances == 0) 
                printf("\n\nGAME OVER! YOU LOST!\n");
		printf("\nThe word was : %s\n", actualWord);
}


int main(){
    int choice;
    char input[4];
    char compare[] = "yes";
    int level = 1;
 
    srand(time(NULL));
    system("cls");
	
    printf("\n");
    printf("\033[1;31m"); 
    printf("      _   _                                          \n");
    printf("     | | | |                                         \n");
    printf("     | |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __   \n");
    printf("     |  _  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\  \n");
    printf("     | | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
    printf("     \\_| |_/\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("                          __/ |                      \n");
    printf("                         |___/                       \n");
    printf("\033[0m"); 
    
    printf("\033[1;34m");
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
    printf("\033[0m");


   printf("\033[1;92m");
   printf("\n\n---------- WELCOME TO HANGMAN GAME ----------\n\n");
   printf("Instructions:\n");
   printf("* A word will be displayed with missing letters. Your goal is to guess the missing letters.\n");
   printf("* All letters are in lowercase.\n");
   printf("* You have 6 chances to guess the correct letters. If the hangman figure is completely drawn, you lose.\n");
   printf("* If a letter is entered more than 2 times (whether it's already present or correct), you lose.\n");
   printf("* If you want to exit the game then: \n");
   printf("    - Enter 0 to exit the game.\n");
   printf("Enter 'yes' to begin: ");
	
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
			
                }//end of if statement
		
	     	while (getchar() != '\n');
 		if(level == 0){
			printf("\nExiting the game. Goodbye!\n");
			 return 0;
		}
	
            if(level == 1){
		checkEnteredLetter("checkeasy.txt", 1);
		 printf("\nIf you want to exit the game then enter 0 to exit the game.\n");
		 printf("\nOtherwise you can enter 1 to play another game:\n");
		 scanf("%d", &choice); 
	         if(choice == 0){
			return 0;
		   }
		 else continue;	

            }//end of level 1

            if(level == 2){
                 checkEnteredLetter("checkmedium.txt", 2);
		 printf("\nIf you want to exit the game then enter 0 to exit the game.\n");
		 printf("\nOtherwise you can enter 1 to play another game:\n");
		 scanf("%d", &choice); 
	         if(choice == 0) return 0;
		 else continue;
		 
            } //end of level 2

            if(level == 3){
		 checkEnteredLetter("checkhard.txt", 3);
		 printf("\nIf you want to exit the game then enter 0 to exit the game.\n");
		 printf("\nOtherwise you can enter 1 to play another game:\n");
		 scanf("%d", &choice); 
	         if(choice == 0) return 0;
		 else continue;

            }
        } //end of level 3
	else{
		printf("\nExiting the game. Goodbye!\n");
		return 0;
	}

   }//end of while loop
    
}// end program
