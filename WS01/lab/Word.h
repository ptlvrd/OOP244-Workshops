/* name- patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id- 158605220
* date- 11/09/2023
*
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*
*/
#ifndef SDDS_Word_H 
#define SDDS_Word_H 
#include "cStrTools.h"
#define MAX_WORD_LEN 21

namespace sdds {

    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };

    int searchWords(const Word words[], int num, const char word[]);
    void addWord(Word words[], int* index, const char newWord[]);
    int readWord(char* word, FILE* fptr, int maxLen);
    void title(const char* value, int len);
    void endList();
    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
    void print(const Word* w, int gotoNextLine, int len);
    int findMaxLen(const Word words[], int noOfWords);
    void listWords(const Word words[], int noOfWords, const char* theTitle);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt, int sortType);
    int totalCount(const Word* words, int num);
    void wordStats(const char* filename);
    void programTitle();


}
#endif
