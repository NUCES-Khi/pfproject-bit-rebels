### Team Members
<table>
<tr>
	<th>Name</th>
	<th>Seat Number</th>
</tr>
<tr>
	<td> Amna </td>
	<td> 23k-0066</td>
</tr>
<tr>
	<td> Urooj Baloch </td>
	<td> 23k-0071 </td>
</tr>
</table>

# Project demo:

https://github.com/NUCES-Khi/pfproject-bit-rebels/assets/142903458/291dbc86-e3fb-4d66-807c-6abefcbcd43e

# Project Proposal: To Create A Hangman Game in C

![images](https://github.com/NUCES-Khi/pfproject-bit-rebels/assets/144048378/cc95f64c-871c-4e6d-95a2-80bc56c3c175)


## Datastructures used, how and why:

### What we used:
1. A <strong>struct</strong> datastructure which we created to store 2 values:
   * A random index.
   * A 2D Array which stores all the words from a given file.
2. <strong>Array</strong> structure, to compare the user-input for a missing letter against the actual letter.

### How we used:
1. We defined the <strong>Struct</strong> Data Structure using the struct keyword as shown below:

   ```C
   typedef struct {
    int randomIndex;
    char words[MAX_WORDS][MAX_LENGTH];
   } WordData;
   ```
2. Arrays are used to verify user input against the actual word as shown below:
   ```C
           // letter is user input
		for (j; j < strlen(actualWord); ++j){
			if (actualWord[j] == letter && guessWord[j] == '_'){
				guessWord[j] = letter;
				found = 1;
			}
		}
		// checking if the user input is being repeated i.e. the user has already entered that letter before:
		j = 0;
		for (j; j < index; ++j){
			if (wrongLetters[j] == letter) 
				repeatFlag = 1;
		}
   ```
   Here,
   * if the user input is correct, we are updating the guess-word's missing letter with the user input
   * repeatFlag makes sure that the user's number of remaining chances before the game ends remains the same.

### Why we used:

1. We have three levels of difficulty i.e. easy, medium and hard. After selecting a word from the file, we manipulate it and modified it by replacing limited amount of letters with underscores and store the updated word in a 1D array.
2. We had to read and store those files in a 2D array so we can find the word against the program-generated random index.
3. Considering the type of functions we had in our mind, we decided to create a struct structure, to store the value for both, the random index number and a 2D array to contain our words.
4. Strings work as arrays. If we want to compare a letter of string A against a letter of string B, we need to use arrays.

## Major Problems Faced and How we resolved them:

1. <strong>Filing</strong> was the main issue we encountered. We resolved it by learning more about it.
2. The code had bugs, like the loop to take user input and compare it with the actual word was not working properly. We resolved this issue by doing hours of debugging.

## Algorithm:

### Working of main function:

1. The program starts with printing the rules of the game.
2. The user is given two options.
   * Enter 0 to exit the game.
   * Enter 'yes' to start the game.
3. When the game starts, the user is given options to choose the difficulty level.
   * Enter 1 for level 1.
   * Enter 2 for level 2.
   * Enter 3 for level 3.
4. If the user enters 0 for the difficulty level, the game ends!
5. Else the code calls the function "checkEnteredLetter" and in the parameters, text-file is given depending on the level chosen.
   ```C
   
     if(level == 1){
        checkEnteredLetter("easy.txt", 1);
     }
   
     if(level == 2){
        checkEnteredLetter("medium.txt", 2);
     }
   
     if(level == 3){
        checkEnteredLetter("hard.txt", 3);
     }
   
   ```
6. Here easy.txt, medium.txt and hard.txt are the files containing words.

### Working of checkEnteredLetter(char *file1, char *file2):

1. We have declared and initialized some variables.
2. We declare and initialize a variable using the struct we defined, as shown below:

   ```C
          WordData wordData = takeWordFromFile(filename); 
   ```
3. Here we are calling another function <strong>takeWordFromFile(char *file)</strong>.
4. This function will return us two values, a random index generated by our code and a 2D array which contains all the words from the given file (contains words with missing letters).
5. Then we use a while loop to loop until the user has any remaining chances. Total number of chances for wrong guesses are six.
6. Within the while loop we compare user input against actual word, if the user guesses a wrong letter, some part of the hangman gets drawn/printed.
7. The game continues until the user if out of chances i.e. the hangman has been completely drawn/printed.
8. We are using a function called printHangman to print the Hangman based on the number of chances left.
9. If the user guesses the word correctly, the program asks user to:
    * Press 0 to exit
    * Press 1 to play more
10. If the user chooses to continue playing, the user is again given the option to choose the difficulty level, and the rest of the procedure is the same.

### Working of takeWordFromFile(char *filename):

1. We declare and initialize some variables.
2. We read the given file and write it in a 1D array. We are also replacing any "\n" (newline characters) with "\0" (endline character).
3. We use the rand() function to get a random number within the range of the Maximum number of words we have in our files.
4. The function returns two values:
   * The int value of random index.
   * The corresponding word (with missing letters) for that random index value.

### Function to Clear the Console:

We want the user to have a smooth and nice User Experience while playing our Hangman, so we wrote the following function to clear the console everytime we get the user input:
```C
       void clearConsole() {
          printf("\033[2J\033[H");
       }
```

## Complexity of our Algorithm:
The complexity of our algorithm is O(n<sup>2</sup>). There are surely chances of improvement in our code but still O(n<sup>2</sup>) is not a bad value for space complexity, since we are only using a limited number of words in the files we used.
