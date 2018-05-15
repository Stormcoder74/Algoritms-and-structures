//https://github.com/Stormcoder74/Algoritms-and-structures.git
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[128];
    int age;
    int number;
} Student;

typedef struct Node {
    Student *student;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Создание нового узла
Node *getFreeNode(Student *student, Node *parent) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->student = student;
    tmp->parent = parent;
    return tmp;
}

// Вставка узла
void insert(Node **head, Student *student) {
    Node *tmp = NULL;
    if (*head == NULL) {
        *head = getFreeNode(student, NULL);
        return;
    }
    tmp = *head;
    while (tmp) {
        if (student->number > tmp->student->number) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(student, tmp);
                return;
            }
        } else if (student->number < tmp->student->number) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(student, tmp);
                return;
            }
        } else {
            exit(2); // дерево построено неправильно
        }
    }
}

void printStudent(Student *student){

}

// поиск в двоичном дереве поиска
Student *find(Node *root, int number) {
    if (root) {
        if (number == root->student->number) return root->student;
        if (number < root->student->number) {
            Student *student = find(root->left, number);
            if (student) return student;
        }
        if (number > root->student->number) {
            Student *student = find(root->right, number);
            if (student) return student;
        }
    }

    return NULL;
}

int main() {
    Node *tree = NULL;
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        puts("Can't open file!");
        exit(1);
    }
    int count;
    fscanf(file, "%d", &count); // Считываем количество записей
    int i;
    for (i = 0; i < count; i++) {
        char name[64] = "";
        Student *student = (Student *) malloc(sizeof(Student));
        fscanf(file, "%s", student->name);
        fscanf(file, "%i", &student->age);
        fscanf(file, "%i", &student->number);
        insert(&tree, student);
    }
    fclose(file);

    Student *st = find(tree, 4659);
    printf("\n\nStudent %s, %d, %d, student->name, student->age, student->number");
    return 0;
}