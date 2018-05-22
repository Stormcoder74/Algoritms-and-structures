#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int piramidalSort(int *, int);

int shellSort(int *, int);

int quickSort(int *, int, int);

int mergeSort(int *arr, int left, int right);

const int LENGHT = 100;
const int MAX_VALUE = 100;

int main(void) {
    int *array, amountCompare;

    array = (int *) malloc(LENGHT * sizeof(int)); // выделяем память
    for (int i = 0; i < LENGHT; i++) {
        array[i] = (int) random() % MAX_VALUE;
        printf("%d ", array[i]);
    }
    printf("\n");

    amountCompare = piramidalSort(array, LENGHT);     // количество сравнений в пирамидальной сортировке
//    amountCompare = shellSort(array, LENGHT);         // количество сравнений в сортировке Шелла
//    amountCompare = quickSort(array, 0, LENGHT - 1);    // количество сравнений в сортировке Хоара
//    amountCompare = mergeSort(array, 0, LENGHT - 1);  // количество сравнений в сортировке слиянием

    FILE *fout;
    fout = fopen("output.txt", "w");

    fprintf(fout, "Number of elements: %d\nNumber of compares: %d\n", LENGHT, amountCompare);
    fprintf(fout, "Sorted Array:\n");

    for (int i = 0; i < LENGHT; i++)
        fprintf(fout, "%d ", array[i]);

    free(array);
    fclose(fout);
    return 0;
}

void swap(int *item1, int *item2) {
    int buf;
    buf = *item1;
    *item1 = *item2;
    *item2 = buf;
}

// пирамидальная сортировка
int piramidalSort(int *arr, int lenght) {
    int mid, last = lenght - 1, amountComp = 0;
    while (last > 0) {
        mid = last / 2;
        for (int i = mid; i >= 1; i--) {
            if (arr[i - 1] < arr[2 * i - 1])
                swap(&arr[i - 1], &arr[2 * i - 1]);
            if (2 * i < lenght && arr[i - 1] < arr[2 * i])
                swap(&arr[i - 1], &arr[2 * i]);
        }
        amountComp += 2 * mid;
        swap(&arr[0], &arr[last]);
        last--;
    }
    return amountComp;
}

// сортировка Шелла
int shellSort(int *arr, int lenght) {
    int amountComp = 0;
    for (int dist = lenght / 2; dist > 0; dist /= 2)
        for (int i = 0; i + dist < lenght; i++) {
            int tmp = arr[i + dist];
            for (int j = i; j >= 0; j -= dist) {
                amountComp++;
                if (tmp < arr[j]) {
                    arr[j + dist] = arr[j];
                } else
                    break;
                arr[j] = tmp;
            }
        }
    return amountComp;
}

// сортировка Хоара
int quickSort(int *array, int first, int last) {
    int i = first, j = last, base = array[(first + last) / 2], amountComp = 0;
    do {
        while (array[i] < base) {
            amountComp++;
            i++;
        }
        while (array[j] > base) {
            amountComp++;
            j--;
        }
        if (i <= j) {
            if (array[i] > array[j])
                swap(&array[i], &array[j]);
            amountComp++;
            i++;
            j--;
        }
    } while (i <= j);
    if (i < last)
        amountComp += quickSort(array, i, last);
    if (first < j)
        amountComp += quickSort(array, first, j);
    return amountComp;
}

// сортировка слиянием
int mergeSort(int *arr, int left, int right) {
    int amountComp = 0;
    if (left < right) {            // если фрагмент массива состоит более чем из одного элемента
        if (right - left == 1) {   // если фрагмент массива состоит из двух элементов
            if (arr[right] < arr[left])
                swap(&arr[right], &arr[left]);
            amountComp++;
        } else { // разбиваем заданный фрагмент на два массива
            // рекурсивно вызываем функции mergeSort
            int mid = left + (right - left) / 2;
            amountComp += mergeSort(arr, left, mid);
            amountComp += mergeSort(arr, mid + 1, right);

            // Сливаем массивы
            int *tmp = (int *) malloc((right - left) * sizeof(int)); // выделяем память под временный массив
            for (int i = left, j = mid + 1, k = 0; k <= right - left;) {
                if ((i <= mid && arr[i] <= arr[j]) || j > right)
                    tmp[k] = arr[i++];
                else
                    tmp[k] = arr[j++];
                amountComp++;
                k++;
            }
            for (int i = left; i <= right; i++) {
                arr[i] = tmp[i - left];
                printf("%d ", arr[i]);
            }
            printf("\n");
            free(tmp);
        }
    }
    return amountComp;
}