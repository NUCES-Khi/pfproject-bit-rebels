### Team Members
Amna(23K-0066)

Urooj Baloch(23K-0071)

# Hangman Game


![images](https://github.com/NUCES-Khi/pfproject-bit-rebels/assets/144048378/cc95f64c-871c-4e6d-95a2-80bc56c3c175)

This is a simple implementation of the Hangman game written in C. 

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


# Instructions
1. You should have chose the difficulty level first

2. The program will display the word your goal is to guess the correct word

3. The words should be in lower case

4. You have 6 chances to guess the correct word

5. Complete the word before the chances end

6. Once the chances end and body of hangman drawn completely you will lose the game

   ![Unknown](https://github.com/NUCES-Khi/pfproject-bit-rebels/assets/144048378/867cc34f-0161-41a2-9694-b31c1ded8f49)

#### Compilation: 
The code of hangman will compile in C program 

#### Gameplay: 
Follow the on-screen instructions to guess the missing letters and complete the word before running out of attempts.


# Code Structure



The code structure involves functions to handle user input,function to pick the random word ,checking the entered character against the word, files containg words to be guessed of each difficulty level and of correct words, updating the puzzle, and managing the game flow.
