// This is the hashtable.h file!
#include <stdio.h> 
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#define ALPHABET 27

typedef struct trie_elt
{
    //word_id should be 0 if no word and 1 if word
    int word_id; 

    struct trie_elt* alphabet[ALPHABET];

} trie_elt;

typedef struct trie
{
    struct trie_elt* first;

} trie;

// creates a trielist dictionary
trie_elt* create(void);

// checks if a word is in the hashtable
bool check(char* word, trie_elt* mytrie);

// gets the frequency of that word in our data so far
int getFrequency(char* word, trie_elt* mytrie);

// adds a word to the hashtable
void add_word(char* word, trie_elt* mytrie);


