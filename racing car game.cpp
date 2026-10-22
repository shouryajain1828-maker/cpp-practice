
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define ROAD_WIDTH 25
#define ROAD_HEIGHT 20

int carPosition = ROAD_WIDTH / 2;
int enemyPosition;
int enemyRow = 0;
int score = 0;
int gameOver = 0;

void setup()
{
    srand((unsigned int)time(NULL));
    enemyPosition = rand() % ROAD_WIDTH;
}

void drawRoad()
{
    int i, j;

    system("cls");

    printf("\n       ===== RACING CAR GAME =====\n");
    printf("       Controls: A = Left | D = Right | Q = Quit\n");
    printf("       Score: %d\n\n", score);

    for (i = 0; i < ROAD_HEIGHT; i++)
    {
        printf("       |");

        for (j = 0; j < ROAD_WIDTH; j++)
        {
            if (i == ROAD_HEIGHT - 1 && j == carPosition)
            {
                printf("A");
            }
            else if (i == enemyRow && j == enemyPosition)
            {
                printf("V");
            }
            else
            {
                printf(" ");
            }
        }

        printf("|\n");
    }

    printf("       ===============================\n");
}

void input()
{
    if (kbhit())
    {
        char key = getch();

        if (key == 'a' || key == 'A')
        {
            if (carPosition > 0)
                carPosition--;
        }
        else if (key == 'd' || key == 'D')
        {
            if (carPosition < ROAD_WIDTH - 1)
                carPosition++;
        }
        else if (key == 'q' || key == 'Q')
        {
            gameOver = 1;
        }
    }
}

void logic()
{
    enemyRow++;

    if (enemyRow == ROAD_HEIGHT - 1 &&
        enemyPosition == carPosition)
    {
        gameOver = 1;
    }

    if (enemyRow >= ROAD_HEIGHT)
    {
        enemyRow = 0;
        enemyPosition = rand() % ROAD_WIDTH;
        score += 10;
    }
}

int main()
{
    setup();

    while (!gameOver)
    {
        drawRoad();
        input();
        logic();

        Sleep(150);
    }

    system("cls");

    printf("\n");
    printf("       ===============================\n");
    printf("             GAME OVER!\n");
    printf("       ===============================\n");
    printf("             Final Score: %d\n", score);
    printf("\n       Thanks for playing!\n\n");

    printf("       Press any key to exit...");
    getch();

    return 0;
}




