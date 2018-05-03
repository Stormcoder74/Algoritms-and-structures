//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main(void) {
    int arr[SIZE] = {0};
//    int counter = 0;
    for (int i = 0; i < SIZE; i++) {
        int new = (int) random() % 100;
        printf("%2d ", new);
        int min = 0, max = i, mid;
//        counter += 6;
        while (max - min > 1) {
            mid = (min + max) / 2;
            if (new < arr[mid])
                max = mid;
            if (new >= arr[mid])
                min = mid;
//            counter += 8;
        }
        if (min == 0 && arr[min] > new)
            max = 0;
        for (int j = i; j > max; j--) {
            arr[j] = arr[j - 1];
//            counter += 4;
        }
        arr[max] = new;
//        counter++;
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++)
        printf("%2d ", arr[i]);
//    printf("\n%d ", counter);
    return 0;
}