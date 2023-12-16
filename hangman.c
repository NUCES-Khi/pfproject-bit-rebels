#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAX_LENGTH 100
#define MAX_WORDS 50

//Declaring a structure
typedef struct {
    int randomIndex;
    char words[MAX_WORDS][MAX_LENGTH];
} WordData;

    
// Function to choose a random word from a file
WordData takeWordFromFile(char *filename) {  //This function was originally written by Urooj. I improvised it according to the requirements.
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

    if (wordCount > 0) {
        result.randomIndex = rand() % wordCount;
        if (result.randomIndex >= 0 && result.randomIndex < wordCount) {
            printf("Word to guess is:\n%s\n", result.words[result.randomIndex]);
        }
    }

    return result;
} //end function takeWordFromFile


//function to extract the words from a file
void takeCorrectWordFromAnotherFile(char *filename, char words[MAX_WORDS][MAX_LENGTH]){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File does not exist.\n");
        return NULL;
    }
	
    int wordCount = 0;
    char line[MAX_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL && wordCount < 44) {
        line[strcspn(line, "\n")] = '\0';      //Remove newline character
        strcpy(words[wordCount], line);
        wordCount++;
    }
    fclose(file);
} //end function takeCorrectWordFromAnotherFile


//function to print the hangman figure
void printHangman(int mistakes) {
    switch (mistakes) {
        case 6:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        @\n");
            printf("  |       /|\\\n");
            printf("  |       / \\\n");
            printf("__|__\n");
            break;
        case 5:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        @\n");
            printf("  |       /|\\\n");
            printf("  |       /\n");
            printf("__|__\n");
            break;
        case 4:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        @\n");
            printf("  |       /|\\\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 3:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        @\n");
            printf("  |       /|\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 2:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        @\n");
            printf("  |        |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 1:
            printf("  _________\n");
            printf("  |        |\n");
            printf("  |        @\n");
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
} // end function printHangman


//function to check the user-entered letter
void checkEnteredLetter(char *filename1, char*filename2){
   	int chances = 6, found = 0, mistake = 0, repeated = 0;
    	int index = 0;
    	char wrongLetters[MAX_LENGTH];
  
	WordData wordData = takeWordFromFile(filename1);
		int random = wordData.randomIndex;
		char guessWord[50];
                strcpy(guessWord, wordData.words[random]);    //guessWord is the word with missing letters
		
	        char checkWordData[MAX_WORDS][MAX_LENGTH];
		takeCorrectWordFromAnotherFile(filename2, checkWordData);
                char actualWord[30];
		strcpy(actualWord, checkWordData[random]);     //actualWord is the same word but with complete letters
		
	        char letter;
		while(chances > 0 && chances < 7){
               		printf("\nEnter letter: ");
               		scanf(" %c", &letter);
			system("cls");
     			for(int j = 0; j < strlen(actualWord); ++j){
				found = 0;
				if (actualWord[j] == letter) {
					if(guessWord[j] == '_'){
						guessWord[j] = letter;
						found = 1;
						for(int i = 0; i < strlen(actualWord) - j; ++i){
							 if (actualWord[i] == letter){
							   if(guessWord[i] == '_'){
            			 			   	guessWord[i] = letter;   // Update the corresponding position in list2
		    					    }
							 }
						}
					 break;
					}
                                //calculting user-entered wrong characters as to print the body and to reduce the chances
				if(found != 1){
					printf("\n\nThe entered letter is repeated.\nThe limit of repetition is 2\n");
					found = 1;
					++repeated;
				}
				break;
        			}
		
       				 if(wrongLetters[j] == letter){
					printf("\n\nThe entered letter is repeated.\nThe limit of repetition is 2\n");
					found = 1;
					++repeated;
					}
   			 } //end for loop of checking letter
			 
			printf("\nCurrent status: %s\n", guessWord);

               		 //checking mistakes so that hangman can be drawn accordingly
                	 if(found == 0) {
                    	 	wrongLetters[index] = letter;
                    		++mistake;
                    		--chances;
                    		++index;
                    		printf("Entered wrong letters are: ");
                    		for(int i = 0; i < index; ++i){
                        		printf(" %c ", wrongLetters[i]);
                    		  }
                    		printf("\nRemaining chances are : %d\n", chances);
                    		printHangman(mistake);
				if(strcmp(actualWord, guessWord) == 0){
                    			printf("\n\nCONGRATULATION! YOU WON THE GAME!\n\n");
                    			break;
                    	 }
                    	
                	}// end found
        
                	else {
                    	printf("Entered wrong letters are: ");
                    	for(int i = 0; i < index; ++i){
                        	printf("%c ", wrongLetters[i]);
                    	}
                    	printf("\nRemaining chances are : %d\n", chances);
                    	printHangman(mistake);
			if(strcmp(actualWord, guessWord) == 0){
                    		printf("\n\nCONGRATULATION! YOU WON THE GAME!\n\n");
                    		break;
                    	 }
		  	}

			//checking if game is over or not
			if(repeated > 4){
				printf("\n\nGAME OVER! YOU LOST!\n\n");
				printf("\n\nYou Exceeded the limit of repeating letters which are already present");
				break;
			}
		}
            
                	//declaring game over
                	if(chances == 0) 
                	printf("\n\nGAME OVER! YOU LOST!\n\n");
		   	printf("\nThe word was : %s", actualWord);
} //end of function checkEnteredLetter



int main(){
   
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
printf("Instructions:\n");
printf("1. A word will be displayed with missing letters. Your goal is to guess the missing letters.\n");
printf("2. All letters are in lowercase.\n");
printf("3. You have 6 chances to guess the correct letters. If the hangman figure is completely drawn, you lose.\n");
while(level > 0 && level < 4){
	
		printf("\n4. Choose a level:\n");
		printf("    - Enter 1 for Easy\n");
		printf("    - Enter 2 for Medium\n");
		printf("    - Enter 3 for Hard\n");
		printf("    - Enter 0 to exit the game.\n");
		printf("5. If a letter is entered more than 2 times (whether it's already present or correct), you lose.\n\n");
	

printf("Get ready to play! Enter 'yes' to begin: ");
	fgets(input, sizeof(input), stdin);
        if (strcmp(input, compare) == 0) {
		printf("\nEnter level to proceed with the game: ");
		scanf(" %d", &level);
		if (level > 3) {
                printf("Invalid input. Please enter a valid level.\n");
                while (getchar() != '\n'); // Clear input buffer
                
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
        } //end of if statement(strcmp(input, compare) == 0)

   }//end of while loop
    
} // end main function
