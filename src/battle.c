/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** battle.c
*/

#include "../include/my.h"

void test_run(struct combat *combat, sfEvent event, game_content_t *game)
{
    if (event.type == sfEvtMouseButtonPressed &&
    sfMouse_getPositionRenderWindow(game->game_w).x >= 1000
    && sfMouse_getPositionRenderWindow(game->game_w).x <= 1150
    && sfMouse_getPositionRenderWindow(game->game_w).y >= 600
    && sfMouse_getPositionRenderWindow(game->game_w).y <= 640
    && combat->wolf_turn != '1')
        combat->char_life = 0;
}

void battle_loop(struct combat *combat, game_content_t *game)
{
    set_text(combat, game, 0);
    set_scale_pos(combat, game);
    draw_sprite(combat, game);
}

sfSprite *create_sprite(char *filepath)
{
    struct set_texture img;
    img.texture = sfTexture_createFromFile(filepath, NULL);
    img.sprite = sfSprite_create();
    sfSprite_setTexture(img.sprite, img.texture, sfTrue);
    return (img.sprite);
}

void battle(game_content_t *game)
{
    struct combat *combat = malloc(sizeof(struct combat));
    combat->time = sfClock_create();
    combat->bg = create_sprite("img/combat_pokemon.png");
    sfSprite *wolf = create_sprite("img/wolf.png");
    combat->wolf = wolf;
    print_life_char(combat);
    print_life_wolf(combat);
    combat->life_wolf = sfText_create();
    combat->char_life = 2;
    while (combat->char_life != 0)
        battle_loop(combat, game);
    sfSprite_setPosition(game->bg.bg_sprite, (sfVector2f){-3050, -1590});
    set_text(combat, game, 1);
}