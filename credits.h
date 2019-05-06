#ifndef credits_H_INCLUDED
#define credits_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct  credit
{
	    SDL_Surface *credits;
	    SDL_Rect camera;
}credit;

void afficher_credit (SDL_Surface *screen);






  #endif // DS_H_INCLUDED
