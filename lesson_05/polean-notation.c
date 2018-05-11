//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <stdlib.h>

#define T char

char actionTable[7][8] = {
	{' ', '|', '+', '-', '*', '/', '(', ')'},
	{'|', '4', '1', '1', '1', '1', '1', '5'},
	{'+', '2', '2', '2', '1', '1', '1', '2'},
	{'-', '2', '2', '2', '1', '1', '1', '2'},
	{'*', '2', '2', '2', '2', '2', '1', '2'},
	{'/', '2', '2', '2', '2', '2', '1', '2'},
	{'(', '5', '1', '1', '1', '1', '1', '3'}
};

struct TNode {
    T value; // Данные
    struct TNode *next; // Указатель на следующий элемент списка
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

char selectAction(char stack, char arrow){
	int row = 0, col = 0;
	for (int i = 0; i < 8; i++){
		if(actionTable[0][i] == arrow)
			col = i;
		if(i < 7 && actionTable[i][0] == stack)
			row = i;
	}
	return actionTable[row][col];
}

void printOut(char *output){
	int i = 0;
	while(output[i] != '\0')
		printf("%c", output[i]);
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
        	char c;
            switch (selectAction(head->value, el[0])) {
                case '1':
						push(el[0]);
                    break;
                case '2':
                  c = pop();
                  char arr[] = {c, '\0'};
                  i -= 2;
					toOutput(output, arr, &outIndex);
                    break;
                case '3':
					pop();
                    break;
                case '4':
					printOut(output);
                  return 0;
                case '5':
					printf("Скобки несогласованы");
					return 1;
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}