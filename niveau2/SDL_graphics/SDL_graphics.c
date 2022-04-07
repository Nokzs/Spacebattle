#include "SDL_graphics.h"
#include "../sdl2/sdl2-light.h"


void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->skin_ship);
    clean_texture(textures->skin_ennemy);
    clean_texture(textures->missile);
}


void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
    
    textures->skin_ship = load_image("ressources/spaceship.bmp",renderer);

    textures->skin_ennemy = load_image("ressources/enemy.bmp",renderer);

    textures->missile = load_image("ressources/missile.bmp", renderer);
}
void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}
void apply_sprite(SDL_Renderer* renderer, SDL_Texture* texture, sprite_t* sprite){
    if(sprite->is_visible==1){
        SDL_Rect dst = {0, 0, 0, 0};
    
        SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
        dst.x = sprite->x; dst.y=sprite->y;
        SDL_RenderCopy(renderer, texture, NULL, &dst);
    }
}