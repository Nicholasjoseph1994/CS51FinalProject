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

    // 'test' the splits function
    printf("========== TESTING SPLITS FUNCTION ==========\n");
    split** splits_test = splits("table");
    for (int i = 0; i < 5; i++)
        printf("%s %s\n", splits_test[i]->start, splits_test[i]->end);

    // 'test' the deletes function
    printf("\n========== TESTING DELETES FUNCTION ==========\n");
    char** deletes_test = deletes(splits_test);
    for (int i = 0; i < 5; i++)
        printf("%s\n", deletes_test[i]);
    
    // 'test' the transposes function
    printf("\n========== TESTING TRANSPOSES FUNCTION ==========\n");
    char** transposes_test = transposes(splits_test);
    for (int i = 0; i < 4; i++)
        printf("%s\n", transposes_test[i]);

    printf("\n========== TESTING REPLACES FUNCTION ==========\n");
    char** replaces_test = replaces(splits_test, "abc");
    for (int i = 0; i < 15; i++)
        printf("%s\n", replaces_test[i]);

    printf("\n========== TESTING INSERTS FUNCTION ==========\n");
    char** inserts_test = inserts(splits_test, "abc");
    assert (strcmp(inserts_test[1], "btable") == 0);
    for (int i = 0; i < 18; i++)
        printf("%s\n", inserts_test[i]);


    return 0;
}
