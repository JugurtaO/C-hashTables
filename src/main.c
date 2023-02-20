#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
int main (int argc, char **argv){
    if (argc!=2)
        printf("Uses with ./main <file.txt> \n");
    else{
        player* table[MAX_SIZE];
        init_hash_table(table); 
        printf("init table done ;;\n");
        read_file(argv[1], table);
        hashPrint_table(table);
        
        printf("********\n");
        player *jugurta =malloc(sizeof(player));
        strcpy(jugurta->name,"Jugurta");
        jugurta->age=20;
        hash_delete(jugurta,table);
        hashPrint_table(table);
    }

  

    return 0;
}