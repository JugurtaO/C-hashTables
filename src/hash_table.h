#include <stdio.h>

#define MAX_SIZE 10
#define MAX_NAME 128

typedef struct{
    char name[MAX_NAME];
    int age;
} player;

void init_hash_table(player * table[]);           // init to NULL
int hash(player *pl);             //returns the table Index where concerned data will be stored
player* hash_lookup(player *pl,player * table[]);  //returns a pointer to the player struct if exists or NULL if not
int hash_insert(player *pl,player * table[]);      //returns a boolean true if player has been successfully inserted of false if not
int hash_delete(player *pl,player * table[]);      //returns a boolean true if player has been successfully deleted of false if not
void read_file(char* fileName,player * table[]);
void hashPrint_table(player * table[]); // display table content