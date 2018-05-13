//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>

#define LENGTH 10    // ожидаемая длина хеш-кода

long long hashFunction(char *string){
    long long lenght = 1;
    for(int i = 0; i < LENGTH; i++)
        lenght *= 10;

    long long result1 = 13;
    for(int i = 0; string[i] != '\0'; i++){
        result1 += string[i] * string[i];
    }

    long long result2 = 1;
    while(result2 < lenght / 10) {
        result2 *= result1;
        result2 %= lenght;
    }

    return result2;
}

int main() {
    char string1[] = "output string";
    char string2[] = "intput string";
    char string3[] = "o";
    char string4[] = "";
    char string5[] = "rjgoerigjifk";

    printf("%lld\n", hashFunction(string1));
    printf("%lld\n", hashFunction(string2));
    printf("%lld\n", hashFunction(string3));
    printf("%lld\n", hashFunction(string4));
    printf("%lld\n", hashFunction(string5));

    return 0;
}