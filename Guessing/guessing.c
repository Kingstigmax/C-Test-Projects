#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int randomNumber, guess, attempts = 0;
    const int MAX_ATTEMPTS = 10;

    srand(time(NULL));
    randomNumber = rand() % 100 + 1;

    printf("Guess the number Game\n");
    printf("---------------------\n");
    printf("The number is between 1 and 100. \n");

    while (attempts < MAX_ATTEMPTS) 
    {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        scanf("%d", &guess);

        attempts++;

        if (guess == randomNumber)
        {
            printf("Congrats! You guessed the right number in %d attempts! \n", attempts);
            break;
        } else if (guess < randomNumber) 
        {
            printf("Too low! Try again. \n");
        } else {printf("Too high ! Try again. \n");}

    }

    if (attempts == MAX_ATTEMPTS) 
    {   
        printf("Sorry, you didn't guess the number in %d attempts. The correct number was %d. \n", attempts, randomNumber);
    }

    return 0;
}