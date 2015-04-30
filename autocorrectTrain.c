#include "autocorrectTrain.h"
#include "string.h"

#define MAXSTRLEN 100

hash_table* readWords(char** words, int numWords) {
    hash_table* table = create(HASHSIZE);
    for (int i = 0; i < numWords; ++i) {
        add_word(words[i], table);
    }
    return table;
}
split** splits (char* word) {
    int len = strlen(word);
    // mallocs a list of splits
    split** splits = malloc(sizeof(split*) * len);
    for (int i = 0; i < len; i++) {
        split* s = malloc(sizeof(split));
        s->start = malloc((i+1) * sizeof(char));
        s->end = malloc((len - i + 1) * sizeof(char));
        strncpy(s->start, word, i);
        strncpy(s->end, word + i, len-i);
        splits[i] = s;
    }
    return splits;
}
void freeSplits(split** splits, int numSplits) {
    for (int i = 0; i < numSplits; i++) {
        free(splits[i]);
    }
    free(splits);
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
            char replacement [2] = {alphabet[j], '\0'};
            strcpy(replace, splits[i]->start);
            replaces[i*alphaLen + j] = strcat(strcat(replace, replacement), splits[i]->end + 1);
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
    char** inserts = malloc((wordLen+1) * alphaLen * sizeof(char*));
    for (int i = 0; i < wordLen; i++) {
        for (int j = 0; j < alphaLen; j++) {
            char* insert = malloc(wordLen + 1);
            char insertion [2] = {alphabet[j], '\0'};
            strcpy(insert, splits[i]->start);
            inserts[i*alphaLen+j] = strcat(strcat(insert, insertion), splits[i]->end);
        }
    }
    // deals with inserts on the end
    for (int j = 0; j < alphaLen; j++) {
        char* insert = malloc(wordLen + 1);
        char insertions[2] = {alphabet[j], '\0'};
        strcpy(insert, splits[0]->start);
        inserts[wordLen * alphaLen + j] = strcat(strcat(insert, splits[0]->end), insertions);

    }
    return inserts;
}

//make sure to create the hashtable outside of this function
hash_table* editDistance1(char* word) {
    hash_table* table = create(HASHSIZE);
    char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    split** the_splits = splits(word);
    char** deleted = deletes(the_splits);
    char** transposed = transposes(the_splits);
    char** replaced = replaces(the_splits, alphabet);
    char** inserted = inserts(the_splits, alphabet);
    freeSplits(the_splits, strlen(word));

    int wordLen = strlen(word);
    int alphaLen = strlen(alphabet);

    for (int i = 0; i < wordLen; i++) {
        add_word(deleted[i], table);
        free(deleted[i]);
    }

    for (int i = 0; i < wordLen -1; i++) {
        add_word(transposed[i], table);
        free(transposed[i]);
    }

    for (int i = 0; i < (wordLen * alphaLen); i++) {
        add_word(replaced[i], table);
        free(replaced[i]);
    }

    for (int i = 0; i < ((wordLen + 1) * alphaLen); i++) {
        add_word(inserted[i], table);
        free(inserted[i]);
    }
    free(deleted);
    free(transposed);
    free(replaced);
    free(inserted);
    return table;
}

hash_table* editDistance2(char* word, hash_table* dictionary) {

    hash_table* edits1 = editDistance1(word);
    
    hash_table* edits2 = create(HASHSIZE);

    // goes through all the words that are edit distance1
    for (int i = 0; i < edits1->buckets; i++) {
        hash_elt* elt = edits1->lists[i];
        while (elt != NULL)
        {
            // finds all the words that are edit distance 1 from each word
            hash_table* two_away = editDistance1(elt->word);

            // adds all of those words to edits2
            for (int j = 0; j < two_away->buckets; j++) {
                hash_elt* elt2 = two_away->lists[j];
                
                while (elt2 != NULL) {
                    // checks if the string is an actual word before adding
                    if (check(elt2->word, dictionary)) {
                        add_word(elt2->word, edits2);
                    }
                    elt2 = elt2->next;
                }
            }
            elt = elt->next;
        }
    }
    return edits2;
}

hash_table* known (hash_table* words, hash_table* dict) {
    hash_table* knownWords = create(HASHSIZE);

    for (int i = 0; i < words->buckets; i++)
    {
        hash_elt* currentword = words->lists[i];
        while (currentword != NULL)
        {
            if(check(currentword->word, dict))
            {
                add_word(currentword->word, knownWords);
            }
            currentword = currentword->next;
        }
    }
    return knownWords;
}

char* correct (char* word, hash_table* dict) {
    hash_table* candidates = NULL;

    if (check(word, dict)) {
        return word;
    }
        
    candidates = known(editDistance1(word), dict); 
    if (is_empty(candidates)) 
    {
        candidates = editDistance2(word, dict);
        if (is_empty(candidates)) {
            return word;
        }
    }

    int freqmax = 0;
    int freq = 0;
    char* correction;
    for (int i = 0; i < candidates->buckets; i++)
    {
        hash_elt* currentword = candidates->lists[i];
        while (currentword != NULL)
        {
            freq = getFrequency(currentword->word, dict) + 1;
            if (freq > freqmax)
            {
                freqmax = freq;
                correction = currentword->word;
            }
            currentword = currentword -> next;
        }
    }
    return correction;
}
