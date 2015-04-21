#include "bloom.h"
#include <stdlib.h>
#include <stdbool.h>
// implementing myself because stdmath uses doubles
int int_pow(int base, int exp) {
    int ret = 1;
    for (int i = 0; i < exp; i++) {
        ret *= exp;
    }
    return ret;
}
//djb2 hash from http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(char *str)
{
    int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; 
    return hash;
}
// sets the index'th bit of filter to 1
void set_to_one(int index, struct bloom_filter* filter) {
    int byte = index / 8;
    int offset = index % 8;
    filter->bytes[byte] ^= int_pow(2, offset);

}
bool check_one(int index, struct bloom_filter* filter) {
    int byte = index / 8;
    int offset = index % 8;
    return ((filter->bytes[byte] | int_pow(2, offset)) == filter->bytes[byte]);
}
void add_word(char* word, struct bloom_filter* filter) {
    // uses the djb2 hash as the seed
    int seed = hash(word);
    srand(seed);
    for (int i = 0; i < filter->k; i++) {
        set_to_one(rand() % filter->size, filter);
    }
}
bool check(char* word, struct bloom_filter* filter) {
    int seed = hash(word);
    for (int i = 0; i < filter->k; i++) {
        if (!(check_one(rand() % filter->size, filter))) {
            return false;
        }
    }
    return true;
}
