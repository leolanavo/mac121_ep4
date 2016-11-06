#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Recieves a string ans its maximum size. Realloc the string
 *  * with double the original size and return the new string. */
char* reallocSTR(char* str, int size) { 
    char* new;
    new = malloc(2*size * sizeof(char));
    
    strcpy(new, str);
    free(str);
    
    return(new);
}

/* Recieve a string with alphanumeric characters and convert them all
 *  * to lower case characters. */
void toLower (char* str) {
    int i, size;
    size = strlen(str);
    
    for (i = 0; i < size; i++)
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    
    return;
}

/* Recieve an integer. Return 1 if the integer is an aplanumeric character, 
 *  * 0 otherwise. */
int alphaNumeric (int c) {
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    else
        return 0;
}

/* Recieve a pointer a file from where it will read a word,
 * and return the read word in lower case. It also recieves
 * an integer pointer so it can return 1 when the EOF is reached
 * end, will be 0, otherwise. */
char* readWord (FILE* file, int* end) {

    int c, sizestr, count;
    char* string;
               
    sizestr = 8;
    string = malloc(sizestr * sizeof(char));

    c = 0;
    
    /*Char Seeker*/
    if (c != EOF) {
        *end = 0;
        while(c!= EOF && alphaNumeric(c) == 0)
            c = fgetc(file);
        if (c == EOF) *end = 1;
        ungetc(c, file);
    }
    
    for ((c = fgetc(file)), count = 0; alphaNumeric(c); (c = fgetc(file))) {

         if (count == 0 && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))) {
            string[0] = c;
            count++;
        }
        
        else if (count != 0){
            if (count >= sizestr) {
                string = reallocSTR(string, sizestr);
                sizestr *= 2;
            }
            string[count] = c;
            count++;
        }
    }

    /*Char Seeker*/
    if (c != EOF) {
        *end = 0;
        while(c!= EOF && alphaNumeric(c) == 0)
            c = fgetc(file);
        if (c == EOF) *end = 1;
        ungetc(c, file);
    }

    else *end = 1;
    
    toLower(string);
    return (string);
}
