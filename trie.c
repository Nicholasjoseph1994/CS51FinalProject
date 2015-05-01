// This is the trie!
 
#include <stdlib.h>
#include "trie.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
void print_test(trie_elt* mytrie);

int main(void)
{
    printf("main \n");
    trie_elt* dict_head = create();
    print_test(dict_head);
    add_word("dog", dict_head);
    add_word("cat", dict_head);
    add_word("doggy", dict_head);
    int dog_test = check("dog", dict_head);
    int toy_test = check("toy", dict_head);
    int cat_test = check("cat", dict_head);
    int doggy = check("Dog", dict_head);
    printf("%d, %d, %d, %d \n", dog_test, toy_test, cat_test, doggy);
    add_word("dog", dict_head);
    int dog_freq = getFrequency("dog", dict_head);
    int doggy_freq = getFrequency("Dog", dict_head);
    printf("dog frequency is %d \n", dog_freq);
    printf("Dog freq is %d \n", doggy_freq);
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

void print_test(trie_elt* mytrie)
{
   printf("entered print_test \n"); 
   //printf("the initial char is: %c \n", mytrie->first->letter);
}

trie_elt* create(void)
{
    printf("entered create \n");
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

