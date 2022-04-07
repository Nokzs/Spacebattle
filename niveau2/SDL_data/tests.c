#define "SDL_data.h"
#define "../struct/struct.h"
test_init_sprite_param(sprite_t *sprite, int x, int y, int w, int h, int v){
    init_sprite(sprite,x,y,w,h,v);
    print_sprite(sprite);
}
test_init_sprite(){
    int i;
    sprite_t* sprite;
    for(i=0;i<20;i++){
        test_init_sprite_param(sprite,i,i,i,i,i);
    }
}
int main(char* argv[], int argc){
    test_init_sprite();
}

