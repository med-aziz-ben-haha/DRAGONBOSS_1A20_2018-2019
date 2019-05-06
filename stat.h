#ifndef stat_H_INCLUDED
#define stat_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


#include "collision.h"


typedef struct  stat
{
SDL_Surface *stage;
TTF_Font *font_stage;
SDL_Rect stage_pos;
SDL_Surface *icon;
SDL_Rect icon_pos;
SDL_Surface *health;
SDL_Rect health_pos;
SDL_Rect health_camera[61];
SDL_Surface *mana;
SDL_Rect mana_pos;
SDL_Rect mana_camera[61];
SDL_Surface *lives;
TTF_Font *font_lives;
SDL_Rect lives_pos;
SDL_Surface *score;
TTF_Font *font_score;
SDL_Rect score_pos;
int fh,fm;
int nb_life;
int val_score;
int health_level;
}stat;




void initialiser_stats (stat *s);
void animation_health_down (stat *p, int i);
void animation_health_up (stat *p);
void animation_mana_up (stat *p);
void animation_mana_down (stat *p);
void afficher_stats (stat *s,SDL_Surface *fenetre);
void update_health (stat *s, enemie e, perssonage *p , background *b);




  #endif // DS_H_INCLUDED
