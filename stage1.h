#ifndef stage1_H_INCLUDED
#define stage1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


#include "perso.h"
#include "collision.h"
#include "background.h"
#include "enemy.h"
#include "stat.h"
#include "pause.h"
#include "imput.h"
#include "option.h"
#include "end.h"

void stage_1 (SDL_Surface *screen, bool *success,int *action);







  #endif // DS_H_INCLUDED
