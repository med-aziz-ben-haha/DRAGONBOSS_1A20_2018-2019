#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



typedef struct enemie
	{

	SDL_Surface *enemie;
	SDL_Rect rect;
	SDL_Rect rects[90];
	int frame;
	int direction;
  int range;
	}enemie;

void setrects_enemie(SDL_Rect* clip);

void inisialiser_enemie (enemie *f);
void MoveEnnemi(enemie *E);
	void afficher_enemie (enemie *f,SDL_Surface *screen,SDL_Rect pos);
	void animation (enemie *p);
  void update_ennemi(enemie *E ,SDL_Surface *screen,SDL_Rect r);

#endif // DS_H_INCLUDED
