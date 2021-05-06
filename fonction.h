#ifndef FONCTION_H_INCLUDED 
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#define SCREEN_W 1300
#define SCREEN_H 500


/**
 * @struct INPUT  
 * @brief struct for INPUT 
 */ 

typedef struct 
{
int right, left , right1 , left1 ;
} 
INPUT;  

/**
 * @struct background   
 * @brief struct for background 
 */ 

typedef struct 
{
SDL_Surface *bg;  /*!< Surface1*/

SDL_Rect Posbg;  /*!< Rectangle*/
SDL_Rect Posbg2;

SDL_Rect positioncamera1; /*!< Rectangle1*/
SDL_Rect positioncamera2; /*!< Rectangle2*/
} 
background ;

/*********************/

void INIT_INPUT (INPUT *I);
void init_background (background *b);
void afficher_background (SDL_Surface *screen , background b );
void scrolling_left(background *b, int avancement, SDL_Surface *screen, INPUT I );
void scrolling_left1(background *b, int avancement, SDL_Surface *screen, INPUT I );
void scrolling_right(background *b, int avancement, SDL_Surface *screen, INPUT I );
void scrolling_right1(background *b, int avancement, SDL_Surface *screen, INPUT I );

#endif // FONCTION_H_INCLUDED
