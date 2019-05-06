#include "option.h"




void read_volume (int *music, int *sfx)
{
	FILE* fichier=NULL;
	  fichier=fopen("fichier/volume.txt","r");
		while(!feof(fichier))
				fscanf(fichier,"%d %d",music,sfx);
		  fclose(fichier);
}

void save_volume (int *music, int *sfx)
{
	FILE* fichier=NULL;
	  fichier=fopen("fichier/volume.txt","w");
fprintf(fichier,"%d %d",(*music),(*sfx));
		  fclose(fichier);
}

int fullscreen(SDL_Surface *ecran)
{
	SDL_Surface *sure[5];
	int n=0,t;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;

	sure[4]=IMG_Load("graphic/menu/exit_msg.png");
    sure[0]=IMG_Load("graphic/menu/exit_msg_yes_selected.png");
	sure[1]=IMG_Load("graphic/menu/exit_msg_no_selected.png");
	sure[2]=IMG_Load("graphic/menu/exit_msg_yes_clicked.png");
	sure[3]=IMG_Load("graphic/menu/exit_msg_no_clicked.png");
//set back
SDL_Surface *back;
back=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,1000,300,32,0,0,0,0);
SDL_FillRect(back,NULL,SDL_MapRGB(ecran->format,0,0,0));
SDL_Rect bpos;
bpos.x=0;
bpos.y=180;

    while(1)
    {
    	SDL_BlitSurface(sure[n],NULL,ecran,&pos);
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
						if (n==0)//yes
						{SDL_BlitSurface(sure[2],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (50);								ecran=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);
    				return 0;
						}
						else if (n==1)//no
						{SDL_BlitSurface(sure[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (50);
							SDL_FreeSurface(sure[n]);
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
					SDL_BlitSurface(sure[2],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (50);								ecran=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);
				return 0;}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392 )
				{
					SDL_BlitSurface(sure[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (50);
					return 0;
				}
			break;
    	}
    }
		int i=0;
		for(i=0;i<5;i++)
		SDL_FreeSurface(sure[i]);
				SDL_FreeSurface(back);
}

void options(SDL_Surface *screen,int *action, int *next, int *finish)
{

SDL_Surface *background,*boutton_sfx[6],*boutton_music[6],*full_screen[3],*keys[3],*music[2],*sfx[2];
	int m=1,s=0,ks=0,fs=0,t,n=1,q=1,p_sfx,volume_sfx,p_music,volume_music,mp=0;
	read_volume (&volume_music,&volume_sfx);
	p_sfx=volume_sfx/20;
	p_music=volume_music/20;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	full_screen[0]=IMG_Load("graphic/option/full-screen-normal.png");
	full_screen[1]=IMG_Load("graphic/option/full-screen-selected.png");
	full_screen[2]=IMG_Load("graphic/option/full-screen-clicked.png");
	keys[0]=IMG_Load("graphic/option/key-settings-normal.png");
	keys[1]=IMG_Load("graphic/option/key-settings-selected.png");
keys[2]=IMG_Load("graphic/option/key-settings-clicked.png");
	background=IMG_Load("graphic/option/back.png");
	music[0]=IMG_Load("graphic/option/music-normal.png");
   music[1]=IMG_Load("graphic/option/music-selected.png");
	sfx[1]=IMG_Load("graphic/option/sfx-selected.png");
	sfx[0]=IMG_Load("graphic/option/sfx-normal.png");

{	boutton_sfx[0]=IMG_Load("graphic/option/sfx0.png");
	boutton_sfx[1]=IMG_Load("graphic/option/sfx20.png");
	boutton_sfx[2]=IMG_Load("graphic/option/sfx40.png");
	boutton_sfx[3]=IMG_Load("graphic/option/sfx60.png");
	boutton_sfx[4]=IMG_Load("graphic/option/sfx80.png");
	boutton_sfx[5]=IMG_Load("graphic/option/sfx100.png");}

{	boutton_music[0]=IMG_Load("graphic/option/music0.png");
	boutton_music[1]=IMG_Load("graphic/option/music20.png");
	boutton_music[2]=IMG_Load("graphic/option/music40.png");
	boutton_music[3]=IMG_Load("graphic/option/music60.png");
	boutton_music[4]=IMG_Load("graphic/option/music80.png");
	boutton_music[5]=IMG_Load("graphic/option/music100.png");}

//init sfx
	Mix_Chunk *sfx_sound;
	sfx_sound= Mix_LoadWAV("graphic/option/effect.wav");
//init music
Mix_Music *music_sound;
music_sound= Mix_LoadMUS("graphic/option/option.mp3");
Mix_VolumeMusic(volume_music);
Mix_PlayMusic(music_sound,-1);

	do{
	//affichage des images
	SDL_BlitSurface(background,NULL,screen,&pos);
    SDL_BlitSurface(full_screen[fs],NULL,screen,&pos);
    SDL_BlitSurface(sfx[s],NULL,screen,&pos);
    SDL_BlitSurface(music[m],NULL,screen,&pos);
      SDL_BlitSurface(keys[ks],NULL,screen,&pos);
				SDL_BlitSurface(boutton_sfx[p_sfx],NULL,screen,&pos);
					SDL_BlitSurface(boutton_music[p_music],NULL,screen,&pos);
    SDL_Flip(screen);

    	t=0;
    	if (SDL_WaitEvent(&event)){
    	switch(event.type)
{
case SDL_QUIT:
(*action)=0;
(*next)=0;
(*finish)=0;
	q=0;
break;
    		//avec clavier
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym)
    			{

    				case SDLK_UP:

						if (m==0 && s==0 && fs==0 && ks==0)
    				{s=1;}
    					if (m==1 && t==0){

    						ks=1;
    						m=0;
    				fs=0;
    						s=0;
    						t=1;
    						n=3;
    					}
    					else if(s==1 && t==0){
								//	if (mp==1) 	Mix_PlayMusic(music_sound,-1);
//mp=0;
                                m=1;
                                s=0;
                                ks=0;
                                fs=0;
                                t=1;
                n=1;
										      	}
    					else if (ks==1 && t==0){
    						s=1;
    						ks=0;
    					fs=0;
    						m=0;
    						t=1;
    		n=2;
    					}
                        else if (fs==1 && t==0)
                        {
                            s=1;
                            fs=0;
                            m=0;
                            ks=0;
                            t=1;
            n=2;
}
    				break;

    				case SDLK_DOWN:

    				if (m==0 && s==0 && ks==0 && fs==0)
    				{ks=1;}
    					if (m==1 && t==0){

                                m=0;
                                s=1;
                                ks=0;
                                fs=0;
                           n=2;
    					}
    					else if(s==1 && t==0){
							//	if (mp==1) 	Mix_PlayMusic(music_sound,-1);
//mp=0;
    						m=0;
    						s=0;
    						ks=1;
    						fs=0;
    						t=1;
    						n=3;
							}
    					else if (ks==1 && t==0){
    						ks=0;
    						fs=0;
    						m=1;
    						s=0;
    						t=1;
    						 n=1;

							}
                        else if (fs==1 && t==0)
                        {
                            ks=0;
                            s=0;
                            m=1;
                            fs=0;
                            t=1;
                             n=1;

									      }
    				break;
    				case SDLK_LEFT:
						if (n==1){
						if (volume_music>0)
						{
							p_music--;
							volume_music-=20;
						Mix_VolumeMusic(volume_music);
						}}
						else if (n==2){
						if (volume_sfx>0)
						{
							p_sfx--;
							volume_sfx-=20;
							mp=1;
						Mix_VolumeChunk(sfx_sound,volume_sfx);
				Mix_PlayChannel(-1,sfx_sound, 0);
						}}
    			else	if(n==3)	{
						if (ks==0 && t==0)
						{
							fs--;
							ks++;
							t=1;
						}
						else if (ks==1 && t==0)
						{
							fs++;
							ks--;
							t=1;
						}
						}
					break;

					case SDLK_RIGHT:
					if (n==1){
					if (volume_music<100)
					{
						p_music++;
						volume_music+=20;
					Mix_VolumeMusic(volume_music);
					}}
				else	if (n==2){
					if (volume_sfx<100)
					{
						p_sfx++;
						volume_sfx+=20;
						mp=1;
						Mix_VolumeChunk(sfx_sound,volume_sfx);
				Mix_PlayChannel(-1,sfx_sound, 0);
					}}
					else if(n==3)	{
						if (ks==0 && t==0)
						{
							fs--;
							ks++;
							t=1;
						}
						else if (ks==1 && t==0)
						{
							fs++;
							ks--;
							t=1;
						}
						}
					break;

    				case SDLK_RETURN:

    					if (ks==1)
    					{
    						SDL_BlitSurface(keys[2],NULL,screen,&pos);
    						SDL_Flip(screen);

    					//non definie
    					}
                        else if (fs==1)
                        {
                          SDL_BlitSurface(full_screen[2],NULL,screen,&pos);
    						SDL_Flip(screen);

                          fullscreen(screen);
                        }
    				break;
    			}
    		break;

//avec souris
   		case SDL_MOUSEMOTION:

    				m=0;
    				s=0;
    				fs=0;
    				ks=0;
    			if (event.motion.x>60 && event.motion.y>195 && event.motion.x<910 && event.motion.y<250)
    			{
    			m=1;

    			}

    			else if (event.motion.x>60 && event.motion.y>310 && event.motion.x<910 && event.motion.y<360)
    			{

    				s=1;

    			}
    			else if (event.motion.x>65 && event.motion.y>440 && event.motion.x<420 && event.motion.y<560 )
    			{
    				ks=1;

    			}
    			else if (event.motion.x>580 && event.motion.y>440 && event.motion.x<940 && event.motion.y<560 )
    			{
    				fs=1;

    			}

    		break;

    		case SDL_MOUSEBUTTONDOWN:
    			if (event.button.button==SDL_BUTTON_LEFT)
    			{
    			if (event.motion.x>295 && event.motion.y>195 && event.motion.x<355 && event.motion.y<250)
						{
							if (volume_music>0)
							{
								p_music--;
								volume_music-=20;
							Mix_VolumeMusic(volume_music);

							}
    				//modife music ---
    				}

						else if (event.motion.x>845 && event.motion.y>195 && event.motion.x<905 && event.motion.y<250 )
							{
								if (volume_music<100)
								{
									p_music++;
									volume_music+=20;
									Mix_VolumeMusic(volume_music);

								}
							//modife music +++
						}
					else	if (event.motion.x>295 && event.motion.y>310 && event.motion.x<355 && event.motion.y<360)
							{
								if (volume_sfx>0)
								{mp=1;
									p_sfx--;
									volume_sfx-=20;
									Mix_VolumeChunk(sfx_sound,volume_sfx);
							Mix_PlayChannel(-1,sfx_sound, 0);
								}
							//modife sfx ---
							}
    				else if (event.motion.x>845 && event.motion.y>310 && event.motion.x<905 && event.motion.y<360 )
							{
								if (volume_sfx<100)
								{mp=1;
									p_sfx++;
									volume_sfx+=20;
									Mix_VolumeChunk(sfx_sound,volume_sfx);
							Mix_PlayChannel(-1,sfx_sound, 0);
								}
    					//modife sfx+++
    				}
    				else if (ks==1)
    				{
    				ks=2;
    				SDL_Delay (100);

    				}
    				else if (fs==1)
    				{
    			fs=2;
    				SDL_Delay (100);
					fullscreen(screen);
					fs=0;
    				}
    				else if (event.motion.x>832 && event.motion.y>72 && event.motion.x<973 && event.motion.y<117 )
    			{
    				q= 0;

    			}
    			}
    		break;


    	}

    	}
save_volume (&volume_music,&volume_sfx);
 }
	while(event.key.keysym.sym!=SDLK_ESCAPE &&q!=0);



 	SDL_FreeSurface(background);
    	SDL_FreeSurface(full_screen[0]);
    	SDL_FreeSurface(full_screen[1]);
    	SDL_FreeSurface(full_screen[2]);
    	SDL_FreeSurface(keys[0]);
    	SDL_FreeSurface(keys[1]);
        SDL_FreeSurface(keys[2]);
    	SDL_FreeSurface(music[1]);
    	SDL_FreeSurface(music[0]);
    	SDL_FreeSurface(sfx[1]);
    	SDL_FreeSurface(sfx[0]);
}
