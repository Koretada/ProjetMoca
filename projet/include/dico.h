#ifndef DICO_H
#define DICO_H

/**
 * \file dico.h
 * \brief Les fonctions utilisées pour les dictionnaires.
 */

/**
 * \fn void insertDico(dico** dictionary, mot_t* linkWord)
 * \brief Insere un mot dans un dictionnaire. 
 *
 * \param dictionary est un dictionnaire, linkWord est un mot. 
 * \return Ne retourne rien (void).
 */

void insertDico(dico** dictionary, mot_t* linkWord);

/**
 * \fn void addToDico(dico** dictionary, char* word, unsigned int* line, unsigned int* colonne)
 * \brief Créer un mot qui contient son emplacement et qui sera ajouté à un dictionnaire.
 *
 * \param dictionary est un dictionnaire, word est un mot, line et colonne sont >=0. 
 * \return Ne retourne rien (void).
 */
 
void addToDico(dico** dictionary, char* word, unsigned int* line, unsigned int* colonne);

/**
 * \fn void displayDico(dico* dictionary)
 * \brief Affiche le dictionnaire.
 *
 * \param dictionary est un dictionnaire.
 * \return Ne retourne rien (void).
 */

void displayDico(dico* dictionary);
#endif