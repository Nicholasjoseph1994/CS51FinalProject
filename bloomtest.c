#include "bloom.h"
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    struct bloom_filter* testFilter = malloc(sizeof(struct bloom_filter));
    initialize(testFilter);
    add_word("hi", testFilter);
    print_filter(testFilter);

}
