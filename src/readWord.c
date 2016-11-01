#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reallocSTR(char* str, int size) { 
    int i;
    char* new;
    new = malloc(2*size * sizeof(char));
    strcpy(new, str);
    
    /*Clean the previous string from the memory*/
    for (i = 0; i < size; i++)
        str[i] = 0;
    
    free(str);
    str = new;
}

void toLower (char* str, int size) {
    int i;
    for (i = 0; i < size; i++)
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
}

int alfaNumber (int c) {
    if ((c >= 48 && c<=57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    else
        return 0;
}

int main () {
    FILE *file;
    file = fopen("test.txt", "ro");
    int i, c, sizestr, count;
    char* string;
   
    sizestr = 24;
    string = malloc(sizestr * sizeof(char)); 

    for ((c = fgetc(file)), count = 0; (isspace(c)), (alfaNumber(c)), c !=EOF; 
         (c = fgetc(file))) {
        
        if (count == 0 && !(c >= 48 && c <= 57)) {
            string[0] = c;
            count++;
        }
        
        else {
            if (count == sizestr) {
                reallocSTR(string, sizestr);
                sizestr *= 2;
            }
            string[count] = c;
            count++;   
        }
    }

    toLower(string, sizestr);
    printf("%s\n", string); 
    return 0;
}
