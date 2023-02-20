# C-hashTables
# Description

   __This is C-hashTables implementation __ 

The main program processes with initing the hashTable boxes to NULL and then  reads the txt file .
It stores all players with there ages in the correct index box corresponding to the value calculated by the hash function.
It uses hash_insert , hash_delete and hash_lookup functions to look , insert and delete player if wanted.

The program considers possible confusions in the case of insertion of two players in a table cell with the same index and that by seeking the free cell closest to 
the previously calculated  index .
If it reaches the end of the table without finding a free cell, it does not insert the player.


Finally it prints out the table with all corresponding players in the txt file.

# Working directory structure

    .
    ├── README
    └── src
         ├── hash_table.c
         ├── hash_table.h
         ├── hash_table.o
         ├── main
         ├── main.c
         ├── main.o
         ├── makefile
         └── players.txt

    1 directory, 9 files

