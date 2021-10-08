#include "main_functions.h"
#include "additional_functions.c"
#include "quicksort.c"

char* Ctor(FILE *file, int *count_strings){
    int count_chars = sizeTextFile_in_Char(file);

    char* text = (char *)calloc (count_chars, sizeof(char)); //везде проверять на корректность ввода
    fread(text, count_chars, sizeof(char), file); //fread returns?! если вернул больше MAXLINES
    *count_strings = sizeTextFile_in_string(text);
    struct String lineptr[*count_strings] = {};

    return Read_strings(lineptr, count_strings, text);
}

int Read_strings(struct String* lineptr, int* lineptr_index, char *text){
    int len_string = 0, text_index = 0;

    while(text[text_index] != '\0'){
        if (text[text_index] == '\n'){
            lineptr[*lineptr_index].len = len_string;
            lineptr[*lineptr_index].str = text + text_index - len_string;
            len_string = 0;
            text[text_index] = '\0';
            //Батюшка, вы уж либо крестик снимите, либо трусы наденьте.
            //!TODO надеть трусы
            (*lineptr_index)++;

        }
        else{
            len_string++;
        }

        text_index++;
    }


    lineptr[*lineptr_index].len = len_string;
    lineptr[*lineptr_index].str = text + text_index - len_string;

    return *lineptr_index;
}

int Output_Result(struct String* lineptr, int* lines, FILE *file){
    printf("***1\n");
    quicksort(lineptr, 0, *lines - 1, SORTING_FROM_THE_BEGIN);
    Write_strings(lineptr, lines);

    printf("\n");

    printf("***2\n");
    quicksort(lineptr, 0, *lines - 1, SORTING_FROM_THE_END);
    Write_strings(lineptr, lines);

    printf("\n");

    printf("***3\n");
    quicksort(lineptr, 0, *lines - 1, SORTING_FROM_POINTERS);
    Write_strings(lineptr, lines);
}

int Write_strings(struct String* lineptr, int* lines){
    for (int i = 0; i < *lines; i++)
        printf("%s\n", lineptr[i].str); //fprintf <- slow, fwrite <- fast
}

int Unit_tests(){
    //FILE *File1_IN = fopen("Unit1_IN.txt", "r");
    //FILE *File1_Result = fopen("Unit1_IN.txt", "w");
    //FILE *File1_OUT = fopen("Unit1_OUT.txt", "r");

    //FILE *File2 = fopen("Unit_test2.txt", "r");
    //FILE *File3 = fopen("Unit_test3.txt", "r");

    //закрывать файлы
}
