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

void print(hash_table* mydict)
{
    for (int i = 0; i < (HASHSIZE - 1); i++)
    {
        hash_elt* element = mydict->lists[i];
        while (element != NULL)
        {
            printf("%s, %d \n", element->word, element->freq);
            element = element -> next;
        }
    }
}
hash_table* create(int buckets)
{
   hash_table* table = malloc(sizeof(hash_table));
   table->buckets = buckets;
   table->lists = malloc(sizeof(hash_elt*) * table->buckets);
   for (int i = 0; i < table->buckets; i++) {
       table->lists[i] = NULL;
   }
   return table;
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

bool check(char* word, hash_table* mytable)
{
    if (getFrequency(word, mytable) == 0)
        return false;
    else return true;
}



// gets the frequency of that word in our data so far
int getFrequency(char* word, hash_table* mytable)
{
    unsigned long hash_value = hash(word);
    //hash_elt* test1 = mytable->lists[hash_value];
    //printf(" %s ", test1->word);
    //struct hash_elt *element;
    for (hash_elt* element = mytable->lists[hash_value]; element != NULL; element = element->next)
        if (strcmp(word, element->word) == 0)
            return element->freq; 
    return 0; 
}

void add_word(char* word, hash_table* mytable)
{
    unsigned long hash_value = hash(word);

    if (check(word, mytable))
    {
        for (hash_elt* element = mytable->lists[hash_value]; element!= NULL; element = element->next)
        {
            if (strcmp(word,element->word) == 0)
            {
                (element->freq)++;
                return;
            }
        }   
    }

    hash_elt* new_elt = malloc(sizeof(hash_elt));
    if (new_elt == NULL)
        return;
    new_elt->word = word;
    printf("word added by add_word: %s \n", word);
    new_elt->freq = 1;
    new_elt->next = mytable->lists[hash_value];
    mytable->lists[hash_value] = new_elt;
    printf("dict value: %s \n", mytable->lists[hash_value]->word);
    return;
}

bool is_empty(hash_table* table) {
    for (int i = 0; i < table->buckets; i++) {
        if (table->lists[i] != NULL) {
            return false;
        }
    }
    return true;
}
