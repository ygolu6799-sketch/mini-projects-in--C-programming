#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int width = 20, height = 20;
int gameOver, score;
int x, y, fruitX, fruitY, flag;
int tailX[100], tailY[100];
int countTail;

void setup() {
    gameOver = 0;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < width+2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printf("#");
            if (i == y && j == x)
                printf("O"); // Snake head
            else if (i == fruitY && j == fruitX)
                printf("F"); // Fruit
            else {
                int print = 0;
                for (int k = 0; k < countTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o"); // Snake body
                        print = 1;
                    }
                }
                if (!print) printf(" ");
            }
            if (j == width - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < width+2; i++)
        printf("#");
    printf("\n");
    printf("Score: %d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': flag = 1; break; // left
            case 'd': flag = 2; break; // right
            case 'w': flag = 3; break; // up
            case 's': flag = 4; break; // down
            case 'x': gameOver = 1; break; // exit
        }
    }
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < countTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag) {
        case 1: x--; break;
        case 2: x++; break;
        case 3: y--; break;
        case 4: y++; break;
        default: break;
    }

    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = 1;

    for (int i = 0; i < countTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        countTail++;
    }
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // slow down game speed
    }
    printf("Game Over! Final Score: %d\n", score);
    return 0;
}
