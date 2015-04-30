#include "autocorrectTrain.h"
#include "assert.h"
#include "string.h"
hash_table* training (void) {
    char* words[4] = {"this", "is", "2nd", "test"};
    return readWords(words, 4);
    
}
int main(void) {
    // test the word 'table'
    char* word = malloc(6 * sizeof(char));
    strncpy(word, "table", 5);
    split** splits_test = splits("table");

    // 'test' the deletes function
    /* printf("\n========== TESTING DELETES FUNCTION ==========\n"); */
    char** deletes_test = deletes(splits_test);
    assert(strcmp(deletes_test[0], "able") == 0);
    assert(strcmp(deletes_test[1], "tble") == 0);
    assert(strcmp(deletes_test[2], "tale") == 0);
    assert(strcmp(deletes_test[3], "tabe") == 0);
    assert(strcmp(deletes_test[4], "tabl") == 0);
    
    // 'test' the transposes function
    /* printf("\n========== TESTING TRANSPOSES FUNCTION ==========\n"); */
    char** transposes_test = transposes(splits_test);
    assert(strcmp(transposes_test[0], "atble") == 0);
    assert(strcmp(transposes_test[1], "tbale") == 0);
    assert(strcmp(transposes_test[2], "talbe") == 0);
    assert(strcmp(transposes_test[3], "tabel") == 0);

    /* printf("\n========== TESTING REPLACES FUNCTION ==========\n"); */
    char** replaces_test = replaces(splits_test, "abc");
    assert(strcmp(replaces_test[0], "aable") == 0);
    assert(strcmp(replaces_test[1], "bable") == 0);
    assert(strcmp(replaces_test[2], "cable") == 0);
    assert(strcmp(replaces_test[3], "table") == 0);
    assert(strcmp(replaces_test[4], "tbble") == 0);
    assert(strcmp(replaces_test[5], "tcble") == 0);
    assert(strcmp(replaces_test[6], "taale") == 0);
    assert(strcmp(replaces_test[7], "table") == 0);
    assert(strcmp(replaces_test[8], "tacle") == 0);
    assert(strcmp(replaces_test[9], "tabae") == 0);
    assert(strcmp(replaces_test[10], "tabbe") == 0);
    assert(strcmp(replaces_test[11], "tabce") == 0);
    assert(strcmp(replaces_test[12], "tabla") == 0);
    assert(strcmp(replaces_test[13], "tablb") == 0);
    assert(strcmp(replaces_test[14], "tablc") == 0);

    /* printf("\n========== TESTING INSERTS FUNCTION ==========\n"); */
    char** inserts_test = inserts(splits_test, "abc");
    assert(strcmp(inserts_test[0], "atable") == 0);
    assert(strcmp(inserts_test[1], "btable") == 0);
    assert(strcmp(inserts_test[2], "ctable") == 0);
    assert(strcmp(inserts_test[3], "taable") == 0);
    assert(strcmp(inserts_test[4], "tbable") == 0);
    assert(strcmp(inserts_test[5], "tcable") == 0);
    assert(strcmp(inserts_test[6], "taable") == 0);
    assert(strcmp(inserts_test[7], "tabble") == 0);
    assert(strcmp(inserts_test[8], "tacble") == 0);
    assert(strcmp(inserts_test[9], "tabale") == 0);
    assert(strcmp(inserts_test[10], "tabble") == 0);
    assert(strcmp(inserts_test[11], "tabcle") == 0);
    assert(strcmp(inserts_test[12], "tablae") == 0);
    assert(strcmp(inserts_test[13], "tablbe") == 0);
    assert(strcmp(inserts_test[14], "tablce") == 0);
    assert(strcmp(inserts_test[15], "tablea") == 0);
    assert(strcmp(inserts_test[16], "tableb") == 0);
    assert(strcmp(inserts_test[17], "tablec") == 0);
    printf("Passed all tests\n");

    return 0;
}
