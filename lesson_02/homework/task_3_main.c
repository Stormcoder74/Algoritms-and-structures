/* Исполнитель «Калькулятор» преобразует целое число, записанное на экране.
 * У исполнителя две команды, каждой присвоен номер:
 *   1(здесь 0). Прибавь 1.
 *   2(здесь 1). Умножь на 2.
 *   Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.
 *   Сколько существует программ, которые число 3 преобразуют в число 20?*/
//Она вскипятила мне мозг
//https://github.com/Stormcoder74/Algoritms-and-structures.git

#include <stdio.h>
#include <math.h>
#include <string.h>

int const GOAL = 20;
int const START = 3;

// Поиск.
// x - преобразуемое в двоичное представление число
// sings - кол-во знаков в итоговой строке(влияет на кол-во "незначащих" нулей)
// start - аккумулятор
// oper - строка с искомой комбинацией операций
int find(int x, int *signs, int *start, char *oper) {
    if (x / 2) {    // делим пока не 0
        *signs = *signs - 1;    // декрементируем кол-во знаков
        int result = find(x / 2, signs, start, oper);   // вызываем рекурсивно
        if (result == 1) return 1;  // проверяем результат
        if (result == -1) return -1;
    }

    for (int i = 1; i < *signs; ++i) {  // добавляем "незначащие"(но очень важные в данном случае) нули
        strcat(oper, "0");
        *start = *start + 1;
        if (*start == GOAL) return 1;   // а не пора ли закончить?
        if (*start > GOAL) return -1;
    }

    if (x % 2) {            // добавляем остатки
        *start = *start * 2;
        strcat(oper, "1");
    } else {
        *start = *start + 1;
        strcat(oper, "0");
    }

    if (*start == GOAL) return 1;       // а не пора ли закончить?
    if (*start > GOAL) return -1;
    *signs = 0; // обязательно обнуляем чтобы "важные" нули добавляльсь только в начало строки
    return 0;
}

int main() {
    int counter = 0;                    // главный вопрос: сколько же?
    char *operations[100][20];          // массив строк с правильными последовательностями
    for (int j = 0; j < 100; ++j) {     // его инициализация
        *operations[j] = "";
    }
    for (int length = 4; length <= GOAL - START; length++) { //кол-во используемых команд (не менее 4 в данном случае)
        for (int i = 0; i < pow(2, length); i++) {  // i - число преобразуемое в двоичное представление
            int l = length;
            int s = START;
            char oper[20] = "";         // строка для заполнения операциями
            if (find(i, &l, &s, oper) == 1) {   // если поиск вернул правильную комбинацию
                int no = 1;                     // добавляем ее в массив правильных ответов
                for (int j = 0; j < counter; j++) { // дубликатов возвращается очень много приходится фильтровать
                    if (strcmp(oper, (char *) operations[j]) == 0) {
                        no = 0;
                        break;
                    }
                }
                if (no) {   // если дубликаты не найдены, то добавляем
                    strcpy((char *) operations[counter], oper);
                    counter++;
                }
            }
        }
    }
    printf("%d \n\n", counter); // вывод результатов
    for (int k = 0; k < counter; ++k) {
        printf("%s\n", (char *) operations[k]);
    }
    return 0;
}
// PS ужасна работа со строками в си...