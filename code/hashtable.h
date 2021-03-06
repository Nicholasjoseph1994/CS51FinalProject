// This is the hashtable.h file!
#include <stdio.h> 
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#define HASHSIZE 100000

typedef struct hash_elt
{
    struct hash_elt *next;
    char* word;
    int freq;
} hash_elt;

typedef struct hash_table
{
    hash_elt** lists;
    int buckets;
} hash_table;

// prints out a hashtable
void print(hash_table* mydict);

// creates a dictionary
hash_table* create(int buckets);

// checks if a word is in the hashtable
bool check(char* word, hash_table* mytable);

// gets the frequency of that word in our data so far
int getFrequency(char* word, hash_table* mytable);

// adds a word to the hashtable
void add_word(char* word, hash_table* mytable);

bool is_empty(hash_table* table);

void freeHash(hash_table* table);
