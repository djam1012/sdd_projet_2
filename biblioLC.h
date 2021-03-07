#ifndef BIBLC
#define BIBLC

typedef struct livre{
  int num;
  char *titre;
  char *auteur;
  struct livre *suiv;
} Livre;

typedef struct biblio{
  Livre *L;
} Biblio;

Livre* creer_livre(int num,char* titre,char* auteur);
void liberer_livre(Livre* l);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);
void afficher_livre(Livre* l);
void afficher_biblio(Biblio* b);
Livre* recherche_ouvrage_num(Biblio* b, int num);
Livre* recherche_ouvrage_titre(Biblio* b, char* titre);
Biblio* recherche_ouvrage_auteur(Biblio* b, char* auteur);
void supprimer_ouvrage(Biblio* b, int num, char* titre, char* auteur);
Biblio* fusion_biblio(Biblio* b1, Biblio* b2);
Biblio* copier_biblio(Biblio* b);
Biblio* afficher_exemplaires(Biblio* b);

#endif
