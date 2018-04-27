#include <stdio.h>
#include <math.h>

int const GOAL = 20;
int const START = 3;

void toBin(int x, int *start, int goal) {
    if (x / 2) {
        toBin(x / 2, start, goal);
    }
    printf("%d", x % 2);
    if (x % 2) {
        *start *= 2;
    } else {
        *start += 1;
    }
}

int main() {
    for (int c = 1; c < 5; c++) {
        int signs = pow(2, c);
        for (int i = 0; i < signs; i++) {
            int start = START;
            toBin(i, &start, GOAL);
            printf(" %d\n", start);
        }
        printf("\n");
    }
    return 0;
}