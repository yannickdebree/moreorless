#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int MAX = 100, MIN = 1;

int main()
{
    srand(time(NULL));
    int isRunning = 1;

    while(isRunning == 1)
    {
        playAGame();
        isRunning = askANewGame();
    }

    return 0;
}

void playAGame()
{
    clearConsole();
    levelChoice();
    int mysteryNumber = (rand() % (MAX - MIN + 1)) + MIN, promptedValue = 0, nbrRounds = 0;

    while(promptedValue != mysteryNumber)
    {
        nbrRounds++;
        printf("What is the number between %d and %d ? ", MIN, MAX);
        scanf("%d", &promptedValue);
        if(promptedValue < MIN || promptedValue > MAX)
        {
            printf("Please enter an integer between %d and %d.\n", MIN, MAX);
        }
        else if(promptedValue > mysteryNumber)
        {
            printf("Less !\n");
        }
        else if(promptedValue < mysteryNumber)
        {
            printf("More !\n");
        }
        else if(promptedValue == mysteryNumber)
        {
            printf("You've win in %d rounds !\n", nbrRounds);
        }
    }
}

void clearConsole()
{
    system("@cls||clear");
}

void levelChoice()
{
    int level = 0, minLevel = 1, maxLevel = 5;
    while(level < minLevel || level > maxLevel)
    {
        printf("Choice a level : (from %d to %d) : ", minLevel, maxLevel);
        scanf("%d", &level);
        if(level < minLevel || level > maxLevel)
        {
            printf("Please choice a number between %d and %d. \n", minLevel, maxLevel);
        }
    }
    MAX = (int)(10 * pow(10, level) + 0.5);
}

int askANewGame()
{
    int answer = 2;
    while(answer != 0 &&  answer != 1)
    {
        printf("An other game ? (Yes = 1, No = 0) ? ");
        scanf("%d", &answer);
        if(answer != 0 &&  answer != 1)
        {
            printf("Please enter 0 or 1 to continue.\n");
        }
    }
    return answer;
}
