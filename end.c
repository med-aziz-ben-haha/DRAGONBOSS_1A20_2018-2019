#include "end.h"



void setrects_dead(SDL_Rect* clip)
{

clip[0].x=0;
clip[0].y=0;
clip[0].w=250;
clip[0].h=250;
int i=1;
for (i=1; i<15;i++)
{
clip[i].w=250;
clip[i].h=250;
clip[i].x=clip[i].w+clip[i-1].x;
clip[i].y=0;
}

}

void initialiser(dead *p)
{
p->bg=IMG_Load("graphic/dead.png");
p->dante=IMG_Load("graphic/hero/dante-die.png");
p->rect.x=350;
p->rect.y=300;
p->pos.x=0;
p->pos.y=0;
setrects_dead (p->rects);
}

void afficher (dead *p,SDL_Surface *screen, int i)
{
  SDL_BlitSurface(p->bg,NULL,screen,&p->pos);
	SDL_BlitSurface(p->dante,&p->rects[i],screen,&p->rect);
  SDL_Flip(screen);
  SDL_Delay (16);
}

void end_dead (SDL_Surface *screen)
{
  dead p;
  int i=0;
initialiser(&p);
Mix_Music *music_sound;
music_sound= Mix_LoadMUS("graphic/dead.mp3");
Mix_PlayMusic(music_sound,1);
afficher (&p,screen,i);
SDL_Delay(2500);
for (i=1;i<15;i++)
afficher (&p,screen,i);
SDL_Delay(1500);
}
