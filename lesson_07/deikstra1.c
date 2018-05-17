#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int graph[5][5] = {
        {1000, 2, 5, 1000, 7},
        {2, 1000, 1, 1000, 1000},
        {5, 1, 1000, 5, 1},
        {1000, 1000, 5, 1000, 3},
        {7, 1000, 1, 3, 1000}
};

enum Status {
    NONE, VISITED
};
typedef enum Status Status;

typedef struct Vertex {
    char name;
    int index;
    Status status;
    int pathLenght;
} Vertex;

int minVertex(Vertex *vertexes){
	int min = 1000;
	int index = -1;
	for(int i = 0; i < 5; i++){
		if((vertexes + i)->status == NONE &&
			(vertexes + i)->pathLenght < min){
				min = (vertexes + i)->pathLenght;
				index = i;
			}
	}
	return index;
}

int main() {
    /*FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        puts("Can't open file!");
        exit(1);
    }*/
    int count = 5;
//    fscanf(file, "%d", &count); // Считываем количество вершин
    Vertex *vertexes = (Vertex *) malloc(count * sizeof(Vertex));
    int *graph = (int *) malloc(count * count * sizeof(int));
    char name = 'A';
    for (int i = 0; i < count; ++i) {
        (vertexes + i)->name = name;
        (vertexes + i)->index = i;
        (vertexes + i)->status = NONE;
        (vertexes + i)->pathLenght = 1000;
        name++;
    }
    /*for (int i = 0; i < count; i++) {
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
    fclose(file);*/
    char start = 'A';
    int current = 0;
    printf("Начинаем с вершины %c\n", start);
    for(int i = 0; i < 5; i++){
    	if((vertexes + i)->name == start){
    		current = (vertexes + i)->index;
    		break;
    	}
    }
    while(current >= 0){
    	(vertexes + current)->status = VISITED;
    	int min = 1000;
    	int minColumn = 0;
    	for(int i = 0; i < count; i++){
    		if((vertexes + i)->pathLenght +
    			(graph + current * count + i) < min){
    			min = (graph + current * count + i);
    			minColumn = i;
    		}
    	}
    	current = minVertex(vertexes);
    }
    printf("Hello, World!\n");
    return 0;
}