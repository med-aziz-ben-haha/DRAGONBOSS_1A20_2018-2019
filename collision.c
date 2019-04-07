#include "collision.h"


//***********************collision parfaite*************************************************************************



SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y)
{

SDL_Color color ;
Uint32 col=0;
char* pPosition = (char*) pSurface->pixels ;
pPosition += (pSurface->pitch * y);
pPosition += (pSurface->format->BytesPerPixel * x);

memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
SDL_GetRGB(col ,pSurface->format , &color.r , &color.g ,&color.b );


return (color) ;
}

void update_points_de_collision(perssonage* hero)
{

  //points a droite de l'hero

	hero->x1=hero->rect.x + hero->rect.w ;
	hero->y1=hero->rect.y ;

	hero->x2=  hero->rect.x + hero->rect.w;
	hero->y2= hero->rect.y ;


	hero->x3=hero->rect.x + hero->rect.w ;
	hero->y3= hero->rect.y + hero->rect.h ;


	hero->x4=hero->rect.x + hero->rect.w ;
	hero->y4= hero->rect.y  ;


	hero->x5=hero->rect.x + hero->rect.w ;
	hero->y5= hero->rect.y  ;

	//points a gauche de l'hero

	hero->x6=  hero->rect.x ;
	hero->y6=  hero->rect.y ;

	hero->x7=  hero->rect.x ;
	hero->y7=  hero->rect.y  ;

	hero->x8= hero->rect.x  ;
	hero->y8=  hero->rect.y + hero->rect.h;

	hero->x9=  hero->rect.x ;
	hero->y9=  hero->rect.y ;

	hero->x10=  hero->rect.x ;
	hero->y10=  hero->rect.y;

	//points au milieu de l'hero

	hero->x11=  hero->rect.x;
	hero->y11=  hero->rect.y ;

	hero->x12=  hero->rect.x;
	hero->y12=  hero->rect.y + hero->rect.h ;


}

// retourne la couleur voir liste dans les variables globales

//pour le moment collision avec blanc

int collision_player_map_droite(background* acteurs , perssonage* hero)
{

SDL_Color color1 , color2 , color3 , color4 , color5 ;

int coll = 0;
color1=GetPixel (acteurs->mask , hero->x1 , hero->y1) ;
color2=GetPixel (acteurs->mask , hero->x2 , hero->y2) ;
color3=GetPixel (acteurs->mask , hero->x3 , hero->y3) ;
color4=GetPixel (acteurs->mask , hero->x4 , hero->y4) ;
color5=GetPixel (acteurs->mask , hero->x5 , hero->y5) ;


if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255))
	|| ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255) ) || ((color4.r==255)  &&  (color4.g==255)  &&  (color4.b==255))
	|| ((color5.r==255)  &&  (color5.g==255)  &&  (color5.b==255) ))
{
	coll = blanc;
}

return coll;
}

int collision_player_map_gauche(background* acteurs , perssonage* hero)
{

SDL_Color color6 , color7 , color8 , color9 , color10 ;

int coll = 0;

color6=GetPixel (acteurs->mask , hero->x6 , hero->y6) ;
color7=GetPixel (acteurs->mask , hero->x7 , hero->y7) ;
color8=GetPixel (acteurs->mask , hero->x8 , hero->y8) ;
color9=GetPixel (acteurs->mask , hero->x9 , hero->y9) ;
color10=GetPixel (acteurs->mask , hero->x10 , hero->y10) ;

if(((color6.r==255)  &&  (color6.g==255)  &&  (color6.b==255) )
	|| ((color7.r==255)  &&  (color7.g==255)  &&  (color7.b==255) ) || ((color8.r==255)  &&  (color8.g==255)  &&  (color8.b==255) )
	 || ((color9.r==255)  &&  (color9.g==255)  &&  (color9.b==255) ) || ((color10.r==255)  &&  (color10.g==255)  &&  (color10.b==255)))
{
	coll = blanc;
}

return coll;
}

int collision_player_map_top(background* acteurs , perssonage* hero)
{

SDL_Color  color11  ;

int coll = 0;

color11=GetPixel (acteurs->mask , hero->x11 , hero->y11) ;

if(((color11.r==255)  &&  (color11.g==255)  &&  (color11.b==255) ))
{
	coll = blanc;
}

return coll;
}

int collision_player_map_bas(background* acteurs , perssonage* hero)
{

SDL_Color  color12 ;

int coll = 0;


color12=GetPixel (acteurs->mask , hero->x12 , hero->y12) ;

if(((color12.r==255)  &&  (color12.g==255)  &&  (color12.b==255)))
{
	coll = blanc;
}

return coll;
}
