#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* reallocSTR(char* str, int size) { 
    int i;
    char* new;
    new = malloc(2*size * sizeof(char));
    strcpy(new, str);
    
    free(str);
    return(new);
}

void toLower (char* str) {
    int i, size;
    size = strlen(str);
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

int readWord (FILE* file) {

    int i, c, sizestr, count;
    char* string;
   
    sizestr = 5;
    string = malloc(sizestr * sizeof(char)); 

    for ((c = fgetc(file)), count = 0; c !=EOF, alfaNumber(c); 
         (c = fgetc(file))) {

        if (count == 0 && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))) {
            string[0] = c;
            count++;
        }
        
        else if (count != 0){
            if (count == sizestr) {
                string = reallocSTR(string, sizestr);
                sizestr *= 2;
            }
            string[count] = c;
            count++;   
        }
    }

    toLower(string);
    return 0;
}
