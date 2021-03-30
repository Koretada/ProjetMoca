#include "maillon.h"
#include "word.h"
#include "dico.h"

#include "CuTest.h"
#include "AllTests.h"

#ifdef KLEE
#include <klee/klee.h>
#endif

#define FINAL 1
#define maxSizeWord 25

int main(int argc, char* argv[])
{
  FILE* f;
  if(argc == 2){
    f = fopen(argv[1], "r");
    if(f==NULL){
      printf("Erreur dans l'ouverture du fichier\n");
      exit(1);
      }
  }else {
    printf("Utilisation : ./main <FichieraOuvrir>\n");
    exit(1);
  }
  unsigned int* line = (unsigned int*) malloc(sizeof(unsigned int));
  unsigned int* colonne = (unsigned int*) malloc(sizeof(unsigned int));
  char* word = (char*) malloc(sizeof(char)*maxSizeWord);
  dico* dictionary = (dico*) malloc(sizeof(dico));
  dictionary->mot = NULL; // On initialise le mot de notre dictionnaire : resultat valgrind
  dictionary->next = NULL; // On initialise le next de notre dictionnaire : resultat valgrind
  #ifdef KLEE
  klee_make_symbolic(dictionary,sizeof(dico),"linetest");  
  //klee_assume((*line>0) && (*line < 100));
  //klee_make_symbolic(&dictionary,sizeof(dictionary),"dicotest");
 //klee_assume((*line >0) && (*line <500));
  #endif
  #if FINAL
  while(!feof(f)) {
    word = next_word(f,line,colonne); 
    addToDico(&dictionary,word,line,colonne); 
  }
  displayDico(dictionary);
  fclose(f);
  #else 
  RunAllTests();
  #endif
  //free(line);
  //free(colonne);
  //free(word);
  free(word);
  free(dictionary->mot);
  free(dictionary->next);
  free(dictionary);
  
  return 0;
}
