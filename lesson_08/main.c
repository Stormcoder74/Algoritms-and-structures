#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Swap(int *, int *);
int HeapSort(int *, int);
int ShellSort(int *, int);

const int MAX = 1024;

int main(void) {
    int *array, amountCompare, lenght;
    FILE *fin, *fout;
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    array = (int *) malloc(MAX * sizeof(int)); // выделяем память
    int j = 0;
    while (fscanf(fin, "%d", &array[j]) == 1)
        j++;

    lenght = j;
//    amountCompare = HeapSort(array, lenght); // количество сравнений
    amountCompare = ShellSort(array, lenght); // количество сравнений

    fprintf(fout, "Number of elements: %d\nNumber of compares: %d\n", lenght, amountCompare);
    fprintf(fout, "n^2 = %d\nn*log(n) = %d\n",
            lenght * lenght, (int) (lenght * log(lenght) / log(exp(1))));
    fprintf(fout, "Sorted Array:\n");

    for (int i = 0; i < lenght; i++)
        fprintf(fout, "%d ", array[i]);

    free(array);
    fclose(fin);
    fclose(fout);
    return 0;
}

void Swap(int *item1, int *item2) {
    int buf;
    buf = *item1;
    *item1 = *item2;
    *item2 = buf;
}

// Пирамидальная сортировка
int HeapSort(int *arr, int lenght) {
    int mid, last = lenght - 1, amountComp = 0;
    while (last > 0) {
        mid = last / 2; // теперь на последнем месте стоит максимальный элемент, его больше не трогаем
        for (int i = mid; i >= 1; i--) { // и проходимся по коротким ветвям
            if (arr[i - 1] < arr[2 * i - 1])
                Swap(&arr[i - 1], &arr[2 * i - 1]);
            if (2 * i < lenght && arr[i - 1] < arr[2 * i])
                Swap(&arr[i - 1], &arr[2 * i]);
        }
        amountComp += 2 * mid;
        Swap(&arr[0], &arr[last]);
        last--;
    }
    return amountComp;
}

// Сортировка Шелла
int ShellSort(int *arr, int lenght) {
    int mid, last = lenght - 1, amountComp = 0;
    while (last > 0) {
        mid = last / 2; // теперь на последнем месте стоит максимальный элемент, его больше не трогаем
        for (int i = mid; i >= 1; i--) { // и проходимся по коротким ветвям
            if (arr[i - 1] < arr[2 * i - 1])
                Swap(&arr[i - 1], &arr[2 * i - 1]);
            if (2 * i < lenght && arr[i - 1] < arr[2 * i])
                Swap(&arr[i - 1], &arr[2 * i]);
        }
        amountComp += 2 * mid;
        Swap(&arr[0], &arr[last]);
        last--;
    }
    return amountComp;
}