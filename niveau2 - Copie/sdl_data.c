/**
 * \file SDL_data.c
 * \brief Constantes du jeu
 * \author CHAPUSOT Alexis et ANDRE Jeffrey
 * \version 1.0
 * \date 7 AVRIL 2022
 */


#include "SDL_data.h"
#include "sdl2-light.h"


void init_data(world_t * world){
    init_sprite(&(world->ship), SCREEN_WIDTH/2-SHIP_SIZE/2, SCREEN_HEIGHT-3*SHIP_SIZE/2, SHIP_SIZE, SHIP_SIZE, 0);
    print_sprite(&(world->ship));
    init_sprite(&(world->ennemi), SCREEN_WIDTH/2-SHIP_SIZE/2,SHIP_SIZE,SHIP_SIZE,SHIP_SIZE,ENEMY_SPEED);
    init_sprite(&(world->missile),SCREEN_WIDTH/2-MISSILE_SIZE/2, SCREEN_HEIGHT-3*SHIP_SIZE/2+MISSILE_SIZE-SHIP_SIZE/2, SHIP_SIZE, SHIP_SIZE, MISSILE_SPEED);
    set_invisible(&(world->missile));
    //on n'est pas à la fin du jeu
    world->gameover = 0;    
}

void print_sprite(sprite_t* sprite){
    printf("X: %d\ny: %d\nh: %d\nw: %d\nv: %d\n",sprite->x,sprite->y,sprite->h,sprite->w,sprite->v);
}

void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}

int is_game_over(world_t *world){
    return world->gameover;
}

void update_data(world_t *world){
    world->ennemi.y+= world->ennemi.v;
    if(world->missile.is_visible){  
    world->missile.y-= MISSILE_SPEED;   /*!< Si le missile est visible, c'est qu'il doit se déplacer */
    }
    else{
         world->missile.x= world->ship.x+SHIP_SIZE/2-MISSILE_SIZE/2; /*!< sinon il doit être placer au dessus du vaisseau*/
    }
}

void set_visible(sprite_t* sprite){
    sprite->is_visible=1;
}

void set_invisible(sprite_t* sprite){
    sprite->is_visible=0;
}


void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->gameover = 1;
        }
       
         //si une touche est appuyée
         if(event->type == SDL_KEYDOWN){
             //si la touche appuyée est 'D'
             if(event->key.keysym.sym == SDLK_d){
                 printf("La touche D est appuyée\n");
                 world->ship.x+=1;
              }
              else if (event->key.keysym.sym == SDLK_RIGHT)
              {
                  world->ship.x+=10;
              }
              else if (event->key.keysym.sym == SDLK_LEFT)
              {
                  world->ship.x-=10;
              }
              if(event->key.keysym.sym == SDLK_ESCAPE){
                 world->gameover = 1;
              }
              if(event->key.keysym.sym == SDLK_SPACE){
                  set_visible(&(world->missile));
              }
              
              
         }
    }
}

void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v){
    sprite->x=x;
    sprite->y=y;
    sprite->w=w;
    sprite->h=h;
    sprite->v=v;
    sprite->is_visible=1;
}

