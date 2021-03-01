#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "CuTest.h"
#include "maillon.h"
#include "word.h"
#include "dico.h"

void compareWordTest (CuTest * tc){
  unsigned int* line = (unsigned int*) malloc(sizeof(int));
  unsigned int* colonne = (unsigned int*) malloc(sizeof(int));
  *line = 5;
  *colonne = 6;
  int i = 1;
  mot_t* mot, *mot2; 
  mot = generateMot_t ("walid", line, colonne);
  mot2 = generateMot_t ("walid", line, colonne);
  printf("Resultat attendu du test compareWord numero %d : SUCCESS \n",i++);
  CuAssertIntEquals (tc, 0, compareWord(mot,mot2)); // Resultat attendu 0 car mots similaires
  
  mot = generateMot_t ("walid", line, colonne);
  mot2 = generateMot_t ("rania", line, colonne);
  printf("Resultat attendu du test compareWord numero %d : SUCCESS \n",i++);
  CuAssertIntEquals (tc, 1, compareWord(mot,mot2)); // Resultat attendu 1 car R < W 

  mot = generateMot_t ("walid", line, colonne);
  mot2 = generateMot_t ("WALID", line, colonne);
  printf("Resultat attendu du test compareWord numero %d : SUCCESS \n",i++);
  CuAssertIntEquals (tc, 1, compareWord(mot,mot2)); // Resultat attendu 1 car MAJ avant minuscule dans table ascii
  
  mot = generateMot_t ("", line, colonne);
  mot2 = generateMot_t ("", line, colonne);
  printf("Resultat attendu du test compareWord numero %d : SUCCESS \n",i++);
  CuAssertIntEquals (tc, 0, compareWord(mot,mot2)); // Resultat attendu 0 car Mot vide
  
  mot = generateMot_t ("", line, colonne);
  mot2 = generateMot_t ("rania", line, colonne);
  printf("Resultat attendu du test compareWord numero %d : SUCCESS \n",i++);
  CuAssertIntEquals (tc, -1, compareWord(mot,mot2)); // Resultat attendu -1 car Mot vide
  
  mot = generateMot_t ("12345", line, colonne);
  mot2 = generateMot_t ("walid", line, colonne);
  printf("Resultat attendu du test compareWord numero %d : SUCCESS \n \n",i++);
  CuAssertIntEquals (tc, -1, compareWord(mot,mot2)); // Resultat attendu 0 car 1 < W dans la table ascii
  
}

void getSizeMaillonTest (CuTest * tc){
  char tab[32];
  maillon_t* newMaillon;
  int i = 1;
  
  strcpy(tab,"jesuisdeveloppeur");
  newMaillon = stringToMaillon(tab);
  printf("Resultat attendu du test getSizeMaillon numero %d : SUCCESS \n",i++);
  CuAssertIntEquals (tc, strlen(tab), getSizeMaillon(newMaillon));
  
  strcpy(tab,"rania");
  newMaillon = stringToMaillon(tab);
  printf("Resultat attendu du test getSizeMaillon numero %d : SUCCESS \n",i++);
  CuAssertIntEquals (tc, strlen(tab), getSizeMaillon(newMaillon));
  
  strcpy(tab,"walid");
  newMaillon = stringToMaillon(tab);
  printf("Resultat attendu du test getSizeMaillon numero %d : SUCCESS \n",i++);
  CuAssertIntEquals (tc, strlen(tab), getSizeMaillon(newMaillon));
  
  strcpy(tab,"12345");
  newMaillon = stringToMaillon(tab);
  printf("Resultat attendu du test getSizeMaillon numero %d : SUCCESS \n",i++);
  CuAssertIntEquals (tc, strlen(tab), getSizeMaillon(newMaillon));

  strcpy(tab,"");
  newMaillon = stringToMaillon(tab);
  printf("Resultat attendu du test getSizeMaillon numero %d : SUCCESS \n \n",i++);
  CuAssertIntEquals (tc, strlen(tab), getSizeMaillon(newMaillon));
}

void stringToMaillonViceVersaTest(CuTest * tc){ 
  maillon_t* newMaillon;
  int i = 1;
  char *tabOriginal1 = strdup("walid");
  newMaillon = stringToMaillon(tabOriginal1);
  char *tabTmp1 = maillonToString(newMaillon);
  printf("Resultat attendu du test stringToMaillonViceVersa numero %d : SUCCESS \n",i++);
  CuAssertStrEquals (tc, tabOriginal1, tabTmp1);
  free(tabOriginal1);
  free(tabTmp1);
  
  char *tabOriginal2 = strdup("r");
  newMaillon = stringToMaillon(tabOriginal2);
  char *tabTmp2 = maillonToString(newMaillon);
  printf("Resultat attendu du test stringToMaillonViceVersa numero %d : SUCCESS \n",i++);
  CuAssertStrEquals (tc, tabOriginal2, tabTmp2);
  free(tabOriginal2);
  free(tabTmp2);
  
  char *tabOriginal3 = strdup("jesuisdeveloppeur");
  newMaillon = stringToMaillon(tabOriginal3);
  char *tabTmp3 = maillonToString(newMaillon);
  printf("Resultat attendu du test stringToMaillonViceVersa numero %d : SUCCESS \n",i++);
  CuAssertStrEquals (tc, tabOriginal3, tabTmp3);
  free(tabOriginal3);
  free(tabTmp3);

  char *tabOriginal4 = strdup("");
  newMaillon = stringToMaillon(tabOriginal4);
  char *tabTmp4 = maillonToString(newMaillon);
  printf("Resultat attendu du test stringToMaillonViceVersa numero %d : SUCCESS \n \n",i++);
  CuAssertStrEquals (tc, tabOriginal4, tabTmp4);
  free(tabOriginal4);
  free(tabTmp4);
}

CuSuite *MaTestSuite (){
  CuSuite *suite = CuSuiteNew ();
  SUITE_ADD_TEST(suite, compareWordTest);
  SUITE_ADD_TEST(suite, getSizeMaillonTest);
  SUITE_ADD_TEST(suite, stringToMaillonViceVersaTest);
  return suite;
}



