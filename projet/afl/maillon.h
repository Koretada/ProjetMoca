#ifndef MAILLON_H
#define MAILLON_H
#include "structure.h"

/**
* \file maillon.h
* \brief Les fonctions liées aux maillons. 
*/

/**
 * \fn int charToNum(char c)
 * \brief Convertit un char en int.
 *
 * \param c est un char.
 * \return le code ascii du caractère. 
 */

int charToNum(char c);

/**
 * \fn char numToChar(int i)
 * \brief Convertit un int en char. 
 *
 * \param i est un int.
 * \return le caractère du code ascii. 
 */

char numToChar(int i);

/**
 * \fn unsigned int getMask(int k)
 * \brief Récupère le masque correspondant à l'entier k. 
 *
 * \param k est un entier [0;5]
 * \return le masque correspondant à l'entier k.  
 */

unsigned int getMask(int k);

/**
 * \fn void setCharnum(maillon_t* link, int k, char c)
 * \brief Défini.....
 *
 * \param k est un entier [0;5]
 * \return ne retourne rien. (void) 
 */
 
void setCharnum(maillon_t* link, int k, char c);

/**
 * \fn char getCharnum(maillon_t* link, int k)
 * \brief Défini.....
 *
 * \param k est un entier [0;5]
 * \return ne retourne rien. (void) 
 */

char getCharnum(maillon_t* link, int k);

/**
 * \fn maillon_t* stringToMaillon(char* word)
 * \brief convertit un mot en maillon. 
 *
 * \param word est un array de char. 
 * \return un maillon contenant la chaine de caractère.  
 */

maillon_t* stringToMaillon(char* word);

/**
 * \fn int isAvailable(char c)
 * \brief Vérifie si c est un bien une lettre minuscule. 
 *
 * \param word c est un char. 
 * \return 1 si le char est valide, sinon 0
 */

int isAvailable(char c);

/**
 * \fn int getSizeMaillon(maillon_t* link)
 * \brief Détermine la taille du maillon.
 *
 * \param link est un maillon. 
 * \return la taille du maillon.
 */

int getSizeMaillon(maillon_t* link);

/**
 * \fn char* maillonToString(maillon_t* link)
 * \brief Convertit un maillon en chaine de caractère.
 *
 * \param link est un maillon.
 * \return le maillon convertit en chaine de caractère. 
 */

char* maillonToString(maillon_t* link);
#endif