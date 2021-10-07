#include "main_functions.h"
#include "additional_functions.c"
#include "quicksort.c"

int Output_Result(struct String* lineptr, int* lines, FILE *File){
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

int Read_strings(struct String* lineptr, int* lineptr_index, FILE *File) {
    int sizeText = sizeTextFile_in_Char(File);

    char* Text = (char *)calloc(sizeText, sizeof(char));
    fread(Text, sizeText, sizeof(char), File);

    int len_string = 0, Text_index = 0;

    while(Text[Text_index] != EOF && Text[Text_index] != '\0'){
        if (Text[Text_index] == '\n'){
            lineptr[*lineptr_index].len = len_string;
            lineptr[*lineptr_index].str = Text + Text_index - len_string;
            len_string = 0;
            Text[Text_index] = '\0';

            (*lineptr_index)++;

        }
        else{
            len_string++;
        }

        Text_index++;
    }


    lineptr[*lineptr_index].len = len_string;
    lineptr[*lineptr_index].str = Text + Text_index - len_string;

    return *lineptr_index;
}

int Write_strings(struct String* lineptr, int* lines) {
    for (int i = 0; i < *lines; i++)
        printf("%s\n", lineptr[i].str);
}

int Unit_tests() {
    FILE *File1_IN = fopen("Unit1_IN.txt", "r");
    FILE *File1_Result = fopen("Unit1_IN.txt", "w");
    FILE *File1_OUT = fopen("Unit1_OUT.txt", "r");

    //FILE *File2 = fopen("Unit_test2.txt", "r");
    //FILE *File3 = fopen("Unit_test3.txt", "r");
}
