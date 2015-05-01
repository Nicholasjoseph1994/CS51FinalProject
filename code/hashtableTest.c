#include "hashtable.h"
#include <assert.h>

int main(void)
{
    //create a hash table
    hash_table* mydict = create(HASHSIZE);

    //add first, first, First, fiRst, second to the dict
    add_word("first", mydict);
    add_word("second", mydict);
    add_word("first", mydict);
    add_word("first", mydict);

    //test the check, getFrequency, and is_empty
    assert(check("first", mydict));
    assert(!check("not_member", mydict));
    int freq = getFrequency("first", mydict);
    assert(freq == 3);
    assert(!is_empty(mydict));

    hash_table* emptydict = create(HASHSIZE);
    assert(is_empty(emptydict));
    printf("asserts passed\n");

}
