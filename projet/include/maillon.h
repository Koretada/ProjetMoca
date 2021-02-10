#ifndef MAILLON_H
#define MAILLON_H
#include "structure.h"
int charToNum(char c);
char numToChar(int i);
unsigned int getMask(int k);
void setCharnum(maillon_t* link, int k, char c);
char getCharnum(maillon_t* link, int k);
maillon_t* stringToMaillon(char* word);
int isAvailable(char c);
int getSizeMaillon(maillon_t* link);
char* maillonToString(maillon_t* link);
#endif