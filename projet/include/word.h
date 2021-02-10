#ifndef WORD_H
#define WORD_H

char *next_word(FILE *f, unsigned int *nblin, unsigned int *nbcol);
int compareWord(mot_t* w1, mot_t* w2);
void addTailWord(dico* dictionary, mot_t* linkWord);
void addHeadWord(dico* dictionary, mot_t* linkWord);
void incWord(emplacement_t* location, unsigned int line, unsigned int colonne);
void displayWord(mot_t* word, FILE *filedes);

#endif