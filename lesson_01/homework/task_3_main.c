#include <stdio.h>
#include <time.h>

int const N = 500000; // не пойму почему при бОльших значениях программа совсем не работает и ошибок не дает

int main() {
    int arr[N];
    for (int i = 2; i < N; i++) {
        arr[i] = 1;
    }

    int time1 = (int) clock ();

    for (int i = 2; i * i < N; i++) {
        if (arr[i] == 1) {
            for (int j = i * i; j < N; j = (i == 2) ? (j + i) : (j + 2 * i)) {
                if (arr[j] == 1) {
                    arr[j] = 0;
                    //printf("i = %d, j = %d\n", i, j);
                }
            }
        }
    }

    for (int i = N - 1; i > 2; i--) {
        if (arr[i]) {
            printf("Максимальное простое число в диапазоне от 2 до %d: %d\n", N, i);
            printf("Вычисления заняли %d милисекунд\n", (int) (clock () - time1));
            break;
        }
    }
    /*for (int i = 2; i < N; i++) {
        if (arr[i]) printf("%5d", i);
        if (i % 100 == 0) printf("\n");
    }*/
    return 0;
}

