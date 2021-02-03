#include "structure.h"
#include "dico.h"
#include "maillon.h"
#include "word.h"

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
  unsigned int* line = (unsigned int*) malloc(sizeof(int));
  unsigned int* colonne = (unsigned int*) malloc(sizeof(int));
  char* word = (char*) malloc(sizeof(char)*maxSizeWord);
  dico* dictionary = (dico*) malloc(sizeof(dico));
  if(f!=NULL){
    while(!feof(f)) {
      word = next_word(f,line,colonne); 
      addToDico(dictionary,word,line,colonne); 
    }
  displayDico(dictionary);
  fclose(f);
  }
  return 0;
}
