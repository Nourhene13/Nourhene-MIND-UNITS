/** 
* @file fonction.c
 */
#include "fonction.h"
#include<stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#define SCREEN_W 1300
#define SCREEN_H 500


/**

 * @brief To initialize the input I 
 * @param I INPUT
 * @return Nothing
 */

void INIT_INPUT (INPUT *I)
{
I->right = 1 ; 
I->right1 = 1 ; 
I->left = 1;
I->left1 = 1; 
}

/**

 * @brief To initialize the background b .
 * @param b the background
 * @return Nothing
 */

void init_background(background *b )
{
 

///initialisation position background1
b->Posbg.x=0;
b->Posbg.y=0;
b->Posbg.w=0;
b->Posbg.h=0;

///initialisation position camera1
b->positioncamera1.x=0;
b->positioncamera1.y=0;
b->positioncamera1.w=650 ; 
b->positioncamera1.h=(SCREEN_H) ;  

///initialisation position background2
b->Posbg2.x=650;
b->Posbg2.y=0;
b->Posbg2.w=0;
b->Posbg2.h=0;

///initialisation position camera2
b->positioncamera2.x=0;
b->positioncamera2.y=0 ;
b->positioncamera2.w=650; 
b->positioncamera2.h=(SCREEN_H);



b->bg=IMG_Load("background.png"); 


}

/**

 * @brief To show the background b .
 * @param b the background
 * @param screen 
 * @return Nothing
 */

void afficher_background (SDL_Surface *screen , background b )
{

SDL_BlitSurface (b.bg , &b.positioncamera1 , screen , &b.Posbg);
SDL_BlitSurface (b.bg , &b.positioncamera2 , screen, &b.Posbg2  );
}

/**

 * @brief To scroll the background 1 b to the left .
 * @param b the background
 * @param INPUT I 
 * @param avancement
 * @param screen 
 * @return Nothing
 */


void scrolling_left(background *b, int avancement, SDL_Surface *screen, INPUT I)
{
SDL_Rect positionj , positionp;

    if (I.left == 1)
    {
        if (b->positioncamera1.x > 0) 
        {
            b->positioncamera1.x -= avancement;
            positionj.x -= avancement;
            
        }
    }


   
}

/**

 * @brief To scroll the background 2 b to the left .
 * @param b the background
 * @param INPUT I 
 * @param avancement
 * @param screen 
 * @return Nothing
 */


void scrolling_left1(background *b, int avancement, SDL_Surface *screen, INPUT I)
{
SDL_Rect positionj , positionp;

 if (I.left1 == 1)
    {
        if (b->positioncamera2.x > 0 )
        {
           
 b->positioncamera2.x -= avancement;
            positionj.x -= avancement; }

            
        
    }
   
}


/**

 * @brief To scroll the background 1 b to the right .
 * @param b the background
 * @param INPUT I 
 * @param avancement
 * @param screen 
 * @return Nothing
 */

void scrolling_right(background *b, int avancement, SDL_Surface *screen, INPUT I )
{

SDL_Rect positionj , positionp;

    if (I.right == 1 )
    {
        if (b->positioncamera1.w < 5280 ) 
        {
            b->positioncamera1.x += avancement;
            positionj.x += avancement;
           
        }
    }


}

/**

 * @brief To scroll the background 2 b to the right .
 * @param b the background
 * @param INPUT I 
 * @param avancement
 * @param screen 
 * @return Nothing
 */

void scrolling_right1(background *b, int avancement, SDL_Surface *screen, INPUT I )
{

SDL_Rect positionj , positionp;

   

if (I.right1 == 1 )
    {
        if (b->positioncamera2.w < 5280 ) 
        {
            b->positioncamera2.x += avancement;
            positionj.x += avancement;
           
        }
    }
    
}


