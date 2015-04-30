#include "hashtable.h"
#define MAXSTRLEN 100

/*
 * Reads an array of strings into a hashtable and returns a pointer to it.
 * words - the array of strings
 * numWords - the length of words
 */
hash_table* readWords(char** words, int numWords);

typedef struct split {
    char* start;
    char* end;
} split;

split** splits (char* word);
char** deletes(split** splits);
char** transposes(split** splits);
char** replaces(split** splits, char* alphabet);
char** inserts(split** splits, char* alphabet);


// gives all the words that are edit distance 1 away
hash_table* editDistance1(char* word);
// gives all the words that are edit distance 2 away
hash_table* editDistance2(char* word, hash_table* dictionary);
// returns a subset of words that are valid words in our dictionary
char** valid_words(hash_table* table, char**words); 
// gives a valid word that is a possible correction
char* correct(char* word, hash_table* dict);

