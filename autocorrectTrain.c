#include "autocorrectTrain.h"
#include "bloom.h"
#include "string.h"
hash_table* readWords(char** words, int numWords) {
    hash_table* table = create(HASHSIZE);
    for (int i = 0; i < numWords; ++i) {
        add_word(words[i], table);
    }
}
typedef struct split {
    char* start;
    char* end;
} split;

split* splits (char* word) {
    int len = strlen(word);
    split* splits [len];
    for (int i = 0; i < len; i++) {
        split* s = malloc(sizeof(split));
        strncpy(s->start, word, i);
        strncpy(s->end, word + i, len-i);
        splits[i] = s;
    }
}
/* I did splits but if you can fill these in that would be awesome */

/* why is this returning a char**, shouldn't it return some sort of array of char** or char*/
char** deletes(split* splits, int splitslen) {
    if (splits != NULL) 
    {
        char** strarry = malloc(splitslen*sizeof(char*))
        for (int i = 0; i < splitslen; i++)
        {
            if (splits[i]->end = "") 
            {
                strarray[i] = strcat(splits[i]->start, "")
            }
            else 
            {
                strarray[i] = strcat(splits[i]->start, (splits[i]->end)++)
            }

        }
    } 
        
}
char** transposes(split* splits, int splitslen) {
    if (splits != NULL)
    {
        char** strarray = malloc(splitslen * sizeof(char*));
        for (int i = 0; i < splitslen; i++)
        {
            if (splits[i]->end = "")
            {
                strarray[i] = strcat(splits[i]->start, "")
            }
            else
            {
                char* temp = malloc(3 * sizeof(char));
                temp [0] = (splits[i] -> end) [1];
                temp [1] = (splits[i] -> end) [0];
                temp [2] = '/0';
                char* newend = strcat(temp, ((splits[i]->end)++)++);
                strarray[i] = strcat(splits[i]->start, newend);
            }
        }
    }
}
char** replaces(split* splits, int splitslen) {
    char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    int alphalen = strlen(alphabet);
    char** strarray = malloc(splitslen * alphalen * sizeof(char*));
    if (splits != NULL)
    {
        for (int i = 0; i < alphalen; i++)
        {
            for (int j = 0; j < splitslen; j++)
            {
                if (splits[i]->end = "")
                {
                    char* temp = malloc(2*sizeof(char));
                    temp[0] = alphabet[i];
                    temp[1] = "/0";
                    strarray[j*alphalen + i] = strcat(splits[i]->start, temp);
                }
                else
                {
                    char* temp = malloc(2*sizeof(char));
                    temp[0] = alphabet[i];
                    temp[1] = "/0";
                    char* temp2 = strcat(temp,(splits[i]->end)++);
                    strarray[j*alphalen + i] = strcat(splits[i]->start, temp2);
                }
            }
        }
    }
}
char** inserts(split* splits) {
    char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    int alphalen = strlen(alphabet);
    char** strarray = malloc(splitslen * alphalen * sizeof(char*));
    if (splits != NULL)
    {
        for (int i = 0; i < alphalen; i++)
        {
            for (int j = 0; j < splitslen; j++)
            {
                
            }
        }
    }
}
char** editDistance1(char* word) {
    return NULL;
}
char* correct (char* word) {
    return NULL;
}
