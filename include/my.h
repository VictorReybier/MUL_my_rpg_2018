/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** 
*/

#ifndef MY_H
#define MY_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/Graphics/Export.h>
#include <stddef.h>
#include <time.h>

struct set_texture {
    sfTexture *texture;
    sfSprite *sprite;
};

struct combat {
    sfSprite *bg;
    sfSprite *wolf;
    sfRenderWindow *window;
    sfFont *font;
    sfText *life_char;
    sfText *life_wolf;
    sfText *disp;
    sfText *max_life_char;
    sfText *max_life_wolf;
    char wolf_turn;
    sfClock *time;
    int char_life;
};

typedef struct background
{
    sfTexture *bg_text;
    sfSprite *bg_sprite;
    sfVideoMode video_mode;
    sfVector2f bg_size;
}bg_t;
typedef struct map_s
{
    sfIntRect left_three;
    sfIntRect bottom_three;
    sfIntRect top_three;
    sfIntRect middle_three;
    sfIntRect right_three;
    sfIntRect under_grass;
    sfIntRect water;
    sfIntRect farmer;
    sfIntRect worker;
}map_t;
typedef struct pause
{
    sfVector2f pause_scale;
    sfIntRect hitbox_resume;
    sfIntRect hitbox_menu;
    sfIntRect hitbox_quit;
    sfTexture *pause_text;
    sfSprite *pause_sprite;
}pause_t;
typedef struct menu
{
    sfIntRect hitbox_play;
    sfIntRect hitbox_quit;
    sfSprite *menu_sprite;
    sfTexture *menu_text;
    sfVector2f menu_scale;
    sfMusic *music;
}menu_t;

typedef struct effects
{
    sfSprite *boom;
    sfTexture *boom_txt;
    sfIntRect boom_spr;
}effect_t;

typedef struct pers
{
    sfTexture *char_text;
    sfSprite *char_sprite;
    sfClock *walk_c;
    int x;
    int y;
    sfTime walk_t;
    float walk_s;
    sfIntRect char_size;
    char *name;
    char *attack;
    int hp;
    int mana;
    int strenght;
    int agility;
}pers_t;

typedef struct inventory
{
    sfTexture *inv_text;
    sfSprite *inv_sprite;
    sfTexture *sinv_text;
    sfSprite *sinv_sprite;
    sfVector2f inv_size;
    sfIntRect inv_rect;
    int hp_potions;
    int mana_potions;
    int weight;
    int count;
}inventory_t;

typedef struct ennemy
{
    char *name;
    char *attack;
    int hp;
    int strength;
}ennemy_t;

typedef struct quest
{
    sfTexture *quest_text;
    sfSprite *quest_sprite;
    sfVector2f quest_size;
    sfVector2f quest_pos;
    sfText *text_quest;
    sfFont *font_quest;
    sfVector2f text_pos;
}quest_t;

typedef struct game
{
    sfRenderWindow *game_w;
    sfVideoMode video_mode;
    sfSprite *background;
    sfTexture *bck_txt;
    sfEvent event;
    bg_t bg;
    menu_t menu;
    effect_t effect;
    pers_t pers;
    quest_t quest;
    pause_t pause;
    map_t map;
    inventory_t inventory;
    ennemy_t ennemy;
    sfMusic *music;
}game_content_t;

int check_for_errors(int ac, char **av);
void my_menu(game_content_t *game);
int my_strlen(char *str);
int my_strcmp(char const *s1, char const *s2);
void my_putstr(char *str);
void wrt_error(char *str);
void my_action(game_content_t *game);
void my_hitbox(game_content_t *game, sfEvent event);
void my_display_menu(game_content_t *game);
void load_game(game_content_t *game);
void my_display_background(game_content_t *game);
void my_game(game_content_t *game);
void my_hitboxes(game_content_t *game);
void my_pause(game_content_t *game);
void animated_char(game_content_t *game, sfEvent move);
sfIntRect move_rect(sfIntRect rect, int offset, int max_value);
void my_hitboxes_p(game_content_t *game);
int my_event(game_content_t *game);
void load_char_info(game_content_t *game);
void move_main_char(game_content_t *game, char direction);
void move_horizontal(game_content_t *game, char dir);
void move_vertical(game_content_t *game, char dir);
void move_up(game_content_t *game);
void move_down(game_content_t *game);
void move_left(game_content_t *game);
void move_right(game_content_t *game);
int open_inventory(inventory_t inventory, game_content_t *game);
int check_left(game_content_t *game);
int cant_run_here3(game_content_t *game);
int cant_run_here2(game_content_t *game);
int cant_run_here(game_content_t *game);
void test_run(struct combat *combat, sfEvent event, game_content_t *game);
void battle_loop(struct combat *combat, game_content_t *game);
sfSprite *create_sprite(char *filepath);
void battle(game_content_t *game);
char *int_to_string(int nb);
int window_event(struct combat *combat, int life_wolf, game_content_t *game, int life_char);
void draw_sprite(struct combat *combat, game_content_t *game);
void set_scale_pos(struct combat *combat, game_content_t *game);
void print_text(struct combat *combat, int life_wolf, int life_char, game_content_t *game);
void print_life_wolf(struct combat *combat);
void print_life_char(struct combat *combat);
int wolf_turn(struct combat *combat, int life_char);
void text_wolf(struct combat *combat, int life_wolf);
int set_text(struct combat *combat, game_content_t *game, int status);
void find_battle(game_content_t *game);
void my_quest(game_content_t *game, int x, int y);
int check_up(game_content_t *game);
int check_right(game_content_t *game);
int check_down(game_content_t *game);
int test_heal(struct combat *combat, game_content_t *game, int life_char);

#endif