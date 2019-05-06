#include "collision.h"


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

	hero->x1=hero->rect_relative.x + hero->rect.w-30 ;
	hero->y1=hero->rect_relative.y  ;

	hero->x2=  hero->rect_relative.x + hero->rect.w-30;
	hero->y2= hero->rect_relative.y + hero->rect.h/2 ;


	hero->x3=hero->rect_relative.x + hero->rect.w-30 ;
	hero->y3= hero->rect_relative.y + hero->rect.h  ;

	//points a gauche de l'hero

	hero->x6=  hero->rect_relative.x ;
	hero->y6=  hero->rect_relative.y  ;

	hero->x7=  hero->rect_relative.x ;
	hero->y7=  hero->rect_relative.y + hero->rect.h/2   ;

	hero->x8= hero->rect_relative.x  ;
	hero->y8=  hero->rect_relative.y + hero->rect.h ;


	//points au milieu de l'hero
//up
	hero->x11=  hero->rect_relative.x+ hero->rect.w/2;
	hero->y11=  hero->rect_relative.y ;
//down
	hero->x12=  hero->rect_relative.x+ hero->rect.w/2;
	hero->y12=  hero->rect_relative.y + hero->rect.h ;



}

// retourne la couleur voir liste dans les variables globales

//pour le moment collision avec blanc

int collision_player_map_droite(background* acteurs , perssonage* hero)
{

SDL_Color color1 , color2 , color3  ;

int coll =-1;
color1=GetPixel (acteurs->mask , hero->x1 , hero->y1) ;
color2=GetPixel (acteurs->mask , hero->x2 , hero->y2) ;
color3=GetPixel (acteurs->mask , hero->x3 , hero->y3) ;



if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255))
	|| ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255) ) )
{
	coll = 0;
}


else if(((color1.r==0)  &&  (color1.g==0)  &&  (color1.b==0)) || ((color2.r==0)  &&  (color2.g==0)  &&  (color2.b==0))
	|| ((color3.r==0)  &&  (color3.g==0)  &&  (color3.b==0) ) )
{
	coll = 1;
}

return coll;
}

int collision_player_map_gauche(background* acteurs , perssonage* hero)
{

SDL_Color color6 , color7 , color8  ;

int coll = -1;

color6=GetPixel (acteurs->mask , hero->x6 , hero->y6) ;
color7=GetPixel (acteurs->mask , hero->x7 , hero->y7) ;
color8=GetPixel (acteurs->mask , hero->x8 , hero->y8) ;


if(((color6.r==255)  &&  (color6.g==255)  &&  (color6.b==255) )
	|| ((color7.r==255)  &&  (color7.g==255)  &&  (color7.b==255) ) || ((color8.r==255)  &&  (color8.g==255)  &&  (color8.b==255) ))
{
	coll = 0;
}

else if(((color6.r==0)  &&  (color6.g==0)  &&  (color6.b==0) )
	|| ((color7.r==0)  &&  (color7.g==0)  &&  (color7.b==0) ) || ((color8.r==0)  &&  (color8.g==0)  &&  (color8.b==0) ))
{
	coll = 1;
}

return coll;
}

int collision_player_map_top(background* acteurs , perssonage* hero)
{

SDL_Color  color11  ;

int coll = -1;

color11=GetPixel (acteurs->mask , hero->x11 , hero->y11) ;

if(((color11.r==255)  &&  (color11.g==255)  &&  (color11.b==255) ))
{
	coll = 0;
}

else if(((color11.r==0)  &&  (color11.g==0)  &&  (color11.b==0) ))
{
	coll = 1;
}

return coll;
}

int collision_player_map_bas(background* acteurs , perssonage* hero)
{

SDL_Color  color12 ;

int coll = -1;


color12=GetPixel (acteurs->mask , hero->x12 , hero->y12) ;

if(((color12.r==255)  &&  (color12.g==255)  &&  (color12.b==255)))
{
	coll = 0;
}

if(((color12.r==0)  &&  (color12.g==0)  &&  (color12.b==0)))
{
	coll = 1;
}


return coll;
}
