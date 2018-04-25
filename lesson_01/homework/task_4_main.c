//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>

long const X = 7;
long const N = 15;

long quickPow(long x, long n) {
    if (n > 3) {
        long tmpX = quickPow(x, n / 2);
        if (n % 2 == 0) {
            x = tmpX * tmpX;
        } else {
            x = x * tmpX * tmpX;
        }
    } else {
        if (n % 2 == 0) {
            x = x * x;
        } else {
            x = x * x * x;
        }
    }
    return x;
}

int main() {
    printf("Число %ld в степени %ld равно %ld\n", X, N, quickPow(X, N));
    return 0;
}