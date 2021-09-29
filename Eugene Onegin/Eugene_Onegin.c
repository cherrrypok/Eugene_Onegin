#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 5000
#define MAXLINES 9999

struct String {
    char* str;
    int len;
};

int Read_strings(struct String* lineptr, int maxsize, int* lines);
int Write_strings(struct String* lineptr, int* lines);
int getline(char* s, int maxsize);
int Unit_tests(struct String* lineptr);

int main() {
    int lines = 0;
    struct String lineptr[MAXLINES];

    Read_strings(lineptr, MAXLINES, &lines);
    Write_strings(lineptr, &lines);
    //printf("%d\n", lines);
    //Unit_tests(lineptr);
}

int Unit_tests(struct String* lineptr) {
    for (int i = 0; i < 10; i++) {
        printf("%d, %p, %s\n", lineptr[i].len, lineptr[i].str, lineptr[i].str);
    }

}

int getline(char* s, int maxsize) {
    char c;
    int i = 0;
    while (maxsize-- && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return --i;
}

int Read_strings(struct String* lineptr, int maxsize, int* lineptr_index) {
    int len = 0;
    char* line = (char*)calloc(MAXLINE, sizeof(char));
    //printf("%p %s\n", line, line);

    while (--maxsize, (len = getline(line, MAXLINE)) > 0) {
        lineptr[*lineptr_index].str = line;
        lineptr[*lineptr_index].len = len;
        //printf("%d, &d\n", sizeof(line), sizeof(lineptr[lineptr_index++]));
        //printf("%p %s %d\n", line, line, len);
        printf("%d, %p, %s\n", lineptr[*lineptr_index].len, lineptr[*lineptr_index].str, lineptr[*lineptr_index].str);

        ++* lineptr_index;
        line = calloc(MAXLINE, sizeof(char));
    }
}

int Write_strings(struct String* lineptr, int* lines) {
    for (int i = 0; i < *lines; i++)
        printf("%s", lineptr[i].str);
}
