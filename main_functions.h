struct String
{
    char* str;
    int len;
};

enum Types_of_Sorting
{
    SORTING_FROM_THE_BEGIN,
    SORTING_FROM_THE_END,
    SORTING_FROM_POINTERS
};

/*
enum Errors{

};
*/

struct String* Ctor (char *file_name, int *count_strings); //добавить документацию

int Read_strings (struct String* lineptr, char *text); //поменять документашку
/** ****************************************************************************
* @brief read text from the FILE
* @param lineptr array of structures consisting of strings and their lengths
* @param File file to readd
*
* Allocates dynamic memory for the entire file. Conditionally splits the text
* into strings, writes their array lineptr.
*/

int Write_strings (struct String* lineptr, int* lines);
/** ****************************************************************************
* @brief prints lines of array contents
* @param lineptr array of structures consisting of strings and their lengths
* @param lines the number of lines in the file
*
* Prints all array strings via \n. The number of rows is equal to the function
* argument lines.
*/

int Output_result (struct String* lineptr, int* lines);
/** ****************************************************************************
* @brief prints the original source text sorted by condition
* @param lineptr array of structures consisting of strings and their lengths
* @param lines the number of lines in the file
* @param File file to read
*
* First printing -- lines are sorted in order.
* Second printing -- lines are sorted from the end.
* Third printing -- lines are sorted by pi addresses (printed in the original order).
* */
