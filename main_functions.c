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

int Unit_tests(struct String* lineptr) {
    for (int i = 0; i < 10; i++)
        printf("%d, %p, %s\n", lineptr[i].len, lineptr[i].str, lineptr[i].str);
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

int Unit_tests_Comp(struct String* lineptr, enum Types_of_Sorting type){
    struct String a, b;
    a.str = "And yet don't look too good, nor talk too wise:";
    a.len = length_string(a.str);
    b.str = "Or being lied about, don't deal in lies,";
    b.len = length_string(b.str);

    int res = Comp_strings(a, b, type);
    if (res < 0)
        printf("%s < %s\n", a.str, b.str);
    else if (res == 0)
        printf("%s = %s\n", a.str, b.str);
    else
        printf("%s > %s\n", a.str, b.str);
}
