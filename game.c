#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "stage1.h"
#include "option.h"
//#include "score.h"
#include "credits.h"





int main()
{
  bool success1=false,success2=false,success3=false;
  int action=-1,a=-1,n,f;
SDL_Init(SDL_INIT_VIDEO);

SDL_Surface *screen;
screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Drago-Knight\t侍の物語",NULL);//titre de la fenetre
perssonage p;
background b;

//intro(screen);
//cinematique(screen);
do{
if (a!=-1) {action=a;a=-1;}
if (a==-1 && action != 0) menu(screen,&action);

switch(action)
{
case 1 ://new game
stage_1 (screen,&success1,&a);
//if (sucess1==true) stage_2 (screen,&success2);
//if (sucess2==true) stage_3 (screen,&success3);
if (success1==true) afficher_credit (screen);
break;
case 2 ://option
options(screen,&a, &n,&f);
break;
case 3 ://score board
//score_board(screen);
break;

}
}while (action != 0);
if (success1==true) printf("success\n");
else printf("fail\n");
SDL_Quit();
return 0 ;
}
