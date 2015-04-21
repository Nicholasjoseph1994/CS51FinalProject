// This is the hashtable.h file!
 
#include <stdlib.h>
#include <hashtable.h>
#include <strings.h>

#define HASHSIZE 1000

typedef struct hash_elt
{
    struct hash_elt *next;
    char *word;
    int *freq;
}hash_elt;

// creates a dictionary
hash_elt* create(void);

// checks if a word is in the hashtable
bool check(char* word, hash_elt *mytable);

// gets the frequency of that word in our data so far
int getFrequency(char* word, hash_elt *mytable);

// adds a word to the hashtable
void add_word(char* word);


