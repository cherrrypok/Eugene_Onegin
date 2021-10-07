#include "additional_functions.h"

int min(int a, int b){
    if (a < b)
        return a;
    return b;
}

int swap(struct String* lineptr, int a, int b){
    struct String tmp = lineptr[b];
    lineptr[b] = lineptr[a];
    lineptr[a] = tmp;
}

int length_string(char* str){
    int len = 0;
    while(str[len++] != '\0')
        ;
    return --len;
}

int sizeTextFile_in_Char(FILE* File){
    fseek(File, 0, SEEK_END);
    int sizeText = ftell(File);
    fseek(File, 0, SEEK_SET);

    return sizeText;
}
