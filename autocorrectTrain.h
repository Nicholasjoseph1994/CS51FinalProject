// trains our algorithm by filling a hashtable with the nubmer of times each word occurs
void readWords(hashtable* table, char** words);
// gives all the words that are edit distance 1 away
char** editDistance1(char* word);
// gives all the words that are edit distance 2 away
char** editDistance2(char* word);
// returns a subset of words that are valid words in our dictionary
char** valid_words(hashtable* table, char**words); 
// gives a valid word that is a possible correction
char* correct(char* word);

