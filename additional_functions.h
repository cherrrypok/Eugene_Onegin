int min (int a, int b);
/** ****************************************************************************
* @brief compares two numbers
* @param a number
* @param b number
*
* return: num < 0 if a < b
* num = 0 if a == b
* num > 0 if a > b
*/

int swap (struct String* lineptr, int a, int b);
/** ****************************************************************************
* @brief swaps two array elements with the passed indexes
* @param lineptr array of structures consisting of strings and their lengths
* @param a index
* @param b index
*/

int Length_string (char* str);
/** ****************************************************************************
* @brief returns the length of the string
* @param str string
*/

int SizeTextFile_char (FILE* File);
/** ****************************************************************************
* @brief returns the length tipe char of the string
* @param File file for counting characters
*/

char* To_lower (char* str);
int SizeTextFile_string (char* text);
