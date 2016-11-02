#include <stdio.h>

int main(int argc, char **argv) {
    
    if (argc != 4) {
        printf("Invalid number of arguments. The argments are <input> <symbol table structure> <sorting style>\n");
        exit(-1);
    }

    FILE *file;
    file = argv[1];
    fopen(file, "ro");
    
    if (strcmp(argv[2],"VD") == 0)
        desorderVec(file, argv[3]);
    
    if (strcmp(argv[2],"VO") == 0) 
        orderVec(file, argv[3]);
    
    if (strcmp(argv[2],"LD") == 0) 
        desorderList(file, argv[3]);
    
    if (strcmp(argv[2],"LO") == 0) 
        orderList(file, argv[3]);
    
    if (strcmp(argv[2],"AB") == 0) 
        binTree(file, argv[3]);
    
    return 0;
}
