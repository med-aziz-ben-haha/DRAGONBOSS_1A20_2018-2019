#include "stage1.h"


#define GRAVITY 10
#define SPEED 5
#define MAX_SPEED 10
#define MAX_JUMP_SPEED 25





int ground=480;



void stage_1 (SDL_Surface *screen, bool *success,int *action)
{
TTF_Init();
	enemie f;
	int vm, vsfx;
	int stairs;
perssonage p;
background b;
int nb_stage=1;
	bool running=true;
	SDL_Event event;
Input I;
bool reload=true;
	initialiser_backround (&b);
	initialiser_perssonage (&p);
inisialiser_enemie (&f);
initialiser_input (&I);

stat st;
initialiser_stats (&st);
int next;

Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
Mix_Music *musique;
musique = Mix_LoadMUS("graphic/stages/stage1.mp3");
	read_volume (&vm,&vsfx);
Mix_VolumeMusic(vm);
Mix_PlayMusic(musique, -1);
SDL_EnableKeyRepeat(200,0);
while(running)
{
	next=-1;
while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
		(*action)=0;
			running=false;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:

				pause(screen,&next,nb_stage,action);
				read_volume (&vm,&vsfx);
				Mix_VolumeMusic(vm);
			Mix_PlayMusic(musique, -1);
				break;
			case SDLK_RIGHT:
				I.right=1;

			break;
			case SDLK_LEFT :
				I.left=1;

      		break;
			case SDLK_SPACE :
				I.jump=1;
				if(p.rect.y==ground)
								p.yvelocity = -55;
					p.xvelocity=MAX_JUMP_SPEED;
			break;
			case SDLK_UP :
						stairs = -5;
			break;
			case SDLK_DOWN :
				    stairs = 5;
			break;
			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;
			break;
			case SDLK_LEFT :
				I.left=0;
      		break;
			case SDLK_SPACE :
				I.jump=0;

			break;
			case SDLK_DOWN :
			I.down=0;
			//		stairs= 0;
			break;
			case SDLK_UP :
			I.down=0;
		//	stairs = 0;
			break;
			}
		break;
		}
	}


if (I.right==1)
{
	p.xvelocity+=1;
	animation_right(&p);
	if (I.jump==0) mouvementright (&p);
	else if (I.jump==1) jumpright (&p);
scrolling_right (&b,&p,screen);
}else if (I.left==1 )
{
	p.xvelocity+=SPEED;
	animation_left(&p);
	if (I.jump==0) mouvementleft (&p);
	else if (I.jump==1) jumpleft (&p);
		scrolling_left (&b,&p,screen);

}
else if (I.left==0 && I.down==0 && I.jump==0 && I.right==0 )
{
	animation_stable(&p);
}





if (collision_player_map_bas(&b , &p)!=1 )
{stairs=0;
	p.yvelocity+=GRAVITY;
 p.rect.y += p.yvelocity;
 p.rect_relative.y += p.yvelocity;}
 else{p.yvelocity=0;
	  p.yvelocity+=stairs;
  p.rect.y += p.yvelocity;
  p.rect_relative.y += p.yvelocity;}


 if(p.rect.y >= ground)
 	 {
 		 p.rect.y= ground;
		 p.rect_relative.y= ground;
 		 p.yvelocity = 0;
}


 if (p.rect_relative.x>5430  && p.rect_relative.x<5700 && p.rect.y<=178 ) ground=178;
else if (p.rect_relative.x>5630  && p.rect_relative.x<5890 && p.rect.y<=250) ground=250;
else if (p.rect_relative.x>5340  && p.rect_relative.x<5490 && p.rect.y<=282 ) ground=282;
else if (p.rect_relative.x>5270  && p.rect_relative.x<5350 && p.rect.y<=332 ) ground=332;
else if (p.rect_relative.x>5180 &&p.rect_relative.x<5280 && p.rect.y<=399) ground=399;
else if (p.rect_relative.x>7030 &&p.rect_relative.x<7325 && p.rect.y<=115) ground=115;
else if (p.rect_relative.x>7250 &&p.rect_relative.x<7525 && p.rect.y<=277) ground=277;
else if (p.rect_relative.x>7740 &&p.rect_relative.x<7850 && p.rect.y<=330) ground=330;
else if (p.rect_relative.x>7650 &&p.rect_relative.x<7765 && p.rect.y<=399) ground=399;
else ground=480;

SDL_Rect relcoord_perssonage={p.rect.x+b.x_relative,p.rect.y,p.rect.w,p.rect.h};
SDL_Rect relcoord={f.rect.x-b.x_relative,f.rect.y};

update_points_de_collision(&p);

if (collision_player_map_bas(&b , &p)==1 || collision_player_map_bas(&b , &p)==1)
st.val_score++;

if (p.rect_relative.x>=9900) // end map = 3000
{
  (*success)=true;
  running=0;
}


if (st.fh<=0) reload=false;
else if (st.fh>=59) reload=true;

update_health (&st,f,&p,&b);
afficher_background (screen,&b);
afficher_stats (&st,screen);
animation_mana_down (&st);
if (reload==true)
animation_health_up (&st);

//animation_mana_down (&st);
afficher_perssonage (&p,screen);
update_ennemi(&f ,screen,relcoord_perssonage);
animation (&f);
afficher_enemie (&f,screen,relcoord);
SDL_Flip(screen);
SDL_Delay(16);
if (st.nb_life<=0){
(*success)=false;
running=false;
 end_dead (screen);
}
if (next==0) running=0;
}
TTF_Quit();
}
