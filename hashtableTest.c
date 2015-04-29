#include "hashtable.h"
int main(void)
{
    hash_table* mydict = create(HASHSIZE);
    add_word("first", mydict);
    add_word("second", mydict);
    add_word("first", mydict);
    print(mydict);
    bool x = check("first", mydict);
    printf(x ? "yes":"no");
    bool y = check("foo", mydict);
    printf(y ? "yes" : "no");

}
