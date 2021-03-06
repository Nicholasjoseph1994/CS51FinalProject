#include "autocorrectTrain.h"
#include <string.h>
#include <ctype.h>
#include <assert.h>

void removeChar(char* str, int index) {
    int len = strlen(str);
    for (int i = index; i < len; i++) {
        str[i] = str[i+1];
    }

}
// changes txt file to list of strings, removes punctuation, makes lowercase
char** filetostrs (const char* filename, int numwords) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) return NULL;
	char** strlist = malloc(numwords * sizeof(char*));
    for (int index = 0; index < numwords; index++) {
        char* currentword = malloc(MAXSTRLEN * sizeof(char));
		fgets(currentword, MAXSTRLEN, fp);
		int wordlen = strlen(currentword);
		for (int i = 0; i < wordlen; i++)
		{
			currentword[i] = tolower(currentword[i]);
			if (!(isalpha(currentword[i])))
			{
                removeChar(currentword, i);
				wordlen--;
                i--;
			}
		}
		strlist[index] = currentword;
	}
	fclose(fp);
	return strlist;
}

// takes a list of incorrectly spelled words and corrects them, outputting 
// a list of corrected words
char** correctWords (char** incorrect, int numWords, hash_table* dict) {
    char** corrects = malloc(numWords * sizeof(char*));

    for (int i = 0; i < numWords; i++) {
        corrects[i] = correct(incorrect[i], dict);
    }
    return corrects;
}

// compares the corrected list of words to the list of incorrected words, returns
// integer number of disagreements
int compareFiles (char** original, int numWords, char** ourCorrections) {

    int errors = 0;
    for (int i = 0; i < numWords; i++) {

        if (strcmp(original[i], ourCorrections[i])!=0)  {
            errors++;
        }
        
    }
    return errors;
}

int main (void)
{
	//TESTING FILETOSTRS
    printf("==========Autocorrecting The Communist Manifesto by Marx & Engels========== \n");
    int words = 11766;
    char** noErrors = filetostrs("manifesto.txt", words);
    printf("Step 1: loaded in manifesto with no misspellings (original)\n");
    char** errors = filetostrs("manifestoErrors.txt", words);
    printf("Step 2: loaded in manifesto with misspellings\n");
    char** lotsOfWords = filetostrs("bigFormatted.txt", 1095639);
    hash_table* dict = readWords(lotsOfWords, 1095639);
    printf("Step 3: loaded in large sample of words to populate our dictionary\n");
    char** correctedVersion = correctWords(errors, words, dict);
    printf("Step 4: ran autocorrect on the misspelled manifesto file\n");
    int numberWrong = compareFiles(noErrors, words, correctedVersion);
    printf("=====Finished=====\n");
    printf("There were %d words in the file and we got %d wrong\n", words, numberWrong);
    printf("Our success rate was %f\n", ((float) words - (float) numberWrong) / (float) words);
}
