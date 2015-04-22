// This is the hashtable.h file!
#include <stdio.h> 
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#define HASHSIZE 1000

typedef struct hash_elt
{
    struct hash_elt *next;
    char* word;
    int freq;
}hash_elt;

typedef struct hash_table
{
    hash_elt** lists;
    int buckets;
}hash_table;
// creates a dictionary
hash_table* create(void);

// checks if a word is in the hashtable
bool check(char* word, hash_table* mytable);

// gets the frequency of that word in our data so far
int getFrequency(char* word, hash_table* mytable);

// adds a word to the hashtable
void add_word(char* word, hash_table* mytable);


