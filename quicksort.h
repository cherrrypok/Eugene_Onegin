int Quicksort (struct String* lineptr, int left, int right, enum Types_of_Sorting type);
/** ****************************************************************************
* @brief Sorts the incoming array in ascending order
* @param lineptr array of structures consisting of strings and their lengths
* @param left pointer to the leftmost element of the array
* @param right pointer to the rightmost element of the array
* @param type three types of sorting:
*        SORTING_FROM_THE_BEGIN, SORTING_FROM_THE_END, SORTING_FROM_POINTERS
*
* Sorts the array relative to the central element, recursively starts sorting
* for the left and right parts.
*/

int Partition (struct String* lineptr, int left, int right, enum Types_of_Sorting type);
/** ****************************************************************************
* @brief function Quicksort's
* @param lineptr array of structures consisting of strings and their lengths
* @param left pointer to the leftmost element of the array
* @param right pointer to the rightmost element of the array
* @param type three types of sorting:
*        SORTING_FROM_THE_BEGIN, SORTING_FROM_THE_END, SORTING_FROM_POINTERS
*
* Divide the array into two parts as follows: all elements from the left part
* that are greater than or equal to the reference, we throw to the right,
* similarly, all elements from the right that are less than or equal to the
* reference, we throw to the left part.
*/

int Comp_strings (struct String a, struct String b, enum Types_of_Sorting type);
/** ****************************************************************************
* @brief lexicographically compares two strings
* @param a string
* @param b string
* @param type three types of sorting:
*        SORTING_FROM_THE_BEGIN, SORTING_FROM_THE_END, SORTING_FROM_POINTERS
*
* return: num < 0 if a < b
* num = 0 if a == b
* num > 0 if a > b
*/

int Next_letter (char* str, int* i);
/** ****************************************************************************
* @brief finds the next letter character on the left in the string
* @param str string
* @param i index
*/
