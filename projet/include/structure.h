#ifndef STRUCTURE_H
#define STRUCTURE_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
/**
 * \file structure.h
 * \brief Les structures utilisées pour le projet.
 */


/**
 * \struct maillon_t
 * \brief La structure qui contient les caractères du mot
 *
 * maillon_t est une liste chaînée 
 * contient un elem (uint32_t) (6 lettres maxi) 
 * next est null si le mot fait moins de 6 lettres.   
 */

typedef struct maillon_t maillon_t;
struct maillon_t {
  uint32_t elem;
  maillon_t* next;
};

/**
 * \struct emplacement_t
 * \brief Correspond a l'emplacement du mot 
 *
 * emplacement_t est une liste chaînée. 
 * contient le numero de ligne (>0) et colonne du début de mot (>0).  
 * next est null si il n'y a pas d'autres occurences. 
 */

typedef struct emplacement_t emplacement_t;
struct emplacement_t {
  unsigned int line;
  unsigned int colonne;
  emplacement_t* next;
};

/**
 * \struct mot_t
 * \brief Structure du mot 
 *
 * mot_t est une liste chaine. 
 * contient la tête/queue du mot, les emplacements des occurences du mot.  
 * queue_mot pointe sur la tête si la taille du mot < 6. 
 * queue_liste est null si il n'y a pas d'autres occurences du mots
 */

typedef struct mot_t mot_t;
struct mot_t {
  maillon_t* tete_mot;
  maillon_t* queue_mot;
  emplacement_t* tete_liste;
  emplacement_t* queue_liste;
};

/**
 * \struct dico
 * \brief Correspond a notre dictionnaire de mots
 *
 * dico est une liste chaînée. 
 * contient les mots de notre texte.   
 * next est null si il n'y a pas d'autres mots.
 */

typedef struct dico dico;
struct dico {
  mot_t* mot;
  dico* next;
};

#endif