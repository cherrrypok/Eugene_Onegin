#include <stdio.h>
#include <stdlib.h>
#include "main_functions.c"

#define MAXLINES 9999

int main() {
    /*
    FILE *file = fopen("text_input_punctuation.txt", "r"); //проверка на возврат. с маленькой. аргумент комендой строки. Ctor
    int lines = 0;
    struct String lineptr[MAXLINES] = {}; //размер через файл
    */
    FILE *file = fopen("text_input_punctuation.txt", "r"); //проверка на возврат. с маленькой. аргумент комендой строки. Cto
    int lines = 0;
    struct String* lineptr = Ctor(file, &lines);
    printf("1\n");
    printf("%p\n", lineptr);

    Output_Result(lineptr, &lines, file);
    return 0;
}
