#include <stdbool.h>
#define FILTERSIZE 4096
#define K 4
struct bloom_filter {
  unsigned char* bytes;
  int k;
  int size;
};
// adds a word to the bloom filter
void add_word(char* word, struct bloom_filter* filter);
// checks if a word is in the bloom filter
bool check(char* word, struct bloom_filter* filter);

void print_filter(struct bloom_filter* filter);
void initialize(struct bloom_filter* filter);
