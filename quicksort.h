int quicksort(struct String* lineptr, int left, int right, enum Types_of_Sorting type);
int partition(struct String* lineptr, int left, int right, enum Types_of_Sorting type);
int Comp_strings(struct String a, struct String b, enum Types_of_Sorting type); // <0 a < b  >0 a >b
int next_letter(char* str, int* i);
