#include <stdio.h>
#include <stdlib.h>
#include "main_functions.c"

int main () 
{
    char* file_name = "text_input.txt";
    int lines = 0;
    struct String* lineptr = Ctor (file_name, &lines);

    Output_result (lineptr, &lines);
    return 0;
}
