#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblioH.h"
#define TAILLE_M 20

int fonctionClef(char* auteur){
  int somme=0;
  for (int i=0; i<strlen(auteur); i++){
    somme+=auteur[i];
  }
  return somme;
}

LivreH* creer_livre(int num, char* titre, char* auteur){
  LivreH* l=(LivreH*)malloc(sizeof(LivreH));
  l->num=num;
  l->titre=strdup(titre);
  l->auteur=strdup(auteur);
  l->clef=fonctionClef(auteur);
  l->suivant=NULL;
  return l;
}

void liberer_livre(LivreH* l){
  if (!l){
    printf("livre vide.\n");
    return;
  }
  free(l->titre);
  free(l->auteur);
  free(l);
}

BiblioH* creer_biblio(int m){
  BiblioH* b=(BiblioH*)malloc(sizeof(BiblioH));
  b->nE=0;
  b->m=m;
  b->T=(LivreH**)malloc(m*sizeof(LivreH*));
  for (int i=0; i<m; i++){
    (b->T)[i]=NULL;
  }
  return b;
}

void liberer_biblio(BiblioH* b){
  if (!b){
    printf("bibliothèque n'existe pas.\n");
    return;
  }
  if (!b->T){
    printf("bibliothèque vide.\n");
    return;
  }
  LivreH* cour;
  LivreH* supp;
  for (int i=0; i<b->m; i++){ // on libère les livres de chaque case s'il y a
    supp=(b->T)[i];
    while(supp){ // on libère les chainages s'il y a
      cour=supp->suivant;
      liberer_livre(supp);
      supp=cour;
    }
  }
  free(b->T);
  free(b);
}

int fonctionHachage(int clef, int m){
  double a=(sqrt(5)-1)/2; // constante A
  double res=floor(m*(clef*a-floor(clef*a)));
  return res;
}

void inserer(BiblioH* b,int num,char* titre,char* auteur){
  // on trouve dans quelle case de la table de hachage on insère le livre
  int i=fonctionHachage(fonctionClef(auteur), b->m);
  // on insère le livre à cette case si elle est vide
  if (!(b->T)[i]) (b->T)[i]=creer_livre(num, titre, auteur);
  // sinon on l'insère par chainage avec le livre déjà présent
  else (b->T)[i]->suivant=creer_livre(num, titre, auteur);
  b->nE++;
}

void afficher_livre(LivreH* l){
  printf("Livre numéro: %d\t Titre: %s\t Auteur: %s\n", l->num, l->titre, l->auteur);
}
