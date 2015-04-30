#include "autocorrectTrain.c"
#include <ctype.h>

// changes txt file to list of strings, removes punctuation, makes lowercase
char** filetostrs (const char* filename, int numwords) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) return NULL;
	char* currentword = malloc(MAXSTRLEN * sizeof(char));
	fgets(currentword, MAXSTRLEN, fp);
	char** strlist = malloc(numwords * MAXSTRLEN * sizeof(char));
	int index = 0;
	while (currentword != NULL)
	{
		int wordlen = strlen(currentword);
		for (int i = 0; i < wordlen; i++)
		{
			currentword[i] = tolower(currentword[i]);
			if (!(isalpha(currentword[i])))
			{
				char* firsthalf = malloc(i*sizeof(char));
				char* secondhalf = malloc((wordlen -i) * sizeof(char));
				strncpy(firsthalf, currentword, i-1);
				strncpy(secondhalf, currentword + (i + 1), wordlen - i - 1);
				currentword = strcat(firsthalf, secondhalf);
				wordlen--;
			}
		}
		strlist[index] = currentword;
		index++;
		fgets(currentword, MAXSTRLEN, fp);
	}
	fclose(fp);
	return strlist;
}

// takes a list of incorrectly spelled words and corrects them, outputting 
// a list of corrected words
char** correctFile (char** incorrect) {
	return NULL;
}

// compares the corrected list of words to the list of incorrected words, returns
// integer number of disagreements
int compareFiles (char** correct, char** incorrect) {
	return 0;
}