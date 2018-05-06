//https://github.com/Stormcoder74/Algoritms-and-structures.git
// решение полным перебором методом поиска с возвратом
#include <stdio.h>
#include <time.h>

#define SIZE 6 // 8 считает очень долго
int moves[8][2] = {{1,  -2}, {2,  -1}, {2,  1}, {1,  2},
                   {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int board[SIZE][SIZE] = {{0}, {0}, {0}, {0},
                         {0}, {0}, {0}, {0}};

int findMove(int x, int y, int step) {
    for (int j = 0; j < 8; j++) {
        int X = x + moves[j][0];
        int Y = y + moves[j][1];
        if ((X >= 0 && X < SIZE) && (Y >= 0 && Y < SIZE)) {
            if (board[Y][X] == 0) {
                board[Y][X] = step;
                if (step == SIZE * SIZE)
                    return 1;
                else if (findMove(X, Y, step + 1) == 1)
                    return 1;
                else
                    board[Y][X] = 0;
            }
        }
    }
    return 0;
}

int main(void) {
    long time1 = (int) clock();
    int result = findMove(0, 0, 1);
    long time2 = (int) clock();

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%3d", board[i][j]);
        printf("\n");
    }
    printf("%lf", (double)(time2 - time1) / 1000);
    return 0;
}