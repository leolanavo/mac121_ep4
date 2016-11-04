#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tabelaSimbolo_VD.h"

int main(int argc, char **argv) {
    
    FILE *file;
    
    if (argc != 4) {
        printf("Invalid number of arguments. The argments are <input> <symbol table structure> <sorting style>\n");
        exit(-1);
    }

    file = fopen(argv[1], "ro");
    if (file == NULL) {
        printf("File doesn't exist\n");
        
    }
    if (strcmp(argv[2],"VD") == 0)
        desorderVec(file, argv[3]);
    
    if (strcmp(argv[2],"VO") == 0) 
        orderVec(file, argv[3]);
    
    /*if (strcmp(argv[2],"LD") == 0) 
        desorderList(file, argv[3]);
    
    if (strcmp(argv[2],"LO") == 0) 
        orderList(file, argv[3]);
    
    if (strcmp(argv[2],"AB") == 0) 
        binTree(file, argv[3]);*/
    
    return 0;
}
