//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int T;
typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node *root) {
    if (root) {
        printf("%d", root->data);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

// Создание нового узла
Node *getFreeNode(T value, Node *parent) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

// Вставка узла
void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        return;
    }
    tmp = *head;
    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        } else {
            exit(2); // дерево построено неправильно
        }
    }
}

// КЛП — «корень–левый–правый» (обход в прямом порядке, pre-order)
void preOrderTravers(Node *root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

// ЛКП — «левый–корень–правый» (симметричный обход, in-order)
void inOrderTravers(Node *root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d ", root->data);
        inOrderTravers(root->right);
    }
}

// ЛПК — «левый–правый–корень» (обход в обратном порядке, post-order)
void postOrderTravers(Node *root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

// поиск в двоичном дереве поиска
int find(Node *root, T data) {
    if (root) {
        if (data == root->data) return 1;
        if(data < root->data)
            if(find(root->left, data)) return 1;
        if(data > root->data)
            if(find(root->right, data)) return 1;
    }
    return  0;
}

int main() {
    Node *tree = NULL;
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        puts("Can't open file!");
        exit(1);
    }
    int count;
    fscanf(file, "%d", &count); // Считываем количество записей
    int i;
    for (i = 0; i < count; i++) {
        char name[64] = "";
        int value;
        fscanf(file, "%d", &value);
        insert(&tree, value);
    }
    fclose(file);
    printTree(tree);
    printf("\nPreOrderTravers:");
    preOrderTravers(tree);
    printf("\nInOrderTravers:");
    inOrderTravers(tree);
    printf("\nPostOrderTravers:");
    postOrderTravers(tree);

    printf("\n\nFind 3: %d", find(tree, 3));
    printf("\nFind 9: %d", find(tree, 9));
    printf("\nFind 13: %d", find(tree, 13));
    return 0;
}