#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* malloc(0) неопределённое поведение
 *
 * realloc(size / 2) попытка уменьшить массив с помощью реаллок приводит неопределённое поведение
 *
 * Возвращать указатель на локальный массив нельзя!
 *
 * int func(T arg, ...)
 *
 * Для функции с приёмом неизвестного числа аргументов, подключаем библиотеку stdarg.h (возможно надо подключить stdlib.h
 * va_list
 * va_start \
 * vs_arg    |- Макросы
 * vs_end   /
 * */

#define va_start(ap, parm) (ap) = (char*)(&(parm + 1)) // parm - последний явно переданный аргумент
// Замена в тексте кода
#define sqr(a, b) (a) * (b);
// Обязательно скобки явно, можно получить непредвиденное поведение

#define va_arg(ap, type) ((type*)((char*)(ap) += sizeof(type)))[-1] // Считывание очередного аргумента типа type
// [-1] - берём элемент до той ячейки памяти предыдущего элемента
// int x; x = va_arg(ap, int);
// 0 может быть в конце, а может и не быть, поэтому надеяться, что оно само ограничится не приходится
// va_list - не типизированный указатель на память

// Пример 1
double Foo(double x, int y) {
    //...
    return x; // ?
}

/* Динамический массив
 * Сохраняем строки в дин. массив.
 * Строки поступают от пользователя
 * Количество строк неизвестно и длина каждой не более BUFSIZE
 * Конец ввода: "STOP"
 * Вывести все введенные строки
 * */
/* Структура в С
 * Тип данных с разнотипными переменными
 * */
// Пример  3

struct MySrt{ // Объявление типов данных, переменных таких нет.
    int x, y;
    char ch;
    double d;
    char s[256];
    int* pint;
};
struct My{
    int x;
    char ch;
}; // Примерный размер sizeof(My)

// Объединение в С
union MyUn{ // объявления объединения - все поля размещаются вместе
    float f;
    int x;
    char s[4];

};

int main(void) {
    // пример 1
//    double(*pf)(double, int);
//    double y;
//    pf = Foo;
//    y = pf(0.5, 4); // разыменование указателя и передачи аргументов в функцию
//    double(*pArr[10])(double, int);
//    y = pArr[2](1.5, 10);

     //Пример 2
    char** pArr = (char **) malloc(2 * sizeof(char *) );
    if (pArr == NULL) return 1;
    char buf[BUFSIZ];
    int i = 0, j, count = 2;
    // Считывание строк
    while (1){
        printf("Input string:\n");
        gets(buf);
        if (!strcmp(buf, "STOP")) break;

        if (i == count){
            count *= 2;
            char** ptr = (char **) realloc(pArr, count * sizeof(char*)); // А вдруг релок всё сломает, нужна проверка
            if (ptr == NULL){
                printf("Alloc Error!!!\n");
                for (j = 0; j < i; j++){
                    free(pArr[j]);
                }
                free(pArr);
                return -1;
            }
            pArr = ptr;
        }
        i++;
        pArr[i - 1] = (char *) malloc((strlen(buf) + 1) * sizeof(char)); // Тут тоже проверка
        if (pArr[i - 1] == NULL) {
            printf("Alloc Error!!!\n");
            for (j = 0; j < i - 1; j++){
                free(pArr[j]);
            }
            free(pArr);
            return -1;
        }
        strcpy(pArr[i - 1], buf);
    }
    // Печать строк
    for (j = 0; j < i; ++j){
        printf("%s\n", pArr[j]);
    }
    // Освобождение памяти
    for (j = 0; j < i; j++){
        free(pArr[j]);
    }
    free(pArr);
    // Пример 3: Объявление переменной нашего типа
//    struct MySrt st;
//    st.x = 10;
//    st.y = st.x + 2;
//    strcpy(st.s, "Hello!");
//    //Пример 4
//    int i = 0;
//    union MyUn u;
//    u.x = 233;
//    u.f = -1.5;
//    while (i < 4){
//        printf("%x", u.s[i++]);
//    }
//    struct MySrt* pStr = NULL;
//    pStr = &st;
//    (*pStr).y = 100;
//    pStr->y = 500; //Если указатель используеме ->
//    // Самоссылочные структуры
//    // В структурах разрешено иметь тип данных указатель на эту же структуру. тип самой структуры иметь нельзя.
//    struct Node{
//        int data;
//        struct Node* pNode;
//    };
    // Односвязные списком(однонаправленным списком) называется структура данных, которая является набором элементов
    // следующего типа:
    // В каждом элементе есть поле "данные"
    // указатель на следующий элемент




    return 0;
}
