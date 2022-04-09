#include "SDL_data.h"
#include "../struct/struct.h"
#include "../constantes/constantes.h"cd


void test_init_sprite_param(sprite_t *sprite, int x, int y, int w, int h, int v){
    init_sprite(sprite,x,y,w,h,v);
    print_sprite(sprite);
}
void test_init_sprite(){
    int i;
    sprite_t sprite;
    for(i=0;i<20;i++){
        test_init_sprite_param(&sprite,i,i,i,i,i);
}
}
void test_ship_screen_limit(){
    sprite_t sprite;
    sprite.x=-15;
    printf("x=%d, ",sprite.x);
    left_limit(&sprite.x);
    printf("gauche x=%d \n",sprite.x);
    sprite.x=SCREEN_WIDTH;
    printf("x=%d, ",sprite.x);
    right_limit(&sprite.x);
    printf("droite x=%d \n",sprite.x);
}

void test_vertical_limit_param(sprite_t* sprite){
    printf("y=%d, ",sprite->y);
    bottom_limit(sprite);
    printf("y=%d \n",sprite->y);
}
void test_vertical_limit(){
    sprite_t sprite;
    for(int i=SCREEN_HEIGHT-SHIP_SIZE;i<SCREEN_HEIGHT;i++){
        sprite.y=i;
        printf("%d ",sprite.y);
        test_vertical_limit_param(&sprite);
    }
}
int WinMain( int argc, char* args[] ){
    test_init_sprite();
    test_ship_screen_limit();
    test_vertical_limit();
}
