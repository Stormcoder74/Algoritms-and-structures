#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int T;
FILE *file;

typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
} Node;

// Построить идеально сбалансированное дерево с n узлами
Node *Tree(int n) {
    Node *newNode;
    int x, nl, nr;
    if (n == 0)
        newNode = NULL;
    else {
        fscanf(file, "%d", &x);
        nl = n / 2;
        nr = n - nl - 1;
        newNode = (Node *) malloc(sizeof(Node));
        newNode->data = x;
        newNode->left = Tree(nl);
        newNode->right = Tree(nr);
    }
    return newNode;
}

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

int main() {
    Node *tree = NULL;
    file = fopen("d:\\temp\\data.txt", "r");
    if (file == NULL) {
        puts("Can't open file!");
        return 1;
    }
    int count;
    fscanf(file, "%d", &count); // Считываем количество записей
    tree = Tree(count);
    fclose(file);
    printTree(tree);
    return 0;
}