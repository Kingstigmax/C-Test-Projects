#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

    int randomNumber, guess, attempts = 0;
    int MAX_ATTEMPTS;
    int MaxNumber = 100;
    char difficulty;

    printf("Select the difficulty you want 1. Easy, 2. Medium, or 3. Hard: \n");
    printf("E - Easy (1 to 50, 15 attempts) \n");
    printf("M - Medium (1 to 100, 10 attempts) \n");
    printf("H - Hard (1 to 200, 5 attempts) \n");
    printf("Enter your choice (E/M/H): ");
    scanf(" %c", &difficulty);

    switch(difficulty) 
    {
        case 'E':
        case 'e':
            MaxNumber = 50;
            MAX_ATTEMPTS = 15;
            break;
        case 'M':
        case 'm':
            MaxNumber = 100;
            MAX_ATTEMPTS = 10;
            break;
        case 'H':
        case 'h':
            MaxNumber = 200;
            MAX_ATTEMPTS = 5;
            break;
        default:
            printf("Invalid choice! Defaulting to medium difficulty. \n");
            MaxNumber = 100;
            MAX_ATTEMPTS = 10;
            break;
    }

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

    FILE* file = fopen("highscore.txt", "r+");
    int highscore;

    if (file == NULL)
    {
        file = fopen("highscore.txt", "w+");
        fprintf(file, "Highscore: %d", attempts);
        printf("New Highscore!\n");
    } else 
    {
        fscanf(file, "%d", &highscore);
        if (attempts < highscore) 
        {
            printf("New highscore! \n");
            rewind(file);
            fprintf(file, "%d", attempts);
        } else {printf("Highscore remains at %d attempts.\n", highscore);}

    }

    return 0;
}