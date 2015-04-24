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
char** deletes(split* splits) {
    return NULL;
}
char** transposes(split* splits) {
    return NULL;
}
char** replaces(split* splits) {
    return NULL;
}
char** inserts(split* splits) {
    return NULL;
}
char** editDistance1(char* word) {
    return NULL;
}
char* correct (char* word) {
    return NULL;
}
