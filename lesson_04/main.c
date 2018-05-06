//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>

#define SIZE 8
#define START_X 2
#define START_Y 3

int moves[8][2] = {{1,  -2}, {2,  -1}, {2,  1}, {1,  2},
                   {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int board[SIZE][SIZE] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%3d", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Правило Варнсдорфа: При обходе доски конь следует на то поле,
// с которого можно пойти на минимальное число ещё не пройденных полей.
void ruleOfVarnsdorf(int *x, int *y) {
    int min = 8;
    int numMove = 0;
    for (int i = 0; i < 8; ++i) {
        int X = *x + moves[i][0];
        int Y = *y + moves[i][1];
        if ((X >= 0 && X < SIZE) && (Y >= 0 && Y < SIZE)) {
            if (board[Y][X] == 0) {
                int counter = 0;
                for (int j = 0; j < 8; ++j) {
                    int X2 = X + moves[j][0];
                    int Y2 = Y + moves[j][1];
                    if ((X2 >= 0 && X2 < SIZE) && (Y2 >= 0 && Y2 < SIZE))
                        if (board[Y2][X2] == 0) {
                            counter++;
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

int main(void) {
    int x = START_X, y = START_Y;
    for (int i = 1; i <= SIZE * SIZE; ++i) {
        board[y][x] = i;
        ruleOfVarnsdorf(&x, &y);
    }
    printBoard();
    return 0;
}