#include "credits.h"

void afficher_credit (SDL_Surface *screen)
{
	//music
  Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,1024);//1 -> mono ** 2 -> sterio
  Mix_Music *music;
  music= Mix_LoadMUS("graphic/credit/credits.mp3");
  Mix_PlayMusic(music,1);

  credit c;
//set images & camera
c.credits=IMG_Load("graphic/credit/credits.png");
c.camera.x=0;
c.camera.y=0;
c.camera.w=1000;
c.camera.h=600;

//set back
SDL_Surface *back;
back=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,1000,600,32,0,0,0,0);
SDL_FillRect(back,NULL,SDL_MapRGB(screen->format,0,0,0));
SDL_Rect pos;
pos.x=0;
pos.y=0;

SDL_Surface *note;
note=IMG_Load("graphic/credit/note.png");

  int done=1;

while(done)
{
//devloppers note
if (c.camera.y==0){
SDL_BlitSurface(back,NULL,screen,&pos);
SDL_BlitSurface(note,NULL,screen,&pos);
SDL_Flip(screen);
SDL_Delay (33000);}
  //afficher
	SDL_BlitSurface(back,NULL,screen,&pos);
 SDL_BlitSurface(c.credits,&c.camera,screen,NULL);
SDL_Flip(screen);


//scroll
c.camera.y+=600;
SDL_Delay (6000);

//arret scrolling
if (c.camera.y>=7800)
done=0;
}
SDL_FreeSurface (note);
SDL_FreeSurface (c.credits);
Mix_FreeMusic (music);
}
