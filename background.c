#include "background.h"



void initialiser_backround (background *b)
{
b->x_relative=0;
b->y_relative=-80;
b->background=NULL;
b->bg=NULL;
b->pos.x=0;
b->pos.y=0;
b->camera.x=0;
b->camera.y=-80;
b->camera.w=1000;
b->camera.h=600;
b->background=IMG_Load("graphic/stages/fbg1.png");
b->mask=IMG_Load("graphic/stages/maskbg1.jpg");
b->bg=IMG_Load("graphic/stages/bbg1.jpg");
}

void afficher_background (SDL_Surface *screen,background *b)
{
  SDL_BlitSurface(b->bg,NULL,screen,&b->pos);
SDL_BlitSurface(b->background,&b->camera,screen,NULL);


}

void scrolling_right (background *b,perssonage *p,SDL_Surface *screen)
{
	if (b->camera.x<10000-1010)
	{
		b->x_relative+=p->xvelocity;
		b->camera.x+=p->xvelocity;
    p->rect_relative.x+=p->xvelocity;

	}
}

void scrolling_left (background *b,perssonage *p,SDL_Surface *screen)
{
	if (b->camera.x>0)
	{
		b->x_relative-=p->xvelocity;
		b->camera.x-=p->xvelocity;
    p->rect_relative.x-=p->xvelocity;

	}
}
