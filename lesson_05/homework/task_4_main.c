//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#define T char

char actionTable[7][8] = { // матрица приоритета операторов
        {' ', '|', '+', '-', '*', '/', '(', ')'},
        {'|', '4', '1', '1', '1', '1', '1', '5'},
        {'+', '2', '2', '2', '1', '1', '1', '2'},
        {'-', '2', '2', '2', '1', '1', '1', '2'},
        {'*', '2', '2', '2', '2', '2', '1', '2'},
        {'/', '2', '2', '2', '2', '2', '1', '2'},
        {'(', '5', '1', '1', '1', '1', '1', '3'}
};

struct TNode {
    T value;
    struct TNode *next;
};
typedef struct TNode Node;
Node *head = NULL;

void push(T value) {
    Node *temp;
    temp = (Node *) malloc(sizeof(Node));
    temp->value = value;
    temp->next = head;
    head = temp;
}

T pop() {
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

// выбор действия в соответствии с матрицей приоритета операторов
char selectAction(char stack, char arrow) {
    int row = 0, col = 0;
    for (int i = 0; i < 8; i++) {
        if (actionTable[0][i] == arrow)
            col = i;
        if (i < 7 && actionTable[i][0] == stack)
            row = i;
    }
    return actionTable[row][col];
}

void printOut(char *output) {
    int i = 0;
    while (output[i] != '\0') {
        printf("%c", output[i]);
        i++;
    }
}

int main(int argc, char *argv[]) {
    char input[100] = "| 3 + 23 * 45678 - ( 45 + 32 ) / 6 |"; // входная строка
    char output[100] = "";  // выходная строка
    int outIndex = 0;       // индекс в выходной строке

    for (int i = 0; i < strlen(input); i++) { // i - индекс во входной строке
        char el[20] = "";   // элемент(число или операция)
        int j = 0;          // индекс в элементе

        while (input[i] != ' ' && input[i] != '\0') {
            el[j] = input[i];
            j++;
            i++;
        }

        if (isNumber(el))                   // если элемент - число
            toOutput(output, el, &outIndex);// отправляем его в выходную строку
        else {
            char c; // переменная для временного хранения извлеченного из стека значения
            // если стек пустой первый оператор пушим, для остальных выбираем действие
            switch (head == NULL ? '1' : selectAction(head->value, el[0])) {
                case '1':
                    push(el[0]);
                    break;
                case '2':
                    c = pop();
                    char string[] = {c, '\0'}; // на выход принимается строка, а не символ
                    toOutput(output, string, &outIndex);
                    i -= 2; // остаемся на стрелке на том же символе
                    break;
                case '3':
                    pop();
                    break;
                case '4':
                    printOut(output);
                    return 0;
                case '5':
                    printf("Ошибка: скобки несогласованы!");
                    return 1;
                default:
                    break;
            }
        }
    }
    return 0;
}