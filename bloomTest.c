#include "bloom.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(void) {
    struct bloom_filter* testFilter = malloc(sizeof(struct bloom_filter));
    initialize(testFilter);
    add_word("hi", testFilter);
    print_filter(testFilter);
    add_word("nick", testFilter);
    add_word("jackie", testFilter);
    add_word("manure", testFilter);
    assert(check("manure", testFilter));
    assert(check("jackie", testFilter));
    assert(!check("testing", testFilter));

}
