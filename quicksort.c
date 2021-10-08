#include "quicksort.h"

int quicksort(struct String* lineptr, int left, int right, enum Types_of_Sorting type){
    if (left < right){
        int mid = partition(lineptr, left, right, type);
        quicksort(lineptr, left, mid, type);
        quicksort(lineptr, mid + 1, right, type);
    }
}

int partition(struct String* lineptr, int left, int right, enum Types_of_Sorting type){ // сортировка общая. для каждого типа. void*
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


int next_letter(char* str, int* i){
    while ((str[*i] >= 'A' && str[*i] <= 'Z' || str[*i] >= 'a' && str[*i] <= 'z') == 0)
        --*i;
    return str[*i];
}

int Comp_strings(struct String struct_a, struct String struct_b, enum Types_of_Sorting type){
    char* a = tolower(struct_a.str);
    char* b = tolower(struct_b.str);
    int i = 0;
    if (type == SORTING_FROM_THE_BEGIN) {
        for (i = 0; a[i] == b[i]; i++){
            if (a[i] == '\0'){
                free(a);
                free(b);
                return 0;
            }
        }
        free(a);
        free(b);
        return a[i] - b[i];
    }

    if (type == SORTING_FROM_THE_END) {
        int i_a = length_string(a);
        int i_b = length_string(b);

        int index = min(i_a, i_b);
        for (i = index; i > 0 && next_letter(a, &i_a) == next_letter(b, &i_b); i--){
            i_a--;
            i_b--;
            if (i == 0){
                free(a);
                free(b);
                return 0;
            }
        }
        free(a);
        free(b);
        return a[i_a] - b[i_b];
    }

    if (type == SORTING_FROM_POINTERS) {
        return struct_a.str - struct_b.str;
    }
}
