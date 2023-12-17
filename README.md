## Team Members
Amna(23K-0066)

Urooj Baloch(23K-0071)

# Hangman Game
This is a simple implementation of the Hangman game written in C. The game uses two arrays:

##### Array 1: 
Contains words for the game.

##### Array 2: 
Contains the same words but with missing letters, forming the initial puzzle for the user.

## How the Game Works

The game proceeds as follows:

1. Firstly,program ask the user if he wants to play or not

2. If user wants to play the game the program will ask the user to choose the level i.e EASY, MEDIUM,or HARD 

3. The words for each level are stored in three different files    
 
4. The program randomly selects a word from the file according to user wish of difficulty

5. It displays the a random word with missing letter from the file which which contains these words 

6. The user enters a character to guess the missing letters.

7. The program checks the entered character from the file which contains the correct and complete word

8. If the character matches any of the missing letters, it reveals the correct guesses.

9. If the character doesn't match, it deducts a chance from the user's available attempts.
    
10. Each wrong attempt of user make the body of hangman until the body completes

11. The body of hangman is based on the chances of wrong attempts if the user become out of chances and the man completly hangs the user will loss the game

12. If the user was able to complete the correct word before the chances end he/she will win the game

13. The game continues until the user either guesses all the letters or runs out of attempts.

14. The game will continue until the user exits the game if user exit the game the game will show him his/her score or how many times he won the game


## Instructions
1. 
#### Compilation: 
Compile the code using a C compiler.
#### Execution: 
Run the compiled program.
#### Gameplay: 
Follow the on-screen instructions to guess the missing letters and complete the word before running out of attempts.


## Code Structure

The code structure involves using two arrays, functions to handle user input, checking the entered character against the word, updating the puzzle, and managing the game flow.
