/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** handles main char's movements
*/

#include "my.h"

void move_up(game_content_t *game)
{
    static int offset = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->pers.walk_c)) > 70) {
        sfClock_restart(game->pers.walk_c);
        sfSprite_setTextureRect(game->pers.char_sprite, (sfIntRect){50, offset, 25, 35});
        offset = offset + 35;
        if (offset >= 35 * 3)
            offset = 0;
    }
    game->pers.y = 0;
    sfSprite_move(game->bg.bg_sprite, (sfVector2f){0, 12});
}

void move_down(game_content_t *game)
{
    static int offset = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->pers.walk_c)) > 70) {
        sfClock_restart(game->pers.walk_c);
        sfSprite_setTextureRect(game->pers.char_sprite, (sfIntRect){25, offset, 25, 35});
        offset = offset + 35;
        if (offset >= 35 * 3)
            offset = 0;
    }
    sfSprite_move(game->bg.bg_sprite, (sfVector2f){0, -12});
}

void move_left(game_content_t *game)
{
    static int offset = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->pers.walk_c)) > 70) {
        sfClock_restart(game->pers.walk_c);
        sfSprite_setTextureRect(game->pers.char_sprite, (sfIntRect){75, offset, 25, 35});
        offset = offset + 35;
        if (offset >= 35 * 3)
            offset = 0;
    }
    sfSprite_move(game->bg.bg_sprite, (sfVector2f){12, 0});
}

void move_right(game_content_t *game)
{
    static int offset = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->pers.walk_c)) > 70) {
        sfClock_restart(game->pers.walk_c);
        sfSprite_setTextureRect(game->pers.char_sprite, (sfIntRect){0, offset, 25, 35});
        offset = offset + 35;
        if (offset >= 35 * 3)
            offset = 0;
    }
    sfSprite_move(game->bg.bg_sprite, (sfVector2f){-12, 0});
}