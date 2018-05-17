#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX 1000000

enum Status {
    NONE, VISITED
};
typedef enum Status Status;

typedef struct Vertex {
    char name;      // имя вершины
    Status status;  // состояние
    int pathLenght; // длина пути к ней
} Vertex;

// поиск среди непосещенных вершины с минимальным путем
// возвращаем индекс вершины или -1 в случае отсутствия таковых
int minVertex(Vertex *vertexes, int size) {
    int min = MAX;
    int index = -1;
    for (int i = 0; i < size; i++) {
        if ((vertexes + i)->status == NONE &&
            (vertexes + i)->pathLenght < min) {
            min = (vertexes + i)->pathLenght;
            index = i;
        }
    }
    return index;
}

// вывод результатов
void printVertexes(Vertex *vertexes, int size) {
    for (int i = 0; i < size; i++) {
//        char *st = "VISITED";   // отладочная информация
//        if ((vertexes + i)->status == NONE) st = "NONE";
//        printf("%c(%d)(%s), ", (vertexes + i)->name, (vertexes + i)->pathLenght, st);
        printf("%c(%d), ", (vertexes + i)->name, (vertexes + i)->pathLenght);
    }
    printf("\n\n");
}

int main() {
    FILE *file = fopen("data2.txt", "r");    // открываем файл
    if (file == NULL) {
        puts("Can't open file!");
        exit(1);
    }
    int size = 0;
    fscanf(file, "%d", &size); // читаем количество вершин
    Vertex *vertexes = (Vertex *) malloc(size * sizeof(Vertex));// создаем массив вершин
    int *graph = (int *) malloc(size * size * sizeof(int)); // создаем матрицу смежности
    char name = 'A';    // инициализация массива вершин
    for (int i = 0; i < size; ++i) {
        (vertexes + i)->name = name + i;
        (vertexes + i)->status = NONE;
        (vertexes + i)->pathLenght = MAX;
    }
    for (int i = 0; i < size; i++) {        // чтение из файла матрицы смежности
        for (int j = 0; j < size; j++) {
            int tmp;
            fscanf(file, "%d", &tmp);
            if (tmp == 0) *(graph + i * size + j) = MAX;
            else *(graph + i * size + j) = tmp;
        }
    }
    fclose(file);

    char start = 'G';   // определяем начальную вершину
    printf("Начинаем с вершины %c\n", start);
    int current = start - 'A';  // назначаем ее текущей

    // собственно алгоритм
    (vertexes + current)->pathLenght = 0;           // путь до начала - 0
    while (current >= 0) {                          // пока есть непосещенные
        (vertexes + current)->status = VISITED;     // текущую отмечаем как посещенную
        for (int i = 0; i < size; i++) {            // перебираем элементы строки текущей вершины в матрице
            int tmpLenght = (vertexes + current)->pathLenght + *(graph + current * size + i);   // считаем расстояние до других вершин
            // несмежные вершины считаем тоже, но т.к. расстояние до них существенно велико они не пройдут следующую проверку
            if (tmpLenght < (vertexes + i)->pathLenght) {   // а до тех, которые пройдут
                (vertexes + i)->pathLenght = tmpLenght;     // мы нашли более короткий путь
            }
        }                                       // далее ищем самую близкую вершину, одновременно проверяя наличие непосещенных
        current = minVertex(vertexes, size);
//        printVertexes(vertexes, size);        // отладочная информация
    }

    printVertexes(vertexes, size);
    return 0;
}