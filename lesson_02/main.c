/* Исполнитель «Калькулятор» преобразует целое число, записанное на экране.
 * У исполнителя две команды, каждой присвоен номер:
 *   1. Прибавь 1.
 *   2. Умножь на 2.
 *   Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.
 *   Сколько существует программ, которые число 3 преобразуют в число 20?*/
//Решение преподавателя
//https://github.com/Stormcoder74/Algoritms-and-structures.git

#include <stdio.h>

#define GOAL 20
#define START 3
#define SYLLABLE 1
#define MULTIPLIER 2


int main() {
    int arr[100] = {0};
    arr[START] = 1;
    for (int i = START + 1; i <= GOAL; i++) {
        if ((i % MULTIPLIER) == 0) arr[i] = arr[i - SYLLABLE] + arr[i / MULTIPLIER];
        else arr[i] = arr[i - SYLLABLE];
    }
    printf("%d", arr[GOAL]);
    return 0;
}
