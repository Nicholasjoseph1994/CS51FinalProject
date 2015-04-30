#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct split {
    char* start;
    char* end;
} split;

split* splits (char* word) {
    int len = strlen(word);
    split* splits = (split *) malloc((len + 1) * sizeof(split));
    for (int i = 0; i < len + 1; i++) {
        splits[i].start = malloc((i + 1) * sizeof(char));
        splits[i].end = malloc((len - i + 1) * sizeof(char));
        strncpy(splits[i].start, word, i);
        strncpy(splits[i].end, word + i, len-i);
    }
    return splits;
}

char** deletes(split* splits) {
    if (splits == NULL) return NULL;
    int splitslen = strlen(splits[0].end) + 1;
    char** strarray = malloc((splitslen - 1) * sizeof(char*));
    for (int i = 0; i < splitslen - 1; i++) 
        strarray[i] = strcat(splits[i].start, splits[i].end+1);
    return strarray;
}

char** transposes(split* splits) {
    if (splits == NULL) return NULL;
    int splitslen = strlen(splits[0].end) + 1;
    char** strarray = malloc((splitslen - 2) * sizeof(char*));
    for (int i = 0; i < splitslen - 2; i++)
    {
        char* temp = malloc(3 * sizeof(char));
        temp [0] = (splits[i].end) [1];
        temp [1] = (splits[i].end) [0];
        temp [2] = '\0';
        char* newend = strcat(temp, splits[i].end + 2);
        strarray[i] = strcat(splits[i].start, newend);
    }
    return strarray; 
}

char** replaces(split* splits) {
    if (splits == NULL) return NULL;
    char* alphabet = "abc";
    int alphalen = strlen(alphabet);
    int splitslen = strlen(splits[0].end) + 1;
    char** strarray = malloc((1 + (splitslen - 1) * alphalen) * sizeof(char*));
    for (int i = 0; i < splitslen - 1; i++)
    {
        for (int j = 0; j < alphalen; j++)
        {
            char* temp = malloc(2 * sizeof(char));
            char* temp_start = malloc((strlen(splits[i].start)) * sizeof(char));
            strcpy(temp_start, splits[i].start);
            printf("start = %s\n", temp_start);
            temp[0] = alphabet[j];
            temp[1] = '\0';
            char* newend = malloc((strlen(temp) + strlen(splits[i].end) + 1) * sizeof(char));
            strcpy(newend, strcat(temp,(splits[i].end) + 1));
            strarray[i * alphalen + j] = strcat(temp_start, newend);
            printf("newend = %s\n", newend);
        }
    }  
    return strarray;
}
// the function about is replace so example aable bable cable table tbble tcble ...
// example atable btable ctable taable tbable tcable ...

char** inserts(split* splits) {
    if (splits == NULL) return NULL;
    char* alphabet = "abc";
    int alphalen = strlen(alphabet);
    int splitslen = strlen(splits[0].end) + 1;
    char** strarray = malloc(splitslen * alphalen * sizeof(char*));
    {
        for (int i = 0; i < splitslen; i++)
        {
            for (int j = 0; j < alphalen; j++)
            {
                char* temp = malloc(2 * sizeof(char));
                char* temp_start = malloc((strlen(splits[i].start)) * sizeof(char)); 
                strcpy(temp_start, splits[i].start);
                printf("start = %s\n", temp_start);
                temp[0] = alphabet[j];
                temp[1] = '\0';
                char* newend = malloc((strlen(temp) + strlen(splits[i].end) + 1) * sizeof(char)); 
                strcpy(newend, strcat(temp,(splits[i].end))); 
                strarray[i * alphalen + j] = strcat(temp_start, newend);
                printf("newend = %s\n", newend); 
            }
        }
    }
    return strarray;
}

int main(void)
{
    // test the word 'table'
    char* word = malloc(6 * sizeof(char));
    strncpy(word, "table", 5);

    // 'test' the splits function
    printf("========== TESTING SPLITS FUNCTION ==========\n");
    split* splits_test = splits("table");
    for (int i = 0; i < 6; i++)
        printf("%s %s\n", splits_test[i].start, splits_test[i].end);

<<<<<<< HEAD
    //'test' the deletes function
    // printf("\n========== TESTING DELETES FUNCTION ==========\n");
    // char** deletes_test = deletes(splits_test);
    // for (int i = 0; i < 5; i++)
    //     printf("%s\n", deletes_test[i]);
=======
    // 'test' the deletes function
    printf("\n========== TESTING DELETES FUNCTION ==========\n");
    char** deletes_test = deletes(splits_test);
    for (int i = 0; i < 5; i++)
        printf("%s\n", deletes_test[i]);
>>>>>>> 631f5836fe2582ddcc2230e58c6030e0bef64dc7
    
<<<<<<< HEAD
    // // 'test' the transposes function
    // printf("\n========== TESTING TRANSPOSES FUNCTION ==========\n");
    // char** transposes_test = transposes(splits_test);
    // for (int i = 0; i < 4; i++)
    //     printf("%s\n", transposes_test[i]);
=======
    // 'test' the transposes function
    printf("\n========== TESTING TRANSPOSES FUNCTION ==========\n");
    char** transposes_test = transposes(splits_test);
    for (int i = 0; i < 4; i++)
        printf("%s\n", transposes_test[i]);

    printf("\n========== TESTING REPLACES FUNCTION ==========\n");
    char** replaces_test = replaces(splits_test);
    for (int i = 0; i < 15; i++)
        printf("%s\n", replaces_test[i]);

    printf("\n========== TESTING INSERTS FUNCTION ==========\n");
    char** inserts_test = inserts(splits_test);
    for (int i = 0; i < 18; i++)
        printf("%s\n", inserts_test[i]);
>>>>>>> 021bab801977ad8fa01d50027e627f57f8d0d8fc

    return 0;
}
