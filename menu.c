/*
called functions
score board retour 3
options retour 2
game retour 1
*/
#include "menu.h"


int quit (SDL_Surface *ecran)
{
	SDL_Surface *bg,*exit[5];
	int n=0,t,done=1;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	bg=IMG_Load("graphic/menu/background-menu.jpg");
	exit[4]=IMG_Load("graphic/menu/exit_msg.png");
    exit[0]=IMG_Load("graphic/menu/exit_msg_yes_selected.png");
	exit[1]=IMG_Load("graphic/menu/exit_msg_no_selected.png");
	exit[2]=IMG_Load("graphic/menu/exit_msg_yes_clicked.png");
	exit[3]=IMG_Load("graphic/menu/exit_msg_no_clicked.png");

    while(done)
    {
    	SDL_BlitSurface(bg,NULL,ecran,&pos);
    	SDL_BlitSurface(exit[n],NULL,ecran,&pos);
    	SDL_Flip(ecran);
    	SDL_WaitEvent(&event);
    	t=0;
    	switch(event.type)
    	{
			//avec clavier
    		case SDL_KEYDOWN:

    			switch(event.key.keysym.sym)
    			{
    				case SDLK_LEFT:
    				if (n==4) n=0;
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RIGHT:
					if (n==4) n=0;
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RETURN:
						if (n==0)
						{SDL_BlitSurface(exit[2],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (200);
							SDL_FreeSurface(bg);
							SDL_FreeSurface(exit[n]);
							return 1;
						}
						else if (n==1)
						{SDL_BlitSurface(exit[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (200);
							SDL_FreeSurface(bg);
							SDL_FreeSurface(exit[n]);
							return 0;
						}
					break;

    			}
    		break;
// avec souris

    		case SDL_MOUSEMOTION:
			n=4;
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					n=0;
				}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392)
				{
					n=1;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					SDL_BlitSurface(exit[2],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (200);
					return 1;
				}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392 )
				{
					SDL_BlitSurface(exit[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (200);
					return 0;
				}
			break;

    	}
    }

}

void menu (SDL_Surface *screen, int *action)
{
	 int vm, vsfx;
read_volume (&vm,&vsfx);
	//creation background
SDL_Surface *background=NULL;
background =IMG_Load("graphic/menu/background-menu.jpg");
SDL_Rect background_pos;
background_pos.x=0;
background_pos.y=0;
int c=-1;
//introduction musique
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,1024);//1 -> mono ** 2 -> sterio
Mix_Music *music;
music= Mix_LoadMUS("graphic/menu/background.mp3");
Mix_VolumeMusic(vm);
Mix_PlayMusic(music,-1);//-1 play till the program ends ** n number of times


SDL_Surface *newgame[3],*loadgame[3],*option[3],*exit[3];

	SDL_Rect pos;
	pos.x=0;
	pos.y=0;

	SDL_Event event;
	int ng=1,op=0,ex=0,lg=0,t,save;
	//chargement d'image
    newgame[0]=IMG_Load("graphic/menu/new-game-normal.png");
    loadgame[0]=IMG_Load("graphic/menu/score-normal.png");
    loadgame[2]=IMG_Load("graphic/menu/score-clicked.png");
    loadgame[1]=IMG_Load("graphic/menu/score-selected.png");
    option[0]=IMG_Load("graphic/menu/options-normal.png");
    exit[0]=IMG_Load("graphic/menu/exit-normal.png");
    newgame[1]=IMG_Load("graphic/menu/new-game-selected.png");
    newgame[2]=IMG_Load("graphic/menu/new-game-clicked.png");
    option[1]=IMG_Load("graphic/menu/options-selected.png");
   option[2]=IMG_Load("graphic/menu/options-clicked.png");
    exit[1]=IMG_Load("graphic/menu/exit-selected.png");
     exit[2]=IMG_Load("graphic/menu/exit-clicked.png");

SDL_EnableKeyRepeat(0,0);
    int done=1;
    while (done)
    {

    //affichage des images
	SDL_BlitSurface(background,NULL,screen,&pos);
    SDL_BlitSurface(loadgame[lg],NULL,screen,&pos);
    SDL_BlitSurface(option[op],NULL,screen,&pos);
    SDL_BlitSurface(newgame[ng],NULL,screen,&pos);
      SDL_BlitSurface(exit[ex],NULL,screen,&pos);
    SDL_Flip(screen);
    	t=0;
    	if (SDL_WaitEvent(&event)){
    	switch(event.type)
{
case SDL_QUIT :
(*action)=0;
c=0;
break;

    		//avec clavier
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym){

    				case SDLK_UP:
    				if (ng==0 && op==0 && ex==0 && lg==0)
    				{lg=1;}
    					if (ng==1 && t==0){
    						ex=1;
    						ng=0;
    						op=0;
    						t=1;
    					}
    					else if(op==1 && t==0){
    						if (lg==0)
                            {
                                ng=0;
                                lg=1;
                                op=0;
                                ex=0;
                                t=1;
                            }
                            else{
                                ng=1;
                                op=0;
                                ex=0;
                                t=1;
                            }
    					}
    					else if (ex==1 && t==0){
    						op=1;
    						ex=0;
    						ng=0;
    						t=1;
    					}
                        else if (lg==1 && t==0)
                        {
                            ng=1;
                            lg=0;
                            op=0;
                            ex=0;
                            t=1;
                        }
    				break;

    				case SDLK_DOWN:
    				if (ng==0 && op==0 && ex==0 && lg==0)
    				{ex=1;}
    					if (ng==1 && t==0){
    						if (lg==0)
                            {
                                ng=0;
                                lg=1;
                                op=0;
                                ex=0;
                                t=1;
                            }
                            else{
                                ng=0;
                                op=1;
                                ex=0;
                                t=1;
                            }
    					}
    					else if(op==1 && t==0){
    						ng=0;
    						op=0;
    						ex=1;
    						t=1;
    					}
    					else if (ex==1 && t==0){
    						op=0;
    						ex=0;
    						ng=1;
    						t=1;
    					}
                        else if (lg==1 && t==0)
                        {
                            ng=0;
                            lg=0;
                            op=1;
                            ex=0;
                            t=1;
                        }
    				break;

    				case SDLK_RETURN:
    					if (ng==1)
    					{
    						SDL_BlitSurface(newgame[2],NULL,screen,&pos);
    						SDL_Flip(screen);
    						SDL_Delay(100);
(*action)=1;
c=0;
    					}
    					else if (op==1)
    					{
    						SDL_BlitSurface(option[2],NULL,screen,&pos);
    						SDL_Flip(screen);
    						SDL_Delay(100);

    					(*action)=2;
							c=0;
    					}
							else if (ex==1)
	    				{
	    			SDL_BlitSurface(exit[2],NULL,screen,&pos);
	    						SDL_Flip(screen);
	    				SDL_Delay (200);
						if (quit(screen)==1){
								(*action)=0;
						c= 0;}
	    				}
                        else if (lg==2)
                        {
                          SDL_BlitSurface(loadgame[2],NULL,screen,&pos);
    						SDL_Flip(screen);
    						SDL_Delay(100);
                      (*action)=3;
                      c=0;  }
    				break;
    			}
    		break;

//avec souris
    		case SDL_MOUSEMOTION:

    				ex=0;
    				ng=0;
    				op=0;
    				lg=0;
    			if (event.motion.x>60 && event.motion.y>300 && event.motion.x<320 && event.motion.y<350 )
    			{
    			ng=1;

    			}

    			else if (event.motion.x>60 && event.motion.y>420 && event.motion.x<320 && event.motion.y<470 )
    			{
    				op=1;

    			}
    			else if (event.motion.x>60 && event.motion.y>365 && event.motion.x<320 && event.motion.y<410 )
    			{
    				lg=1;

    			}
    			else if (event.motion.x>60 && event.motion.y>490 && event.motion.x<320 && event.motion.y<560 )
    			{
    				ex=1;

    			}

    		break;

    		case SDL_MOUSEBUTTONDOWN:
    			if (event.button.button==SDL_BUTTON_LEFT)
    			{
    				if (ng==1)
    				{
    					ng=2;
    					SDL_Delay (100);
    			(*action)=1;
					c=0;
    				}
    				else if (op==1)
    				{
    				op=2;
    				SDL_Delay (100);
    			(*action)=2;
					c=0;
    				}
    				else if (lg==1)
    				{
    				lg=2;
    				SDL_Delay (100);
    			(*action)=3;
					c=0;
    				}
    				else if (ex==1)
    				{
    			SDL_BlitSurface(exit[2],NULL,screen,&pos);
    						SDL_Flip(screen);
    				SDL_Delay (200);
					if (quit(screen)==1){
							(*action)=0;
					c= 0;}
    				}
    			}
    		break;


    	}

    	}
if (c==0) break;
 }
    	SDL_FreeSurface(background);
    	SDL_FreeSurface(newgame[2]);
    	SDL_FreeSurface(option[2]);
    	SDL_FreeSurface(exit[2]);
    	SDL_FreeSurface(newgame[0]);
    	SDL_FreeSurface(newgame[1]);
    	SDL_FreeSurface(option[0]);
    	SDL_FreeSurface(option[1]);
    	SDL_FreeSurface(loadgame[0]);
    	SDL_FreeSurface(exit[0]);
    	SDL_FreeSurface(exit[1]);

}

void coa_on(SDL_Surface *ecran)
{
	SDL_Surface *frame;
	SDL_Event event;
	char chaine2[50];
	char chaine[8];
	int i=0,j=10;
	SDL_Rect posframe;
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;
SDL_Surface *transition;
transition=IMG_Load("graphic/transition.png");
SDL_BlitSurface(transition,NULL,ecran,&posframe);
	for(i=1;i<11;i++){
		sprintf(chaine,"%d",i);
		strcat(chaine,".png");
	    strcpy(chaine2,"graphic/coa/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,ecran,&posframe);
		SDL_Flip(ecran);
		SDL_Delay(100);
		SDL_FreeSurface(frame);

	}

}

void coa_off(SDL_Surface *ecran)
{
	SDL_Surface *frame;
	SDL_Event event;
	char chaine2[50];
	char chaine[8];
	int i=10;
	SDL_Rect posframe;
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;

SDL_Surface *transition;
transition=IMG_Load("graphic/transition.png");
SDL_Rect transition_pos;
transition_pos.x=0;
transition_pos.y=0;

	for(i=10;i>0;i--){
		sprintf(chaine,"%d",i);
		strcat(chaine,".png");
	    strcpy(chaine2,"graphic/coa/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,ecran,&posframe);
		SDL_Flip(ecran);
		SDL_Delay(50);
		SDL_BlitSurface(transition,NULL,ecran,&transition_pos);
		SDL_FreeSurface(frame);
	}
SDL_FreeSurface(transition);
}

void logo_on(SDL_Surface *ecran)
{
	SDL_Surface *frame;
	SDL_Event event;
	char chaine2[50];
	char chaine[8];
	int i=0,j=10;
	SDL_Rect posframe;
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;
SDL_Surface *transition;
transition=IMG_Load("graphic/transition.png");
SDL_BlitSurface(transition,NULL,ecran,&posframe);
	for(i=1;i<11;i++){
		sprintf(chaine,"%d",i);
		strcat(chaine,".png");
	    strcpy(chaine2,"graphic/logo/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,ecran,&posframe);
		SDL_Flip(ecran);
		SDL_Delay(100);
		SDL_FreeSurface(frame);

	}

}

void logo_off(SDL_Surface *ecran)
{
	SDL_Surface *frame;
	SDL_Event event;
	char chaine2[50];
	char chaine[8];
	int i=10;
	SDL_Rect posframe;
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;

SDL_Surface *transition;
transition=IMG_Load("graphic/transition.png");
SDL_Rect transition_pos;
transition_pos.x=0;
transition_pos.y=0;

	for(i=10;i>0;i--){
		sprintf(chaine,"%d",i);
		strcat(chaine,".png");
	    strcpy(chaine2,"graphic/logo/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,ecran,&posframe);
		SDL_Flip(ecran);
		SDL_Delay(50);
		SDL_BlitSurface(transition,NULL,ecran,&transition_pos);
		SDL_FreeSurface(frame);
	}
SDL_FreeSurface(transition);
}

void sdl_on(SDL_Surface *ecran)
{
	SDL_Surface *frame;
	SDL_Event event;
	char chaine2[50];
	char chaine[8];
	int i=0,j=10;
	SDL_Rect posframe;
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;
SDL_Surface *transition;
transition=IMG_Load("graphic/transition.png");
SDL_BlitSurface(transition,NULL,ecran,&posframe);
	for(i=1;i<11;i++){
		sprintf(chaine,"%d",i);
		strcat(chaine,".png");
	    strcpy(chaine2,"graphic/sdl/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,ecran,&posframe);
		SDL_Flip(ecran);
		SDL_Delay(100);
		SDL_FreeSurface(frame);

	}

}

void sdl_off(SDL_Surface *ecran)
{
	SDL_Surface *frame;
	SDL_Event event;
	char chaine2[50];
	char chaine[8];
	int i=10;
	SDL_Rect posframe;
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;

SDL_Surface *transition;
transition=IMG_Load("graphic/transition.png");
SDL_Rect transition_pos;
transition_pos.x=0;
transition_pos.y=0;

	for(i=10;i>0;i--){
		sprintf(chaine,"%d",i);
		strcat(chaine,".png");
	    strcpy(chaine2,"graphic/sdl/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,ecran,&posframe);
		SDL_Flip(ecran);
		SDL_Delay(50);
		SDL_BlitSurface(transition,NULL,ecran,&transition_pos);
		SDL_FreeSurface(frame);
	}
SDL_FreeSurface(transition);
}


void intro (SDL_Surface *screen)
{
//creation logo
	SDL_Surface *logo=NULL;
logo= IMG_Load("graphic/logo/logo.png"); // image logo
SDL_Rect logo_pos;
logo_pos.x=0;
logo_pos.y=0;

//creation transition
SDL_Surface *transition;
transition=IMG_Load("graphic/transition.png");
SDL_Rect transition_pos;
transition_pos.x=0;
transition_pos.y=0;

//introduction effet wav
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);//1 -> mono ** 2 -> sterio
Mix_Chunk *music;
music= Mix_LoadWAV("graphic/menu/transition.wav");
  Mix_VolumeChunk(music, MIX_MAX_VOLUME/2);



	//affichage coat of arms pour 1.5 sec repos 0.3 sec puis logo  pour 1.5 sec repos 0.3 sec
Mix_PlayChannel(1,music, 0); //(chaine,nom fichier,nb_fois_joués=nb_fois souhaité-1) joue 1 fois par defaut
SDL_Delay(100);
coa_on(screen);
SDL_Delay(2500);
coa_off(screen);
SDL_BlitSurface(transition,NULL,screen,&transition_pos);
SDL_Flip(screen);
SDL_Delay(500);

Mix_PlayChannel(1,music, 0);SDL_Delay(100);
logo_on(screen);
SDL_Delay(2500);
logo_off(screen);
SDL_BlitSurface(transition,NULL,screen,&transition_pos);
SDL_Flip(screen);
SDL_Delay(500);

Mix_PlayChannel(1,music, 0);SDL_Delay(100);
sdl_on(screen);
SDL_Delay(2500);
sdl_off(screen);
SDL_BlitSurface(transition,NULL,screen,&transition_pos);
SDL_Flip(screen);
SDL_Delay(500);

SDL_FreeSurface(transition);
}

void cinematique(SDL_Surface *ecran)
{int n=642;
	SDL_Surface *frame;
	SDL_Event event;
	char chaine2[50];
	char chaine[50];
	int i=0,j=10;
	SDL_Rect posframe;
	Mix_Music *music_sound;
	music_sound= Mix_LoadMUS("graphic/cinematique/story.mp3");
	Mix_PlayMusic(music_sound,1);
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;
	for(i=1;i<n;i++) // n = nb images de cinematique
	{
		sprintf(chaine,"%04d",i);
		strcat(chaine,".jpeg");
	    strcpy(chaine2,"graphic/cinematique/img");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,ecran,&posframe);
		SDL_Flip(ecran);
		SDL_Delay(80);
		SDL_FreeSurface(frame);

	}

}
