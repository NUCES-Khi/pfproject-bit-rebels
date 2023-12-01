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

1. The program randomly selects a word from Array

2. It displays the corresponding word from Array 2 with missing letters to the user.

3. The user enters a character to guess the missing letters.

4. The program checks the entered character against the word in Array 1.

5. If the character matches any of the missing letters, it reveals the correct guesses.

6. If the character doesn't match, it deducts a chance from the user's available attempts.

7. The game continues until the user either guesses all the letters or runs out of attempts.


## Instructions

#### Compilation: 
Compile the code using a C compiler.
#### Execution: 
Run the compiled program.
#### Gameplay: 
Follow the on-screen instructions to guess the missing letters and complete the word before running out of attempts.


## Code Structure

The code structure involves using two arrays, functions to handle user input, checking the entered character against the word, updating the puzzle, and managing the game flow.
