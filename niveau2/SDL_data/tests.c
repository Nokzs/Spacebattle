#include "SDL_data.h"
#include "../struct/struct.h"


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
int WinMain( int argc, char* args[] ){
    test_init_sprite();
    return 1;
}

