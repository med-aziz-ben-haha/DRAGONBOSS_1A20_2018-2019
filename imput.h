#ifndef DS1_H_INCLUDED
#define DS1_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct Input
{
 int left,right,jump,acction,down;

} Input;

void initialiser_input (Input *I);






  #endif // DS_H_INCLUDED
