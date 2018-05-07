#include <stdio.h>
#include <malloc.h>

#define T char
// Опишем структуру узла списка
struct TNode {
    T value;
    struct TNode *next;
    struct TNode *prev;
};
typedef struct TNode Node;

struct Deck {
    Node *head;
    Node *tail;
    int size;
    int maxSize;
};
struct Deck deck;

enum Direction {
    HEAD_TAIL, TAIL_HEAD
};
typedef enum Direction Direction;

void push(T value, Direction dir) {
    if (deck.size >= deck.maxSize) {
        printf("Error deck size");
        return;
    }
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->value = value;
    if (deck.size == 0) {
        tmp->next = NULL;
        tmp->prev = NULL;
        deck.head = tmp;
        deck.tail = tmp;
    } else if (dir == HEAD_TAIL) {
        tmp->next = deck.head;
        tmp->next->prev = tmp;
        deck.head = tmp;
    } else {
        tmp->prev = deck.tail;
        tmp->prev->next = tmp;
        deck.tail = tmp;
    }
    deck.size++;
}

T pop(Direction dir) {
    if (deck.size == 0) {
        printf("deck is empty");
        return NULL;
    }
// Временный указатель
    Node *tmp = NULL;
// Значение "наверху" списка
    T value;
    if (deck.size == 1) {
        value = deck.head->value;
        tmp = deck.head;
        deck.head = NULL;
        deck.tail = NULL;
    } else if (dir == HEAD_TAIL) {
        value = deck.tail->value;
        tmp = deck.tail;
        deck.tail = deck.tail->prev;
        deck.tail->next = NULL;
    } else {
        value = deck.head->value;
        tmp = deck.head;
        deck.head = deck.head->next;
        deck.head->prev = NULL;
    }


// Запись, на которую указывала голова удаляем, освобождая память
    free(tmp);
// Возвращаем значение, которое было в голове
    deck.size--;
    return value;
}

void PrintStack() {
    Node *current = deck.head;
    while (current != NULL) {
        printf("%c ", current->value);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    deck.maxSize = 100;
    deck.head = NULL;
    deck.tail = NULL;
    push('a', HEAD_TAIL);
    push('b', TAIL_HEAD);
    push('c', HEAD_TAIL);
    push('d', TAIL_HEAD);
    push('e', HEAD_TAIL);
    push('f', TAIL_HEAD);
    PrintStack();
    printf("\n");
    return 0;
}