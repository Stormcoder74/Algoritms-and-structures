//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <stdlib.h>

#define T char

struct TNode {
    T value; // Данные
    struct TNode *next; // Указатель на следующий элемент списка
};
typedef struct TNode Node;
Node *head = NULL;

void Push(T value) {
    Node *temp;
    temp = (Node *) malloc(sizeof(Node));
    temp->value = value;
    temp->next = head;
    head = temp;
}

T Pop() {
    Node *temp = NULL;
    T value = head->value;
    temp = head;
    head = head->next;
    free(temp);
    return value;
}

void toOutput(char *output, char *el, int *index) {
    int i = 0;
    while (el[i] != '\0') {
        output[*index] = el[i];
        i++;
        *index += 1;
    }
    output[*index] = ' ';
    *index += 1;
}

int isNumber(char *str) {
    int i = 0;
    while (str[i] != '\0')
        if (!isdigit(str[i++]))
            return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    char input[100] = "3 + 23 * 4 - ( 45 + 32 ) / 6"; // входная строка
    char output[100] = ""; // выходная строка
    int outIndex = 0;

    for (int i = 0; i < strlen(input); i++) {
        char el[20]; // элемент(число или операция)
        int j = 0;
        while (input[i] != ' ' && input[i] != '\0') {
            el[j] = input[i];
            j++;
            i++;
        }
        el[j] = '\0';
// Если элемент Число
        if (isNumber(el))
            toOutput(output, el, &outIndex);
        else {
            switch (el[0]) {
                case '+':

                    break;
                case '-':

                    break;
                case '*':

                    break;
                case '/':

                    break;
                default:
                    break;
            }
        }
    }
    printf("%d", Pop());
    getchar();
    return 0;
}