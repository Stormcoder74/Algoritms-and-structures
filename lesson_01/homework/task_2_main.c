//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>

int const LIMIT = 10000;

int main(void) {
    int devider = 10;
    for (int i = 1; i <= LIMIT; i++) {
        if (i * i % devider == i)
            printf("%d в квадрате равно %d\n", i, i * i);
        if (i > devider) devider *= 10;
    }
    return 0;
}