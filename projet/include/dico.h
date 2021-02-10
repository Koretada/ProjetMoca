#ifndef DICO_H
#define DICO_H
void insertDico(dico* dictionary, mot_t* linkWord);
void addToDico(dico* dictionary, char* word, unsigned int* line, unsigned int* colonne);
void displayDico(dico* dictionary);
#endif