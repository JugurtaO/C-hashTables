#include "../headers/hash_table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



void init_hash_table(player * table[]){
    for (int i = 0; i < MAX_SIZE;i++){
        table[i] = NULL;
    }
};

int hash(player *pl){
    int playerNameLength = strlen(pl->name);
    int value = 0;
    for (int i = 0; i < playerNameLength;i++){
        value += pl->name[i];
        value = (value * pl->name[i]) % MAX_SIZE;
    }
    return value;
};

player *hash_lookup(player *pl,player * table[]){
    int hash_value = hash(pl);
    for (int i = 0; i < MAX_SIZE;i++){
        int Index = (hash_value + i) % MAX_SIZE;
        if (table[Index]!=NULL && (strcmp(pl->name,table[Index]->name)==0) )
            return table[Index]; //returns a pointer if player found 
    }
    return NULL; // NULL if not 
};
int hash_insert(player *pl,player * table[]){
    int hash_value = hash(pl);
    for (int i = 0; i < MAX_SIZE;i++){
        int Index = (hash_value + i) % MAX_SIZE;
        if (table[Index]==NULL){
            table[Index]=pl;
            return 0;   //returns TRUE if player has been inserted
        }
            
    }
    return 1; // FALSE if not 
};

int hash_delete(player *pl,player * table[]){
    int hash_value = hash(pl);
    for (int i = 0; i < MAX_SIZE;i++){
        int Index = (hash_value + i) % MAX_SIZE;
        if ( table[Index]!=NULL && (strcmp(pl->name,table[Index]->name)==0) && (pl->age==table[Index]->age) ){
            table[Index] = NULL;
            return 0; // returns TRUE if player has been deleted
        }
    }  
    return 1; // FALSE if not 

};

void hashPrint_table(player * table[]){
    for (int i = 0; i < MAX_SIZE;i++){
        if(table[i]==NULL)
            printf("%d : --------\n", i);
        else    
            printf("%d : %s  %d\n", i,table[i]->name,table[i]->age);

    }
};

void read_file(char *fileName,player * table[]){
    FILE *f = fopen(fileName, "r");
    if( f==NULL){
        perror("");
        return ;
    }
    else{
        int age;
        char name[64];
        fscanf(f,"%s %d",name,&age);
        while (!feof(f))
        {
            player *pl=malloc(sizeof(player));
            strcpy(pl->name, name);
            pl->age = age;
            hash_insert(pl,table);
            /***/
            int playerNameLength = strlen(name);
            name[playerNameLength] = '\0';   
            /***/
            fscanf(f,"%s %d",name,&age);
            
        }
    }
    fclose(f);
};