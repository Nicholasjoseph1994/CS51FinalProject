// This is the hashtable.h file!
#include <stdio.h> 
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#define HASHSIZE 1000

typedef struct skip_elt
{
    char* word;
    int freq;

    struct skip_elt** next;

} skip_elt;

typedef struct skip_list
{
    struct skip_elt* first;
    int height;

} skip_list;

// creates a skiplist dictionary
skip_list* create(int size);

// checks if a word is in the hashtable
bool check(char* word, skip_list* myskip);

// gets the frequency of that word in our data so far
int getFrequency(char* word, skip_list* myskip);

// adds a word to the hashtable
void add_word(char* word, skip_list* myskip);


