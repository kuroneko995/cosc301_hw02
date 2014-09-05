#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>


/*
 * Be happy you didn't have to write this function.
 * Prints a low-tech ASCII gallows.  Max number of misses
 * is 7 (i.e., if there are 7 misses, the player loses and
 * the poor sap gets hung).  
 */
void print_gallows(int num_missed) {
    // make sure that we got called in a reasonable way
    assert(num_missed >= 0 && num_missed <= 7);

    printf("\n\n       |||========|||\n");
    if (num_missed > 0) {
        printf ("       |||         |\n");
    } else {
        printf ("       |||          \n");
    }

    if (num_missed > 1) {
        printf ("       |||         O\n");
    } else {
        printf ("       |||          \n");
    }

    if (num_missed > 2) {
        if (num_missed > 4) {
            printf ("       |||        /|\\\n");
        } else if (num_missed > 3) {
            printf ("       |||        /| \n");
        } else {
            printf ("       |||        /  \n");
        }
    } else {
        printf ("       |||           \n");
    }

    if (num_missed > 5) {
        if (num_missed > 6) {
            printf ("       |||        / \\\n");
        } else {
            printf ("       |||        /  \n");
        }
    } else {
        printf ("       |||           \n");
    }

    printf ("       |||\n");
    printf ("       |||\n");
    printf ("     =================\n\n");
}

/*
 * Return length of string based on address
 */
char get_length (const char *word) { // return length of the char array
    char count = 0;
    char temp = 'a';
    char *pointer = word;
    bool done = false;
    while (!done) {
        temp = *pointer;
        if (temp != '\0') {
            count ++;
            pointer += sizeof(char);
        } else {
            done = true;
        }
    }
    return count;
}


/*
 * Print prompt
 *
 */
void print_prompt(char guessedChar[]) {
    if (!strlen(guessedChar)) {
        printf("Already guessed:  (none)\n");
    } else {
        printf("Already guessed: %s\n", guessedChar);
    }
    printf("What is your guest? ");
}

/*
 * Check if word is guessed. Return true if no '_' symbol remains
 */
bool is_guessed(char currWord[]){
    char temp = 'a';
    char i = 0;
    while (temp != '\0') {
        temp = currWord[i];
        if (temp == '_') {
            return false;
        } else {
            i++;
        }         
    }
    return true;
}

/*
 * Play one game of Hangperson.  The secret word is passed as a
 * parameter.  The function should return true if the player won,
 * and false otherwise.
 */
bool one_game(const char *word) {
    char wordLength = get_length(word);
    char num_missed = 0;
    bool game_over = false;
    char input[32];

    // Create a string containing the secret word
    char secretWord[wordLength+1];
    for (char i = 0; i < wordLength; i++) {
        secretWord[i] = *(word + i * sizeof(char));
    }
    secretWord[wordLength] = '\0';
    printf("Length of word is: %d\n", wordLength);

    // Create a string representing the guessing state
    char currWord[wordLength+1];
    for (char i = 0; i < wordLength; i++) {
        currWord[i] = '_';
    }
    currWord[wordLength] = '\0';  
    
    // Create an array to track guessed character
    char guessedChar[27];
    guessedChar[0] = '\0';

    while (!game_over) {
        print_prompt(guessedChar);
        fgets(input, 32, stdin);
                


    }
    
    if (num_missed >= 7) {
        printf("You lost.\n");
    } else {
        printf("You won.\n");
    }
    
    printf("The word is: %s\n", secretWord);
}




#ifndef AUTOTEST
/*
 * The main function is where everything starts.  Choose a random
 * word and call one_game.  Feel free to modify the words array,
 * but don't forget to modify the modulus (currently 4) for choosing 
 *  a random word from the array.
 */
int main() {
    srandom(time(NULL));
    char *words[] = { "SUMMER", "AUTUMN", "WINTER", "SPRING" };
    int word = random() % 4;
    one_game(words[word]);
    return 0;
}
#endif
