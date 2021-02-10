#ifndef STRUCTURE_H
#define STRUCTURE_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct maillon_t maillon_t;
struct maillon_t {
  uint32_t elem;
  maillon_t* next;
};

typedef struct emplacement_t emplacement_t;
struct emplacement_t {
  unsigned int line;
  unsigned int colonne;
  emplacement_t* next;
};

typedef struct mot_t mot_t;
struct mot_t {
  maillon_t* tete_mot;
  maillon_t* queue_mot;
  emplacement_t* tete_liste;
  emplacement_t* queue_liste;
};

typedef struct dico dico;
struct dico {
  mot_t* mot;
  dico* next;
};

#endif