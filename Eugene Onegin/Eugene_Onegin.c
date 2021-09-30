#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 5000
#define MAXLINES 9999

struct String {
    char* str;
    int len;
};

int getline(char* s, int maxsize, FILE *File);
int min(int a, int b);
int swap(struct String* lineptr, int a, int b);
int length_string(char* str);

int Read_strings(struct String* lineptr, int maxsize, int* lines, FILE *File);
int Write_strings(struct String* lineptr, int* lines);
int quicksort(struct String* lineptr, int left, int right, int type);
int partition(struct String* lineptr, int left, int right);
int Comp_strings(struct String a, struct String b, int type); // <0 a < b  >0 a >b

int Unit_tests(struct String* lineptr); //1 - сортировка с начала 2 - сортировка с конца
int Unit_tests_Comp(struct String* lineptr, int type);


int main() {
    FILE *File = fopen("text_input.txt", "r");
    int lines = 0, type = 1;
    struct String lineptr[MAXLINES];

    Read_strings(lineptr, MAXLINES, &lines, File);
    quicksort(lineptr, 0, lines, 2);
    Write_strings(lineptr, &lines);
    //printf("%d\n", lines);
    //Unit_tests(lineptr);
    //Unit_tests_Comp(lineptr, type);
}

int Unit_tests(struct String* lineptr) {
    for (int i = 0; i < 10; i++) {
        printf("%d, %p, %s\n", lineptr[i].len, lineptr[i].str, lineptr[i].str);
    }

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
    return len;
}

int Read_strings(struct String* lineptr, int maxsize, int* lineptr_index, FILE *File) {
    int len = 0;
    char* line = (char*)calloc(MAXLINE, sizeof(char));
    //printf("%p %s\n", line, line);

    while (--maxsize, (len = getline(line, MAXLINE, File)) > 0) {
        lineptr[*lineptr_index].str = line;
        lineptr[*lineptr_index].len = len;
        //printf("%d, &d\n", sizeof(line), sizeof(lineptr[lineptr_index++]));
        //printf("%p %s %d\n", line, line, len);
        //printf("%d, %p, %s\n", lineptr[*lineptr_index].len, lineptr[*lineptr_index].str, lineptr[*lineptr_index].str);

        ++* lineptr_index;
        line = calloc(MAXLINE, sizeof(char));
    }
}

int Write_strings(struct String* lineptr, int* lines) {
    for (int i = 0; i < *lines; i++)
        printf("%s", lineptr[i].str);
}

int quicksort(struct String* lineptr, int left, int right, int type){
    struct String tmp; //!!инициализация
    for (int i = left; i < right; i++){
        for(int j = i + 1; j < right; j++){
            if (Comp_strings(lineptr[i], lineptr[j], type) > 0)
                swap(lineptr, i, j);
        }
    }
}

int Comp_strings(struct String struct_a, struct String struct_b, int type){
    char* a = struct_a.str;
    char* b = struct_b.str;
    int i = 0;
    if (type == 1) {
        for (i = 0; a[i] == b[i]; i++){
            if (a[i] == '\0')
                return 0;
        }
        return a[i] - b[i];
    }

    if (type == 2) {
        int i_a = length_string(a);
        int i_b = length_string(b);
        int index = min(i_a, i_b);
        //printf("%d", index);
        for (i = index; i > 0 && a[i_a] == b[i_b]; i--){
            i_a--;
            i_b--;
            if (i == 0)
                return 0;
        }
        return a[i_a] - b[i_b];
    }
}

int Unit_tests_Comp(struct String* lineptr, int type){
    struct String a, b;
    a.str = "babc"; a.len = 4;
    b.str = "abc"; b.len = 3;
    int res = Comp_strings(a, b, 1);
    if (res < 0)
        printf("%s < %s\n", a.str, b.str);
    else if (res == 0)
        printf("%s = %s\n", a.str, b.str);
    else
        printf("%s > %s\n", a.str, b.str);
}
