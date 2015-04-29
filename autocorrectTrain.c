#include "autocorrectTrain.h"
#include "string.h"
hash_table* readWords(char** words, int numWords) {
    hash_table* table = create(HASHSIZE);
    for (int i = 0; i < numWords; ++i) {
        add_word(words[i], table);
    }
    return table;
}
typedef struct split {
    char* start;
    char* end;
} split;

// char* testword = (char *) malloc(6 * sizeof(char));
// strncpy(testword, "table", 5);

split** splits (char* word) {
    int len = strlen(word);
    split** splits = malloc(sizeof(split**) * len);
    for (int i = 0; i < len; i++) {
        split* s = malloc(sizeof(split));
        strncpy(s->start, word, i);
        strncpy(s->end, word + i, len-i);
        splits[i] = s;
    }
    return splits;
}
/* I did splits but if you can fill these in that would be awesome */

// for each split in splits, if the end part of the split is unempty, removes
// the first letter, appends the new end to start, and returs the resulting string
char** deletes(split** splits, int splitslen) {
    if (splits != NULL) 
    {
        char** strarray = malloc((splitslen-1)*sizeof(char*));
        for (int i = 0; i < splitslen; i++)
        {
            if (strlen(splits[i]->end) != 0) 
            {
                strarray[i] = strcat(splits[i]->start, splits[i]->end+1);
            }
        }
        return strarray;
    }     
    return NULL;
}

// char** transposes(split* splits, int splitslen) {
//     if (splits != NULL)
//     {
//         char** strarray = malloc(splitslen * sizeof(char*));
//         for (int i = 0; i < splitslen; i++)
//         {
//             if (strlen(splits[i]->end) == 0)
//             {
//                 strarray[i] = strcat(splits[i]->start, "")
//             }
//             else
//             {
//                 char* temp = malloc(3 * sizeof(char));
//                 temp [0] = (splits[i] -> end) [1];
//                 temp [1] = (splits[i] -> end) [0];
//                 temp [2] = '/0';
//                 char* newend = strcat(temp, ((splits[i]->end)++)++);
//                 strarray[i] = strcat(splits[i]->start, newend);
//             }
//         }
//     }
// }
// char** replaces(split* splits, int splitslen) {
//     char* alphabet = "abcdefghijklmnopqrstuvwxyz";
//     int alphalen = strlen(alphabet);
//     char** strarray = malloc(splitslen * alphalen * sizeof(char*));
//     if (splits != NULL)
//     {
//         for (int i = 0; i < splitslen; i++)
//         {
//             for (int j = 0; j < alphalen; j++)
//             {
//                 if (strlen(splits[i]->end )= 0)
//                 {
//                     char* temp = malloc(2*sizeof(char));
//                     temp[0] = alphabet[j];
//                     temp[1] = "/0";
//                     strarray[i*alphalen + j] = strcat(splits[i]->start, temp);
//                 }
//                 else
//                 {
//                     char* temp = malloc(2*sizeof(char));
//                     temp[0] = alphabet[j];
//                     temp[1] = "/0";
//                     char* temp2 = strcat(temp,(splits[i]->end)++);
//                     strarray[i*alphalen + j] = strcat(splits[i]->start, temp2);
//                 }
//             }
//         }
//     }
// }
// char** inserts(split* splits) {
//     char* alphabet = "abcdefghijklmnopqrstuvwxyz";
//     int alphalen = strlen(alphabet);
//     char** strarray = malloc(splitslen * alphalen * sizeof(char*));
//     if (splits != NULL)
//     {
//         for (int i = 0; i < splitslen; i++)
//         {
//             for (int j = 0; j < alphalen; j++)
//             {
//                 char* temp = malloc(2*sizeof(char));
//                 temp[0] = alphabet[j];
//                 temp[1] = "/0";
//                 char* temp2 = malloc((strlen(temp) + strlen(splits[i]->end) + 1) * sizeof(char));
//                 temp2 = strcat(temp, splits[i]->end);
//                 strarray[i*alphalen + j] = strcat(splits[i]->start, temp2);
//             }
//         }
//     }
// }
char** editDistance1(char* word) {
    return set(deletes + transposes + replaces + inserts);
}
char* correct (char* word) {
    return NULL;
}
