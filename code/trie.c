// This is the trie!
#include <stdlib.h>
#include "trie.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
void print_test(trie_elt* mytrie);

int main(void)
{
    trie_elt* dict_head = create();
    add_word("cow", dict_head);
    add_word("moo", dict_head);
    add_word("doggy", dict_head);
    assert(check("cow", dict_head));
    assert(check("moo", dict_head));
    assert(check("Doggy", dict_head));
    assert(!check("manure", dict_head));
    add_word("cow", dict_head);
    assert(getFrequency("cow", dict_head) == 2);
    assert(getFrequency("mooo", dict_head) == 0);
    printf("all asserts passed\n");
}

trie_elt* create(void)
{
    trie_elt* new_node = malloc(sizeof(trie_elt));
    new_node->word_id = 0;
    for (int i = 0; i < ALPHABET; i++)
    {
        new_node->alphabet[i] = NULL;
    }
    return new_node;
}

void add_word(char*word, trie_elt* mytrie)
{
    int length = strlen(word);
    
    for (int i = 0; i < length; i++)
    {
       int letter = word[i];
       letter = tolower(letter);
       int spot = letter - 'a';

       if (mytrie->alphabet[spot] == NULL)
       {
           mytrie->alphabet[spot] = create();
       } 
       mytrie = mytrie->alphabet[spot]; 
    }
    mytrie->word_id++;
    return;
}

bool check(char* word, trie_elt* mytrie)
{
    if (getFrequency(word, mytrie) == 0)
        return false;
    else return true;
}

int getFrequency(char* word, trie_elt* mytrie)
{
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        int letter = word[i];
        letter = tolower(letter);
        int spot = letter - 'a';

        if (mytrie->alphabet[spot] == NULL)
        {
            return 0;
        }
        mytrie = mytrie->alphabet[spot];
    }
    int freq = mytrie->word_id;
    return freq;
}

