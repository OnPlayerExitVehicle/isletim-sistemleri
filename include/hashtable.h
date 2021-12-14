#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_DATA 80
#define TABLE_SIZE 10

typedef struct {
    char data[MAX_DATA];
} datas;

datas * hash_table[TABLE_SIZE];

unsigned int getHash(char *);
void print_table();
int hash_table_insert(datas*);
datas *hash_table_lookup(char *);
int hash_table_get_key(char* data_name);

typedef unsigned int hash;