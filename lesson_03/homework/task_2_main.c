//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int N, int *a) {
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}
// подсчет производительности закомментирован
int main(void) {
//    int counter = 0;
    int arr[SIZE] = {0};
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (int) random() % 100;
    }
    print(SIZE, arr);

    int noSwap = 0;     // отсутствие перемещения значений
    int location = 1;   // текущая ячейка
    int direction = 1;  // направление прохода
    float fShift = 0;   // вещественный отступ от краев изменяется на 0.5 за проход
    int iShift = 0;     // целочисленный оступ изменяется на 1 за 2 прохода

    while (1) {
        if (arr[location] < arr[location - 1]) {
            swap(&arr[location], &arr[location - 1]);
            noSwap = 0;
//            counter += 5;
        }
//        counter++;
        location += direction;
        if (location == SIZE - iShift || location == iShift) {
            if (noSwap) break;
            direction *= -1;
            location += direction;
            noSwap = 1;
            fShift += 0.5;
            iShift = (int)fShift;
//            counter += 8;
        }
//        counter += 5;
    }
    print(SIZE, arr);
//    printf("%d", counter);
    return 0;
}
    