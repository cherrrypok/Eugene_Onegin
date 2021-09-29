#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 5000
#define MAXLINES 1000

struct String {
    char* str;
    int len;
} lineptr[MAXLINES];

int read_strings(struct String lineptrn , int maxsize);
int getline(char s, int maxsize);

int main() {
    read_strings(lineptr, MAXLINES);
}

int getline(char s[], int maxsize) {
    char c;
    int i = 0;
    while (maxsize-- && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return --i;
}

int read_strings(struct String lineptr[], int maxsize) {
    char* line = (char *)calloc(MAXLINE, sizeof(char));
    int lineptr_index = 0, len = 0;
    while (--maxsize, (len = getline(line, MAXLINE)) > 0) {
        lineptr[lineptr_index++]->str = line;
        printf("%d, &d\n", sizeof(line), sizeof(lineptr[lineptr_index++]));
        lineptr[lineptr_index]->len = len;
        //printf("%p %s %d\n", line, line, len);
        printf("%s, %p, %d\n", lineptr[lineptr_index].str, lineptr[lineptr_index].str, lineptr[lineptr_index].len);

        line = calloc(MAXLINE, sizeof(char));
    }
}
