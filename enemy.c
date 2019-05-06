#include "enemy.h"


		int nb_frames_e=15;

void setrects_enemie(SDL_Rect* clip)
  {
//mvt left
  clip[0].x=0;
  clip[0].y=0;
  clip[0].w=150;
  clip[0].h=150;
int i=1;
for (i=1;i<nb_frames_e;i++)
{
  clip[i].w=150;
  clip[i].x=clip[i-1].x+clip[i].w;
  clip[i].y=0;
  clip[i].h=150;
}

//mvt right
clip[15].x=0;
clip[15].y=150;
clip[15].w=150;
clip[15].h=150;
i=16;
for (i=16;i<(2*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=150;
clip[i].h=150;
}

//atack right
clip[30].x=0;
clip[30].y=300;
clip[30].w=150;
clip[30].h=150;
i=31;
for (i=31;i<(3*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=300;
clip[i].h=150;
}

//attack left
clip[45].x=0;
clip[45].y=450;
clip[45].w=150;
clip[45].h=150;
i=46;
for (i=46;i<(4*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=450;
clip[i].h=150;
}

//wait left
clip[60].x=0;
clip[60].y=600;
clip[60].w=150;
clip[60].h=150;
i=61;
for (i=61;i<(5*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=600;
clip[i].h=150;
}

//wait right
clip[75].x=0;
clip[75].y=750;
clip[75].w=150;
clip[75].h=150;
i=76;
for (i=76;i<(6*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=750;
clip[i].h=150;
}

  }

void inisialiser_enemie (enemie *f)
{
f->enemie=IMG_Load("graphic/ennemi/ground-guy.png");
f->range=600;
f->rect.x=11000;
f->rect.y=440;
f->rect.w=150;
f->rect.h=150;
f->frame=74;
f->direction=0;
setrects_enemie(f->rects);
}

void MoveEnnemi(enemie *E)//right
{
          if (E->direction==1)
          {
            E->rect.x -=3;

          }
          if(E->direction==2)
          {
            E->rect.x +=3;
          }

}

	void afficher_enemie (enemie *f,SDL_Surface *screen,SDL_Rect pos)
	{
		SDL_BlitSurface(f->enemie,&f->rects[f->frame],screen,&pos);
	}

	void animation (enemie *p)
	{
		if (p->direction==1) // move left
		{
		p->frame++;
		if (p->frame==nb_frames_e-1)
			p->frame=0;
}

if (p->direction==2) // move right
{
p->frame++;
if (p->frame==2*nb_frames_e-1)
	p->frame=15;
}

if(p->direction==3) //attack right
{
  p->frame++;
  if (p->frame==3*nb_frames_e-1)
  	p->frame=30;
}

if(p->direction==4) //attack left
{
  p->frame++;
  if (p->frame==4*nb_frames_e-1)
  	p->frame=45;
}

if(p->direction==5) //wait left
{
  p->frame++;
  if (p->frame==5*nb_frames_e-1)
  	p->frame=60;
}

if(p->direction==6) //wait right
{
  p->frame++;
  if (p->frame==6*nb_frames_e-1)
  	p->frame=75;
}

	}

  void update_ennemi(enemie *E ,SDL_Surface *screen,SDL_Rect r)
	{
    //attack left E->rect.x-r.x>=-100 & move right E->rect.x -r.x <=-100 ground
      //attack right E->rect.x-r.x<=60 & move left E->rect.x-r.x >=60 ground
      //attack left & move right 70 air
        //attack right & move left 30 air

		if (E->rect.x - r.x <= (300) && E->rect.x-r.x >=60)  //move left
		{
			E->direction=1;
			MoveEnnemi(E);
if(E->frame>=15 || E->frame<0 ) E->frame=0;
		}
	else if ( E->rect.x-r.x<=60 && E->rect.x-r.x>0 ) 	//attack right
		{
				E->direction=3;
if(E->frame<=29 || E->frame>=45 ) 	E->frame=30;
}
  	else if (E->rect.x-r.x>=-100 && E->rect.x-r.x<0)   //attack left
    {
      E->direction=4;
if(E->frame<=44 || E->frame>=60 ) 	E->frame=45;
}
		else if (E->rect.x - r.x >= (-300) && E->rect.x -r.x <=-100) //move right
		{
			E->direction=2;
			MoveEnnemi(E);
      if(E->frame<=14 || E->frame>=30)  E->frame=15;

		}
		else if (E->rect.x - r.x < (-300)) //wait right
		{
			E->direction=6;
      if(E->frame<=74 || E->frame>=90)  E->frame=75;
	}
	else if (E->rect.x - r.x > (300)) 	//wait left
  {
			E->direction=5;

if(E->frame<=59 || E->frame>=75 ) 	E->frame=60;
		}
		       	}
