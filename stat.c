#include "stat.h"



void setrects_health(SDL_Rect* clip)
{
  int i=1;

  clip[0].h=30;
  clip[0].y=0;
  clip[0].w=300;
  clip[0].x=0;

  for (i=1;i<20;i++)
  {
    clip[i].h=30;
    clip[i].y=0;
    clip[i].w=300;
  clip[i].x=clip[i].w+clip[i-1].x;
  }

  clip[20].h=30;
  clip[20].y=30;
  clip[20].w=300;
  clip[20].x=0;
  i=21;
  for (i=21;i<40;i++)
  {
    clip[i].h=30;
    clip[i].y=30;
    clip[i].w=300;
  clip[i].x=clip[i].w+clip[i-1].x;
  }

  clip[40].h=30;
  clip[40].y=60;
  clip[40].w=300;
  clip[40].x=0;
  i=41;
  for (i=41;i<60;i++)
  {
    clip[i].h=30;
    clip[i].y=60;
    clip[i].w=300;
  clip[i].x=clip[i].w+clip[i-1].x;
  }

}

void setrects_mana(SDL_Rect* clip)
{
  int i=1;

  clip[0].h=15;
  clip[0].y=0;
  clip[0].w=150;
  clip[0].x=0;

  for (i=1;i<20;i++)
  {
    clip[i].h=15;
    clip[i].y=0;
    clip[i].w=150;
  clip[i].x=clip[i].w+clip[i-1].x;
  }

  clip[20].h=15;
  clip[20].y=0;
  clip[20].w=150;
  clip[20].x=0;
i=21;
  for (i=21;i<40;i++)
  {
    clip[i].h=15;
    clip[i].y=15;
    clip[i].w=150;
  clip[i].x=clip[i].w+clip[i-1].x;
  }

  clip[40].h=15;
  clip[40].y=30;
  clip[40].w=150;
  clip[40].x=0;
i=41;
  for (i=41;i<60;i++)
  {
    clip[i].h=15;
    clip[i].y=30;
    clip[i].w=150;
  clip[i].x=clip[i].w+clip[i-1].x;
  }

}

void initialiser_stats (stat *s)
{
SDL_Color color={255,255,255};
s->icon=IMG_Load("graphic/stages/lives.png");
//SDL_SetColorKey(s->icon, SDL_SRCCOLORKEY, SDL_MapRGB(s->icon->format, 255, 255, 255));
s->font_lives=TTF_OpenFont("fonts/font_lives.ttf",40);
TTF_SetFontStyle(s->font_lives,TTF_STYLE_NORMAL);
s->font_stage=TTF_OpenFont("fonts/font_stage.ttf",40);
TTF_SetFontStyle(s->font_stage,TTF_STYLE_BOLD);
s->stage=TTF_RenderText_Solid(s->font_stage,"STAGE I ",color);
s->font_score=TTF_OpenFont("fonts/font_score.ttf",40);
TTF_SetFontStyle(s->font_score,TTF_STYLE_NORMAL);
s->health=IMG_Load("graphic/stages/health-bar.png");
s->mana=IMG_Load("graphic/stages/mana-bar.png");
setrects_health (s->health_camera);
setrects_mana (s->mana_camera);

s->fh=59;
s->fm=0;

s->health_pos.x=400;
s->health_pos.y=22;
s->mana_pos.x=405;
s->mana_pos.y=40;
s->stage_pos.x=30;
s->stage_pos.y=20;
s->lives_pos.x=320;
s->lives_pos.y=18;
s->icon_pos.x=260;
s->icon_pos.y=18;
s->score_pos.x=780;
s->score_pos.y=23;

s->nb_life=6;
s->val_score=0;
}

void animation_health_down (stat *p, int i)
{
	if(i==2) while ( p->fh<19) 	p->fh++; //from 100->60
  	if(i==4) while	 (p->fh<39) 	p->fh++; //from 60->30
    	if(i==6) while	(p->fh<59) 	p->fh++; //from 30->0
}

void animation_health_up (stat *p)
{
    	if (p->fh>0) 	p->fh--; //from 60->100
}

void animation_mana_up (stat *p)
{
	if (p->fm>40) 	p->fm--; //from 0->30
  	if (p->fm>20) 	p->fm--; //from 30->60
    	if (p->fm>0) 	p->fm--; //from 60->90
}

void animation_mana_down (stat *p)
{
	if (p->fm<19) 	p->fm++; //from 100->60
  	if (p->fm<39) 	p->fm++; //from 60->30
    	if (p->fm<59) 	p->fm++; //from 60->30
}

void afficher_stats (stat *s,SDL_Surface *fenetre)
{
SDL_BlitSurface(s->icon,NULL,fenetre,&s->icon_pos);
SDL_BlitSurface(s->stage,NULL,fenetre,&s->stage_pos);
SDL_BlitSurface(s->health,&s->health_camera[s->fh],fenetre,&s->health_pos);
SDL_BlitSurface(s->mana,&s->mana_camera[s->fm],fenetre,&s->mana_pos);
SDL_Color color={255,255,255};
char remaining[4];
sprintf(remaining,"x%d",s->nb_life);
s->lives=TTF_RenderText_Solid(s->font_lives,remaining,color);
SDL_BlitSurface(s->lives,NULL,fenetre,&s->lives_pos);
char score[15];
sprintf(score,"score : %04d",s->val_score);
s->score=TTF_RenderText_Solid(s->font_score,score,color);
SDL_BlitSurface(s->score,NULL,fenetre,&s->score_pos);

}

void update_health (stat *s, enemie e, perssonage *p , background *b)
{
  int r=-1,l=-1,u=-1,d=-1;
    d=collision_player_map_bas(b ,p);
  r=collision_player_map_droite(b ,p);
  l=collision_player_map_gauche(b ,p);

//down health by ennemy attack
if (e.direction==3 || e.direction==4) p->hit++;
if (r==0 || l==0 || d==0) p->hit+=2;
if(p->hit!=0)
{
  animation_health_down (s,p->hit);
if (e.direction==3)
{if (b->camera.x<=150)
  {p->rect.x-=150;
    p->rect_relative.x-=150;}
//
if (b->camera.x>150)
{
  b->x_relative-=150;
  b->camera.x-=150;
  p->rect_relative.x-=150;

}
}
else if (e.direction==4)
{
  b->x_relative+=150;
  b->camera.x+=150;
  p->rect_relative.x+=150;

}
if (d==0 ) {
   b->x_relative-=150;
   b->camera.x-=150;
   p->rect_relative.x-=150;

  }
if (r==0 ) {
  b->x_relative-=150;
  b->camera.x-=150;
  p->rect_relative.x-=150;

 }
if (l==0 ) {
   b->x_relative+=150;
   b->camera.x+=150;
   p->rect_relative.x+=150;

  }
if(p->hit==6) {p->hit=0;s->nb_life--;}
}
}
