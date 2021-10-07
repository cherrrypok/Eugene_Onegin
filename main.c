#include <stdio.h>
#include <stdlib.h>
#include "main_functions.c"

#define MAXLINES 9999

int main() {
    FILE *File = fopen("text_input_punctuation.txt", "r");
    int lines = 0;
    struct String lineptr[MAXLINES];

    Read_strings(lineptr, &lines, File);
    Output_Result(lineptr, &lines, File);
    printf("Hm OK&");
}
