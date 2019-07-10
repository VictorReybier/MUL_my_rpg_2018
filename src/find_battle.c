/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** find_battle.c
*/

#include "../include/my.h"

struct tmp {
    sfClock *time;
};

void find_battle(game_content_t *game)
{
    int char_x = sfSprite_getPosition(game->bg.bg_sprite).x;
    int char_y = sfSprite_getPosition(game->bg.bg_sprite).y;

    if (char_x >= -3660 && char_x <= -2100 && char_y >= -1150 && char_y <= 85)
        battle(game);
}