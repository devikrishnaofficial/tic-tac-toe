#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number_to_guess, guess, attempts = 0;
    srand(time(NULL)); 
    number_to_guess = rand() % 100 + 1;
    printf("Welcome to Guess the Number!\n");
    printf("I have picked a number between 1 and 100. Try to guess it.\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else if (guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts!\n", attempts);
        }
    } while (guess != number_to_guess);
    return 0;
}

