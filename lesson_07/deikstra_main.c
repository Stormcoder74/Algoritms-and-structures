#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int graph[5][5] = {
        {0, 2, 5, 0, 7},
        {2, 0, 1, 0, 0},
        {5, 1, 0, 5, 1},
        {0, 0, 5, 0, 3},
        {7, 0, 1, 3, 0}
};

typedef struct Vertex {
    char name;
    int index;
    int pathLenght;
} Vertex;


int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        puts("Can't open file!");
        exit(1);
    }
    int count;
    fscanf(file, "%d", &count); // Считываем количество вершин
    Vertex *vertexes = (Vertex *) malloc(count * sizeof(Vertex));
    int *graph = (int *) malloc(count * count * sizeof(int));
    char name = 'A';
    for (int i = 0; i < count; ++i) {
        (vertexes + i)->name = name;
        (vertexes + i)->index = i;
        (vertexes + i)->pathLenght = 0;
        name++;
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            fscanf(file, "%d", graph + i * count + j);
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%d", *(graph + i * count + j));
        }
        printf("\n");
    }
    fclose(file);
    printf("Hello, World!\n");
    return 0;
}