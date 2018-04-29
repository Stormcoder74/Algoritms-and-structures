#include <stdio.h>
#include <math.h>
#include <string.h>

int const GOAL = 20;
int const START = 3;

int find(int x, int *signs, int *start, char *oper) {
    if (x / 2) {
        *signs = *signs - 1;
        int result = find(x / 2, signs, start, oper);
        if (result == 1) return 1;
        if (result == -1) return -1;
    }
    for (int i = 1; i < *signs; ++i) {
//        printf("%d", 0);
        strcat(oper, "0");
        *start = *start + 1;
        if (*start == GOAL) return 1;
        if (*start > GOAL) return -1;

    }
//    printf("%d", x % 2);
    if (x % 2) {
        strcat(oper, "1");
    } else
        strcat(oper, "0");
    if (x % 2)
        *start = *start * 2;
    else
        *start = *start + 1;
    if (*start == GOAL) return 1;
    if (*start > GOAL) return -1;
    *signs = 0;
    return 0;
}

int main() {
    int counter = 0;
    char *operations[100][20];
    for (int j = 0; j < 100; ++j) {
        *operations[j]="";
    }
    for (int length = 4; length < GOAL - 3 +1; length++) {
        for (int i = 0; i < pow(2, length); i++) {
            int l = length;
            int s = START;
            char oper[20] = "";
            if (find(i, &l, &s, oper) == 1) {
                int no = 1;
                for (int i = 0; i < counter; i++) {
                    if (strcmp(oper, operations[i]) == 0) {
                        no = 0;
                        break;
                    }
                }
                if(no){
                    strcpy(operations[counter], oper);
                    counter++;
                }
            }
//            printf(" %d\n", s);
        }
//        printf("\n");
    }
    printf("%d\n\n", counter);
    for (int k = 0; k < counter; ++k) {
        printf("%s\n", operations[k]);
    }
    return 0;
}