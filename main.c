/** 
* @file main.c
* @brief Testing program
* @author MINDS UNITS
* @version 0.1
* @date avril 30 , 2021 
*
*Testing scrolling for background and split screen
*
*/


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fonction.h"
#define SCREEN_W 1300
#define SCREEN_H 500
int main (int argc, char *argv[]){
background b;
///////// 



INPUT I;
INIT_INPUT (&I);


SDL_Event event;
SDL_Surface *screen , *screen1 , *screen2 ;
SDL_Surface *j , *p;  
SDL_Rect positionj,positionp ;

Mix_Music * m;
 

if (SDL_Init (SDL_INIT_VIDEO) == -1) {
printf ("Can't init SDL: %s\n", SDL_GetError ());
return EXIT_FAILURE;
}
screen = SDL_SetVideoMode (SCREEN_W, SCREEN_H, 32,
SDL_HWSURFACE | SDL_DOUBLEBUF);



/****************/


if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
      printf("%s", Mix_GetError());
  }
   
   m=Mix_LoadMUS("Dark.mp3");
   Mix_PlayMusic(m, -1); 


/*****************************/

init_background ( &b );
afficher_background (screen , b );
SDL_Flip (screen);
int continuer = 0;
SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY,
SDL_DEFAULT_REPEAT_INTERVAL);
while (!continuer) {
while (SDL_PollEvent (&event)){
switch (event.type) {
case SDL_QUIT:
continuer = 1;
break;
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_LEFT:
I.left = 1 ;
scrolling_left(&b, 10, screen, I);

break;
case SDLK_RIGHT:
I.right = 1;
scrolling_right(&b, 10, screen, I);

break;
/**************************/
 case SDLK_d:
                    I.right1 = 1;
    scrolling_right1(&b, 10, screen, I);

                
                    
                    break;
case SDLK_q:
                    I.left1 = 1;
scrolling_left1(&b, 10, screen, I);

                    
                    break; 
/**************************/
}
break;
}
}
afficher_background (screen, b);
SDL_Flip (screen);
}
SDL_FreeSurface(screen);
SDL_FreeSurface(b.bg);

}
