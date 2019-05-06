#include "score.h"


void save_score ()
{

}

void read_score ()
{
  FILE* fichier=NULL;
    fichier=fopen("fichier/volume.txt","r");
    while(!feof(fichier)){
        fscanf(fichier,"%d %d",player[i],score[i]);
}
      fclose(fichier);
}

void afficher_score ()
{

}
