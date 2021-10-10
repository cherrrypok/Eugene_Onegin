#include "additional_functions.h"

int min (int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int swap (struct String* lineptr, int a, int b)
{
    struct String tmp = lineptr[b];
    lineptr[b] = lineptr[a];
    lineptr[a] = tmp;
}

int Length_string (char* str)
{
    int len = 0;
    while (str[len++] != '\0')
        ;
    return --len;
}

int SizeTextFile_char (FILE* file) //assert
{
    fseek (file, 0, SEEK_END);
    int sizeText = ftell (file);
    fseek (file, 0, SEEK_SET);

    return sizeText;
}

int SizeTextFile_string (char* text)
{
    int count = 0, index = 0;
    while (text[index] != '\0'){
        if (text[index] == '\n')
            count++;
        index++;
    }
    return ++count;
}


char* To_lower (char* str)
{
    int len = Length_string (str);
    char* res = (char *)calloc (len + 1, sizeof (char));
    int i = 0;
    for (i; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            res[i] = str[i] - 'A' + 'a';
        else
            res[i] = str[i];
    }
    res[i] = '\0';
    return res;
}
