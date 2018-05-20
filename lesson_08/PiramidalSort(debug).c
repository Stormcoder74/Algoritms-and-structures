#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Swap(int *, int *);
int HeapSort(int *, int);

const int MAX = 1024;

int main(void) {
    int *array, amountCompare, lenght;
    FILE *fin, *fout;
    fin = fopen("input.txt", "r");

//    for(int i = 0; i < 200; i++){
//        int new = (int) random() % 100;
//        fprintf(fin, "%d ", new);
//    }

    fout = fopen("output.txt", "w");
    array = (int *) malloc(MAX * sizeof(int)); // выделяем память
    int j = 0;
    while (fscanf(fin, "%d", &array[j]) == 1)
        j++;
    lenght = j;
    amountCompare = HeapSort(array, lenght); // количество сравнений
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
    int mid, last = lenght - 1, amountComp;
//    mid = lenght / 2; // середина массива
//    for (int i = mid; i >= 1; i--) {
//        if (arr[i - 1] < arr[2 * i - 1]) // условие сравнения, которое соответствует пирам. сортировке
//            Swap(&arr[i - 1], &arr[2 * i - 1]);
//        if (2 * i < lenght && arr[i - 1] < arr[2 * i]) // если lenght-нечетное
//            Swap(&arr[i - 1], &arr[2 * i]);
//    }
//
//    for(int i = 0; i < lenght; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//
//    amountComp = 2 * mid;
//    Swap(&arr[0], &arr[last]);
//    last--;
    while (last > 0) {
        mid = last / 2; // теперь на последнем месте стоит максимальный элемент, его больше не трогаем
        for (int i = mid; i >= 1; i--) { // и проходимся по коротким ветвям
            if (arr[i - 1] < arr[2 * i - 1])
                Swap(&arr[i - 1], &arr[2 * i - 1]);
            if (2 * i < lenght && arr[i - 1] < arr[2 * i])
                Swap(&arr[i - 1], &arr[2 * i]);
        }

        for(int i = 0; i < lenght; i++)
            printf("%d ", arr[i]);
        printf("\n");

        amountComp += 2 * mid;
        Swap(&arr[0], &arr[last]);

        for(int i = 0; i < lenght; i++)
            printf("%d ", arr[i]);
        printf("\n");

        last--;
    }
//    if (lenght > 0 && arr[0] > arr[1]) // самое последнее сравнение: нулевого с первым элементом
//        Swap(&arr[0], &arr[1]);
//    amountComp++;
    return amountComp;
}