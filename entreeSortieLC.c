#include "biblioLC.h"
#include "entreeSortieLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Biblio* charger_n_entrees(char* nomfic, int n){
  Biblio* resultat=creer_biblio();
  char ligne[256];
  int i=0;
  char num[30];
  char titre[30];
  char auteur[30];
  FILE* fic ;
  fic=fopen(nomfic,"r");

  if (!fic){
    printf("Problème lors de l'ouverture du fichier\n");
    return NULL;
  }
  printf("fichier ouvert avec succès\n");

  while (i<n){
    for (int c=0; c<30; c++){
      num[c]='\0';
      titre[c]='\0';
      auteur[c]='\0'; // on les réinitialise
    }
     int j=0;
     char* temp=fgets(ligne , 256, fic);

    while (ligne[j]!=' '){
       strncat(num, &ligne[j], 1);
       j++;
    }

    j++;
    while (ligne[j]!=' '){
      strncat(titre, &ligne[j], 1);
      j++;
    }

    j++;
    while (ligne[j]!=' '){
      strncat(auteur, &ligne[j], 1);
      j++;
    }

    i++;
    inserer_en_tete(resultat, atoi(num),titre,auteur);
  }
  fclose(fic);
  return resultat;
}

void enregistrer_biblio(Biblio *b, char* nomfic){
    FILE* fic ;
    fic=fopen(nomfic,"w");
    if (!fic){
      printf("Problème lors de l'ouverture du fichier\n");
      return;
    }
    if (!b){
      printf("la bibliothèque est vide, on ne peut pas la copier\n");
      return;
    }
    Livre* cour=b->L; // on crée une variable temporaire qui stocke le livre à libérer
    while(cour){
      fprintf(fic,"%d %s %s\n",cour->num,cour->titre,cour->auteur);
      if(b->L->suiv==NULL){
        fclose(fic);
        return;
      }
      cour=cour->suiv; // on passe au livre suivant L
    }
    fclose(fic);
}
