#include "function.h"

struct String {
    char* str;
    int len;
};

enum Types_of_Sorting {
    SORTING_FROM_THE_BEGIN,
    SORTING_FROM_THE_END,
    SORTING_FROM_POINTERS
};

int Output_Result(struct String* lineptr, int maxsize, int* lines, FILE *File){
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

int getline(char* s, int maxsize, FILE *File) {
    char c;
    int i = 0;
    while (maxsize-- && (c = getc(File)) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return --i;
}

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

int next_letter(char* str, int* i){
    while ((str[*i] >= 'A' && str[*i] <= 'Z' || str[*i] >= 'a' && str[*i] <= 'z') == 0)
        --*i;
    return str[*i];
}

int sizeTextFile_in_Char(FILE* File){
    fseek(File, 0, SEEK_END);
    int sizeText = ftell(File);
    fseek(File, 0, SEEK_SET);

    return sizeText;
}

int Read_strings(struct String* lineptr, int maxsize, int* lineptr_index, FILE *File) {
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

int quicksort(struct String* lineptr, int left, int right, enum Types_of_Sorting type){
    if (left < right){
        int mid = partition(lineptr, left, right, type);
        quicksort(lineptr, left, mid, type);
        quicksort(lineptr, mid + 1, right, type);
    }
}

int partition(struct String* lineptr, int left, int right, enum Types_of_Sorting type){
    struct String mid = lineptr[(left + right) / 2];
    while (left <= right){
        while(Comp_strings(lineptr[left], mid, type) < 0)
            left++;
        while(Comp_strings(lineptr[right], mid, type) > 0)
            right--;
        if (left >= right)
            break;
        swap(lineptr, left++, right--);
    }
    return right;
}

int Comp_strings(struct String struct_a, struct String struct_b, enum Types_of_Sorting type){
    char* a = struct_a.str;
    char* b = struct_b.str;
    int i = 0;
    if (type == SORTING_FROM_THE_BEGIN) {
        for (i = 0; a[i] == b[i]; i++){
            if (a[i] == '\0')
                return 0;
        }
        return a[i] - b[i];
    }

    if (type == SORTING_FROM_THE_END) {
        int i_a = length_string(a);
        int i_b = length_string(b);

        int index = min(i_a, i_b);
        for (i = index; i > 0 && next_letter(a, &i_a) == next_letter(b, &i_b); i--){
            i_a--;
            i_b--;
            if (i == 0)
                return 0;
        }

        return a[i_a] - b[i_b];
    }

    if (type == SORTING_FROM_POINTERS) {
        return struct_a.str - struct_b.str;
    }
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
