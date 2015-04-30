#include "autocorrectTrain.h"
#include <string.h>
#include <ctype.h>

// changes txt file to list of strings, removes punctuation, makes lowercase
char** filetostrs (const char* filename, int numwords) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) return NULL;
	char* currentword = malloc(MAXSTRLEN * sizeof(char));
	fgets(currentword, MAXSTRLEN, fp);
	char** strlist = malloc(numwords * sizeof(char*));
    for (int index = 0; index < numwords; index++) {
		int wordlen = strlen(currentword);
		for (int i = 0; i < wordlen; i++)
		{
			currentword[i] = tolower(currentword[i]);
			if (!(isalpha(currentword[i])))
			{
				char* firsthalf = malloc(i*sizeof(char));
				char* secondhalf = malloc((wordlen - i + 1) * sizeof(char));
				strncpy(firsthalf, currentword, i);
				strncpy(secondhalf, currentword + i + 1, wordlen - i);
                strcpy(currentword, firsthalf);
				currentword = strcat(currentword, secondhalf);
				wordlen--;
                i--;
			}
		}
		strlist[index] = currentword;
        currentword = malloc(MAXSTRLEN * sizeof(char));
		fgets(currentword, MAXSTRLEN, fp);
	}
	fclose(fp);
	return strlist;
}

// takes a list of incorrectly spelled words and corrects them, outputting 
// a list of corrected words
char** correctWords (char** incorrect, int numWords, hash_table* dict) {
    char** corrects = malloc(MAXSTRLEN * numWords);

    for (int i = 0; i < numWords; i++) {
        corrects[i] = correct(incorrect[i], dict);
    }
    return corrects;
}

// compares the corrected list of words to the list of incorrected words, returns
// integer number of disagreements
int compareFiles (char** correct, int numWords, char** incorrect) {

    int errors = 0;
    for (int i = 0; i < numWords; i++) {

        if (strcmp(correct[i], incorrect[i])!=0) 
            errors++;
        
    }
    return errors;
}

int main (void)
{
	//TESTING FILETOSTRS
	char** noErrors = filetostrs("cattleTest.txt", 5676);
    printf("here1\n");
    char** errors = filetostrs("cattleTestIncorrect.txt", 5676);
    printf("here2\n");
    char** lotsOfWords = filetostrs("bigFormatted.txt", 1095639);
    printf("here3\n");
    hash_table* dict = readWords(lotsOfWords, 1095639);
    printf("here4\n");
    char** correctedVersion = correctWords(errors, 5676, dict);
    printf("here5\n");
    int numberWrong = compareFiles(noErrors, 5676, correctedVersion);
    printf(" the number we got wrong is %d\n", numberWrong);

}
