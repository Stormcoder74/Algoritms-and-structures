#include <stdio.h>
#include <time.h>

#define SIZE 8 // 8
int moves[8][2] = {{1,  -2},
                   {2,  -1},
                   {2,  1},
                   {1,  2},
                   {-1, 2},
                   {-2, 1},
                   {-2, -1},
                   {-1, -2}};
int board[SIZE][SIZE] = {{0},
                         {0},
                         {0},
                         {0},
                         {0},
                         {0},
                         {0},
                         {0}};

int checkBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == 0)
                return 0;
    return 1;
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d\t", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

void invert(int start, int finish) {
    for (int i = 0; i <= (finish - start) / 2; i++) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                if (board[j][k] == start + i) {
                    board[j][k] = finish - i;
                    continue;
                }
                if (board[j][k] == finish - i)
                    board[j][k] = start + i;
            }
        }
    }
}

void stepSelect(int *x, int *y) {
    int min = 8;
    int numMove = 0;
    for (int i = 0; i < 8; ++i) {
        int X = *x + moves[i][0];
        int Y = *y + moves[i][1];
        if ((X >= 0 && X < SIZE) && (Y >= 0 && Y < SIZE)) {
            if (board[Y][X] == 0) {
                int counter = 0;
                int X2, Y2;
                for (int j = 0; j < 8; ++j) {
                    X2 = X + moves[j][0];
                    Y2 = Y + moves[j][1];
                    if ((X2 >= 0 && X2 < SIZE) && (Y2 >= 0 && Y2 < SIZE) ) { //&& (X2 != *x && Y2 != *y)
                        if (board[Y2][X2] == 0) {
                            counter++;
                        }
                    }
                }
                if (counter < min) {
                    min = counter;
                    numMove = i;
                }
            }
        }
    }
    *x = *x + moves[numMove][0];
    *y = *y + moves[numMove][1];
}

int findMove(int x, int y, int step) {
    for (int j = 0; j < 8; j++) {
        int X = x, Y = y;
        stepSelect(&X, &Y);
        if ((X >= 0 && X < SIZE) && (Y >= 0 && Y < SIZE)) {
            if (board[Y][X] == 0) {
                board[Y][X] = step;
                if (step == SIZE * SIZE)
                    return step;
                else
                    return findMove(X, Y, step + 1);
            }
        }
    }
    return step - 1;
}

int main(void) {
//    long time1 = (int) clock();
    int result = findMove(1, 1, 1);
    printBoard();
    /*invert(1, result);
    for (int j = 0; j < SIZE; ++j) {
        for (int k = 0; k < SIZE; ++k) {
            if (board[j][k] == result) {
                result = findMove(k, j, result + 1);
            }
        }
    }
    printBoard();
    invert(40, result);
    for (int j = 0; j < SIZE; ++j) {
        for (int k = 0; k < SIZE; ++k) {
            if (board[j][k] == result) {
                result = findMove(k, j, result + 1);
            }
        }
    }
    printBoard();
    invert(51, result);
    printBoard();*/


//    long time2 = (int) clock();
//    printf("%lf", (double)(time2 - time1) / 1000);
    return 0;
}