// This is the hashtable!
// The functions that we will need are add_word and getFrequency
// Within the getFrequency code, we will be calling another function called "check"
// If the word is there, then getFrequency will return the number of times it occurs.
// If the word is not there, then getFrequency will return 0.
// Note to self: grab the hash function from bloomfilter.c
 
#include <stdlib.h>
#include "hashtable.h"
#include <strings.h>
#include <stdbool.h>
#include <stdio.h>

void print_test(skip_list* myskip);

int main(void)
{
    /*
    hash_table* mydict = create(HASHSIZE);
    add_word("first", mydict);
    add_word("second", mydict);
    add_word("first", mydict); 
    print_test(mydict);
    bool x = check("first", mydict);
    printf(x ? "yes":"no");
    bool y = check("foo", mydict);
    printf(y ? "yes" : "no");
    */ 
}

void print_test(skip_list* myskip)
{
   printf("entered print_test \n"); 
}

skip_list* create(int size);
{
    printf("entered create \n");

    skip_list* list = malloc(sizeof(skip_list));
    list->height = 0;

    list->first = malloc(sizeof(skip_elt*);
    list->first = NULL;
    return list;
}

//struct hash_elt *mytable[HASHSIZE];
unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % HASHSIZE;
}

bool check(char* word, skip_list* myskip)
{
    if (getFrequency(word, mytable) == 0)
        return false;
    else return true;
}



// gets the frequency of that word in our data so far
int getFrequency(char* word, skip_table* myskip)
{

}

void add_word(char* word, skip_list* myskip)
{

}

