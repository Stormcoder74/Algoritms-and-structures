#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main() {
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        int new = (int)random() % 100;
        int min = 0, max = i - 1, mid = (min + max) / 2;
        while (min < max){
            if(new == arr[mid]) break;
            else if(new < arr[mid])  max = mid - 1;
            else min = mid + 1;
            mid = (min + max) / 2;
        }
        for (int j = i; j > mid; --j) {
            arr[j] = arr[j - 1];
        }
        arr[mid] = new;
        printf("%d", arr[i]);
    }
    return 0;
}