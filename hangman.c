#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

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
            printf("  |        O\n");
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
            printf("  |        O\n");
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


int main() {
    char list1[6][20] = {"p u z z l e", "b a n a n a", "c h a n g e", "h i", "b y e", "f a c e b o o k"};
    char list2[6][20] = {"p _ _ _ l _", "_ _ n _ n _", "_ h _ _ g _", "h _", "_ y _", "f _ _ _ _ o _ _"};
    char input[4], letter;
    char compare[] = "yes";
    char body[6];
    int RandomNumber, chances = 6, length = 0, limit, found, check, mistake = 0;

    srand(time(NULL)); 

    printf("\n\nWELCOME TO HANGMAN GAME\n\n");
    printf("----------INSTRUCTIONS----------\n\n");
    printf("1) A word will be given and you have to guess the missing letters\n");
    printf("2) All alphabets are in lowercase\n");
    printf("3) You will be given 6 chances and will lose the game if hangman figure is completely drawn\n\n");
    printf("To start the game enter yes\n");
    fgets(input, sizeof(input), stdin);

    if (strcmp(input, compare) == 0) {
        RandomNumber = rand() % 6;
        printf("Word to guess: %s\n", list2[RandomNumber]);
	limit = strlen(list1[RandomNumber]);

	//loop for counting the number of dashes to be filled
        for (int i = 0; i < 20; ++i) {
            if (list2[RandomNumber][i] == '_') // Check for underscores to calculate length
                length++;
        }

	//loop for the game
        for (int i = 0; chances > 0 && chances < 7; ++i) {
            printf("\nEnter a letter: ");
            scanf(" %c", &letter); // Read a single character as the guessed letter
	    found = 0;

	    //loop for checking if entered letter exist in the actual word or not
            for (int j = 0; j < limit; ++j) {
                if (list1[RandomNumber][j * 2] == letter) {
                    list2[RandomNumber][j * 2] = letter; // Update the corresponding position in list2
                    printf("\nCurrent status: %s\n", list2[RandomNumber]);
		    --length;
		    found = 1;
                }
            } //end for loop of checking letter

	    
           //checking mistakes so that hangman can be drawn accordingly
	    if(found == 0){
		mistake = mistake + 1;
		--chances;
		printf("Remaining chances are : %d\n", chances);
		printHangman(mistake);
	   }
	   else {
	        printf("Remaining chances are : %d\n", chances);
	        printHangman(mistake);
           }

	   //checking if user won or not
	   if(strcmp(list1[RandomNumber], list2[RandomNumber]) == 0){
		  printf("\n\nCONGRATULATION! YOU WON THE GAME!\n\n");
		  break;
	   }
        }
	
	//declaring game over
	if(chances == 0) 
		printf("\n\nGAME OVER! YOU LOST!\n\n");
    }

    return 0;
}