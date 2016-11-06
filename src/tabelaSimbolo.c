#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tabelaSimbolo_VD.h"
#include "../include/tabelaSimbolo_VO.h"
#include "../include/tabelaSimbolo_LD.h"
#include "../include/tabelaSimbolo_LO.h"
#include "../include/tabelaSimbolo_AB.h"

int main(int argc, char **argv) {
    
    FILE *file;
    
    if (argc != 4) {
        printf("Invalid number of arguments. The argments are <input> <symbol table structure> <sorting style>\n");
        exit(-1);
    }

    file = fopen(argv[1], "ro");
    
    if (file == NULL)
        printf("File doesn't exist\n"); 
    
    if (strcmp(argv[2],"VD") == 0)
        desorderVec(file, argv[3]);
    
    else if (strcmp(argv[2],"VO") == 0) 
        orderVec(file, argv[3]);
    
    else if (strcmp(argv[2],"LD") == 0) 
        desorderList(file, argv[3]);
    
    else if (strcmp(argv[2],"LO") == 0) 
        orderList(file, argv[3]);
    
    else  
        binTree(file, argv[3]);
    
    return 0;
}
