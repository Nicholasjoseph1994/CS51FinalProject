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

int print_test(hash_table* mydict);

int main(void)
{
    hash_table* mydict = create(HASHSIZE);
    add_word("first", mydict);
    add_word("second", mydict);
    
    print_test(mydict);
 
}

int print_test(hash_table* mydict)
{
    for (int i = 0; i < (HASHSIZE - 1); i++)
    {
        hash_elt* element = mydict->lists[i];
        while (element != NULL)
        {
            printf("%s \n", element->word);
            element = element->next;
        }
        i++;

    }
    return 0;
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
        if (strcasecmp(word, element->word) == 0)
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
            printf("%s", element->word);
            if (strcasecmp(word,element->word) == 0)
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
    new_elt->freq = 1;
    new_elt->next = mytable->lists[hash_value];
    mytable->lists[hash_value] = new_elt;
    return;
}

