#ifndef menu_H_INCLUDED
#define menu_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "option.h"


int quit (SDL_Surface *ecran);
void menu (SDL_Surface *screen, int *action);
void coa_on(SDL_Surface *ecran);
void coa_off(SDL_Surface *ecran);
void logo_on(SDL_Surface *ecran);
void logo_off(SDL_Surface *ecran);
void sdl_on(SDL_Surface *ecran);
void sdl_off(SDL_Surface *ecran);
void intro (SDL_Surface *screen);
void cinematique(SDL_Surface *ecran);





  #endif // DS_H_INCLUDED
