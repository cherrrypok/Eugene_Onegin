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
int Read_strings(struct String* lineptr, int maxsize, int* lines, FILE *File);
int Write_strings(struct String* lineptr, int* lines);
int Sorting_strings(struct String* lineptr, int left, int right);
int Comp_strings(struct String a, struct String b, int tipe); // <0 a < b  >0 a >b
int Unit_tests(struct String* lineptr); //1 - сортировка с начала 2 - сортировка с конца
int Unit_tests_Comp(struct String* lineptr, int tipe);


int main() {
    FILE *File = fopen("text_input.txt", "r");
    int lines = 0, tipe = 1;
    struct String lineptr[MAXLINES];

    Read_strings(lineptr, MAXLINES, &lines, File);
    Write_strings(lineptr, &lines);
    //printf("%d\n", lines);
    //Unit_tests(lineptr);
    Unit_tests_Comp(lineptr, tipe);
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

int Sorting_strings(struct String* lineptr, int left, int right){
    return 0;
}

int Comp_strings(struct String struct_a, struct String struct_b, int tipe){
    char* a = struct_a.str;
    char* b = struct_b.str;
    int i = 0;
    if (tipe == 1) {
        for (i = 0; a[i] == b[i]; i++){
            if (a[i] == '\0')
                return 0;
        }
        return a[i] - b[i];
    }

    if (tipe == 2) {
        int index = min(struct_a.len, struct_b.len);
        //printf("%d", index);
        for (i = index; a[i] == b[i]; i--){
            if (i == 0)
                return 0;
        }
        return a[i] - b[i];
    }
}

int Unit_tests_Comp(struct String* lineptr, int tipe){
    struct String a, b;
    a.str = "babc";
    a.len = 4;
    b.str = "abc";
    b.len = 3;
    int res = Comp_strings(a, b, 2);
    if (res < 0)
        printf("%s < %s\n", a.str, b.str);
    else if (res == 0)
        printf("%s = %s\n", a.str, b.str);
    else
        printf("%s > %s\n", a.str, b.str);
}
