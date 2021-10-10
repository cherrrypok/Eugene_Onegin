#include "main_functions.h"
#include "additional_functions.c"
#include "Quicksort.c"

struct String* Ctor (char *file_name, int *count_strings) //аргумент комaндой строки.
{
    FILE *file = fopen (file_name, "r"); //проверка на возврат.

    int count_chars = SizeTextFile_char (file);
    char* text = (char *)calloc (count_chars, sizeof (char)); //везде проверять на корректность ввода
    fread (text, count_chars, sizeof (char), file); //fread returns?! если вернул больше MAXLINES

    *count_strings = SizeTextFile_string (text);
    struct String* lineptr = (struct String *)calloc (*count_strings, sizeof(struct String));
    Read_strings (lineptr, text);

    fclose (file);
    return lineptr;
}

int Read_strings (struct String* lineptr, char *text){
    int len_string = 0, text_index = 0, lineptr_index = 0;

    while(text[text_index] != '\0'){
        if (text[text_index] == '\n')
        {
            lineptr[lineptr_index].len = len_string;
            lineptr[lineptr_index].str = text + text_index - len_string;

            len_string = 0;
            text[text_index] = '\0';
            //Батюшка, вы уж либо крестик снимите, либо трусы наденьте.
            //!TODO снять крестик
            lineptr_index++;
        }
        else
        {
            len_string++;
        }

        text_index++;
    }


    lineptr[lineptr_index].len = len_string;
    lineptr[lineptr_index].str = text + text_index - len_string;
}

int Output_result (struct String* lineptr, int* lines)
{
    printf ("***1\n");
    Quicksort (lineptr, 0, *lines - 1, SORTING_FROM_THE_BEGIN);
    Write_strings (lineptr, lines);

    printf ("\n");

    printf ("***2\n");
    Quicksort (lineptr, 0, *lines - 1, SORTING_FROM_THE_END);
    Write_strings (lineptr, lines);

    printf ("\n");

    printf ("***3\n");
    Quicksort (lineptr, 0, *lines - 1, SORTING_FROM_POINTERS);
    Write_strings (lineptr, lines);
}

int Write_strings (struct String* lineptr, int* lines)
{
    for (int i = 0; i < *lines; i++)
        printf ("%s\n", lineptr[i].str); //fprintf <- slow, fwrite <- fast
}
