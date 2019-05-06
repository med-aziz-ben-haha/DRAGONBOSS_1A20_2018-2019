#ifndef end_H_INCLUDED
#define end_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



typedef struct dead
{
SDL_Surface *bg;
SDL_Surface *dante;
SDL_Rect rects[60];
SDL_Rect rect;
SDL_Rect pos;

}dead;

void setrects_dead(SDL_Rect* clip);
void initialiser (dead *p);
void afficher (dead *p,SDL_Surface *screen, int i);
void end_dead (SDL_Surface *screen);


  #endif // DS_H_INCLUDED
