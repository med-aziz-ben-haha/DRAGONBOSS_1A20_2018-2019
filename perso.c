#include "perso.h"


#define GRAVITY 10
#define SPEED 5
#define MAX_SPEED 10
#define MAX_JUMP_SPEED 25

int nb_frames_p=15;

void setrects(SDL_Rect* clip)
{
	//vers droite
clip[0].x=0;
clip[0].y=0;
clip[0].w=100;
clip[0].h=100;
int i=1;
for (i=1; i<nb_frames_p;i++)
{
clip[i].w=100;
clip[i].h=100;
clip[i].x=clip[i].w+clip[i-1].x;
clip[i].y=0;
}

//vers gauche
clip[15].x=0;
clip[15].y=100;
clip[15].w=100;
clip[15].h=100;
 i=16;
for (i=16;i<(2*nb_frames_p);i++)
{
clip[i].w=100;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=100;
clip[i].h=100;
}
//stable right
clip[30].x=0;
clip[30].y=200;
clip[30].w=100;
clip[30].h=100;
i=31;
for (i=31;i<(3*nb_frames_p);i++)
{
clip[i].w=100;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=200;
clip[i].h=100;
}


//stable right
clip[45].x=0;
clip[45].y=300;
clip[45].w=100;
clip[45].h=100;
i=46;
for (i=46;i<(4*nb_frames_p);i++)
{
clip[i].w=100;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=300;
clip[i].h=100;
}

}

void initialiser_perssonage (perssonage *p)
{
p->personnage=IMG_Load("graphic/hero/dante-run.png");
p->frame=29;
p->stable_direction=0;
p->rect.x=0;
p->rect.y=300;
p->rect_relative.x=0;
p->rect_relative.y=300;
p->rect.w=100;
p->rect.h=100;
p->xvelocity=0;
p->yvelocity=0;
p->hit=0;
setrects (p->rects);
}

void afficher_perssonage (perssonage *p,SDL_Surface *screen)
{
	SDL_BlitSurface(p->personnage,&p->rects[p->frame],screen,&p->rect);
}

void animation_right (perssonage *p)
{
  p->stable_direction=0;
	if(p->frame<=0 || p->frame>=15)
		p->frame=0;
	p->frame++;
	if (p->frame>=nb_frames_p)
		p->frame=0;
}

void animation_left (perssonage *p)
{
  p->stable_direction=1;
	if(p->frame<=14 || p->frame>=30)
		p->frame=15;

	p->frame++;
	if (p->frame>=2*nb_frames_p)
		p->frame=16;
}

void animation_stable (perssonage *p)
{
  if (p->stable_direction==0)
  {
	if(p->frame<=29 || p->frame>=45)
		p->frame=30;

	p->frame++;
	if (p->frame>=3*nb_frames_p)
		p->frame=30;
  }
else if (p->stable_direction==1)
{
if(p->frame<=44 || p->frame>=60)
  p->frame=45;

p->frame++;
if (p->frame>=4*nb_frames_p)
  p->frame=45;
}

}

void mouvementright (perssonage *p)
{
  //p->xvelocity+=0.005;
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x<350 || p->rect_relative.x>=8991)
{

p->rect.x+=p->xvelocity;
p->rect_relative.x+=p->xvelocity;
}
}

void mouvementleft (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x>150){
p->rect.x-=p->xvelocity;
p->rect_relative.x-=p->xvelocity;
}
}

void jumpright (perssonage *p)
{

if (p->xvelocity>=MAX_JUMP_SPEED)
	p->xvelocity=MAX_JUMP_SPEED;
if (p->rect.x<350)
{
  p->xvelocity+=5;
p->rect.x+=p->xvelocity;
p->rect_relative.x+=p->xvelocity;
}
}

void jumpleft (perssonage *p)
{
if (p->xvelocity>=MAX_JUMP_SPEED)
	p->xvelocity=MAX_JUMP_SPEED;
if (p->rect.x>0){
p->rect.x-=p->xvelocity;
p->rect_relative.x-=p->xvelocity;
}
}
