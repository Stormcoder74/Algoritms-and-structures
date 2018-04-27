//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>

int const NUMBER = 345; // 101011001
int const NOTATION_BASE = 2;

int toBin(int x) {
    if (x / NOTATION_BASE) return toBin(x / NOTATION_BASE) * 10 + x % NOTATION_BASE;
    else return x % NOTATION_BASE;
}

int main() {
    printf("%d\n", toBin(NUMBER));
    return 0;
}