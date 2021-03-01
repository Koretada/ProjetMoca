#ifndef WORD_H
#define WORD_H

/**
* \file word.h
* \brief Les fonctions liées aux mots. 
*/

 
/**
 * \fn char *next_word(FILE *f, unsigned int *nblin, unsigned int *nbcol)
 * \brief Récupére le prochain mot.
 *
 * \param f fichier à ouvrir, nblin et nbcol qui sont supérieurs ou égales à 0.
 * \return Un tableau contenant les caractères du mot qui suit. 
 */

char *next_word(FILE *f, unsigned int *nblin, unsigned int *nbcol);

/**
 * \fn int compareWord(mot_t* w1, mot_t* w2)
 * \brief Compare deux mots. 
 *
 * \param w1 et w2 sont des mots.
 * \return -1 si w1 < w2, 1 si w1 > w2 et 0 si ils sont égaux. 
 */

int compareWord(mot_t* w1, mot_t* w2);

/**
 * \fn void addTailWord(dico* dictionary, mot_t* linkWord)
 * \brief Ajoute un mot en fin du dictionnaire.
 *
 * \param dictionary est un dico, linkWord est un mot_t. 
 * \return ne retourne rien. (void)
 */

void addTailWord(dico* dictionary, mot_t* linkWord);

/**
 * \fn void addHeadWord(dico** dictionary, mot_t* linkWord)
 * \brief Ajoute un mot en tête du dictionnaire.
 *
 * \param dictionary est un dico, linkWord est un mot_t. 
 * \return ne retourne rien. (void)
 */
 
void addHeadWord(dico** dictionary, mot_t* linkWord);

/**
 * \fn void incWord(emplacement_t* location, unsigned int line, unsigned int colonne)
 * \brief Ajoute la position du mot en fonction de la ligne et colonne. 
 *
 * \param location est un emplacement, line et colonne >=0
 * \return ne retourne rien. (void)
 */

void incWord(emplacement_t* location, unsigned int line, unsigned int colonne);

/**
 * \fn void displayWord(mot_t* word, FILE *filedes)
 * \brief Affiche le mot et son début en ligne et colonne dans le fichier.
 *
 * \param word est un mot_t non null, filedes est un fichier. 
 * \return ne retourne rien. (void)
 */

void displayWord(mot_t* word, FILE *filedes);

/**
 * \fn mot_t generateMot_t(char* string, unsigned int* line, unsigned int* colonne)
 * \brief Convertit une chaine de caractère avec sa position en line et colone en un mot_t. 
 *
 * \param string est une chaîne de caractère, line et colonne >= 0. 
 * \return retourne un mot_t. 
 */

mot_t* generateMot_t(char* string, unsigned int* line, unsigned int* colonne);


#endif