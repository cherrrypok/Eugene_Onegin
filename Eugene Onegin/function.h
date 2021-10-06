struct String {
    char* str;
    int len;
};

enum Types_of_Sorting {
    SORTING_FROM_THE_BEGIN,
    SORTING_FROM_THE_END,
    SORTING_FROM_POINTERS
};

int getline(char* s, int maxsize, FILE *File);
int min(int a, int b);
int swap(struct String* lineptr, int a, int b);
int length_string(char* str);
int next_letter(char* str, int* i);
int sizeTextFile_in_Char(FILE* File);

int Read_strings(struct String* lineptr, int maxsize, int* lines, FILE *File);
int Write_strings(struct String* lineptr, int* lines);
int Output_Result(struct String* lineptr, int maxsize, int* lines, FILE *File);
int quicksort(struct String* lineptr, int left, int right, enum Types_of_Sorting type);
int partition(struct String* lineptr, int left, int right, enum Types_of_Sorting type);
int Comp_strings(struct String a, struct String b, enum Types_of_Sorting type); // <0 a < b  >0 a >b

int Unit_tests(struct String* lineptr); //1 - сортировка с начала 2 - сортировка с конца
int Unit_tests_Comp(struct String* lineptr, enum Types_of_Sorting type);
