#ifndef BIBLIO_H
#define BIBLIO_H

typedef struct livreh{
  int clef;
  int num;
  char* titre;
  char* auteur;
  struct livreh* suivant;
}LivreH;

typedef struct table{
  int nE; // nb elems dans la table de hachage
  int m; // taille de la table
  LivreH** T; // table de hachage avec resolution des collisions par chainage
}BiblioH;

int fonctionClef(char* auteur);
LivreH* creer_livre(int num, char* titre, char* auteur);
void liberer_livre(LivreH* l);
BiblioH* creer_biblio(int m);
void liberer_biblio(BiblioH* b);
int fonctionHachage(int cle, int m);
void inserer(BiblioH* b,int num,char* titre,char* auteur);
void afficher_livre(LivreH* l);
void afficher_biblio(BiblioH* b);
LivreH* recherche_ouvrage_num(BiblioH* b, int num);

#endif
