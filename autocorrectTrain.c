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

split** splits (char* word) {
    int len = strlen(word);
    // mallocs a list of splits
    split** splits = malloc(sizeof(split*) * len);
    for (int i = 0; i < len; i++) {
        split* s = malloc(sizeof(split));
        strncpy(s->start, word, i);
        strncpy(s->end, word + i, len-i);
        splits[i] = s;
    }
    return splits;
}
char** deletes(split** splits) {
    if (splits == NULL) {
        return NULL;
    }
    int wordLen = strlen(splits[0]->end);
    char** deletes = malloc(wordLen * sizeof(char*));
    for (int i = 0; i < wordLen; i++) {
        char* delete = malloc(wordLen);
        strcpy(delete, splits[i]->start);
        deletes[i] = strcat(delete, splits[i]->end + 1);
    }
    return deletes;
}
char** transposes(split** splits) {
    if (splits == NULL) {
        return NULL;
    }
    int wordLen = strlen(splits[0]->end);
    char** transposes = malloc((wordLen - 1) * sizeof(char*));
    for (int i = 0; i < wordLen - 1; i++) {
        char swapped [3] = {splits[i]->end[1], splits[i]->end[0], '\0'};
        char* transpose = malloc(wordLen + 1);
        strcpy(transpose, splits[i]->start);
        transposes[i] = strcat(strcat(transpose, swapped), splits[i]->end + 2);
    }
    return transposes;
}
char** replaces(split** splits, char* alphabet) {
    if (splits == NULL || alphabet == NULL) {
        return NULL;
    }
    int alphaLen = strlen(alphabet);
    int wordLen = strlen(splits[0]->end);
    char** replaces = malloc(wordLen * alphaLen * sizeof(char*));
    for (int i = 0; i < wordLen; i++) {
        for (int j = 0; j < alphaLen; j++) {
            char* replace = malloc(wordLen + 1);
            strcpy(replace, splits[i]->start);
            char replacement [2] = {alphabet[j], '\0'};
            replaces[i] = strcat(strcat(replace, replacement), splits[i]->end + 1);
        }
    }
    return replaces;
}

char** inserts(split** splits, char* alphabet) {
    if (splits == NULL || alphabet == NULL) {
        return NULL;
    }
    int alphaLen = strlen(alphabet);
    int wordLen = strlen(splits[0]->end);
    char** inserts = malloc(wordLen * alphaLen * sizeof(char*));
    for (int i = 0; i < wordLen; i++) {
        for (int j = 0; j < alphaLen; j++) {
            char* insert = malloc(wordLen + 1);
            strcpy(insert, splits[i]->start);
            char insertion [2] = {alphabet[j], '\0'};
            inserts[i] = strcat(strcat(insert, insertion), splits[i]->end);
        }
    }
    return inserts;
}

void editDistance1(char* word, hash_table* table) {
    char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    split** splits = splits(word);
    char** deletes = deletes(word);
    char** transposes = transposes(word);
    char** replaces = replaces(word, alphabet);
    char** inserts = inserts(word, alphabet);

    int wordLen = strlen(word);
    int alphaLen = strlen(alphabet);

    for (int i = 0; i < wordLen; i++) {
        add_word(deletes[i], table);
    }

    for (int i = 0; i < wordLen -1; i++) {
        add_word(transposes[i], table);
    }

    for (int i = 0; i < (wordLen * alphaLen); i++) {
        add_word(replaces[i], table);
    }

    for (int i = 0; i < (wordLen * alphaLen); i++) {
        add_word(inserts[i], table);
    }
}

hash_table* editDistance2(char* word) {

char* correct (char* word) {
    return NULL;
}
