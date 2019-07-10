/*
** EPITECH PROJECT, 2019
** hitboxe_map.c
** File description:
** hitboxe_map
*/

#include "my.h"

int check_right(game_content_t *game)
{
    int x = sfSprite_getPosition(game->bg.bg_sprite).x - 5;
    int y = sfSprite_getPosition(game->bg.bg_sprite).y + 20;
    if (x > -3722 && x < -26 && y < 442 && y > 106 || 
        x > -2042 && x < -1490 && y < 166 && y > -1586 ||
        x > -4166 && x < -3638 && y < 94 && y > -1586 ||
        x > -3662 && x < -2810 && y < -1562 && y > -2342 ||
        x > -2258 && x < -1526 && y < -1610 && y > -1946 ||
        x > -796 && x < -667 && y < 114 && y > 54 ||
        x > -1051 && x < -929 && y < 114 && y > 54) {
        return (1);
    }
    else
        return (0);
}

int check_left(game_content_t *game)
{
    int x = sfSprite_getPosition(game->bg.bg_sprite).x + 5;
    int y = sfSprite_getPosition(game->bg.bg_sprite).y + 20;
    
    if (x > 113 && x < 612 && y < 404 && y > -2412 ||
        x > -2258 && x < -1526 && y < -1610 && y > -1946 ||
        x > -2042 && x < -1490 && y < 166 && y > -1586 ||
        x > -796 && x < -667 && y < 114 && y > 54 ||
        x > -1051 && x < -929 && y < 114 && y > 54)
        return (1);
    else
        return (0);
}

int check_up(game_content_t *game)
{
    int x = sfSprite_getPosition(game->bg.bg_sprite).x + 20;
    int y = sfSprite_getPosition(game->bg.bg_sprite).y + 30;

    if (x > -3722 && x < -26 && y < 442 && y > 106 || 
        x > -2042 && x < -1490 && y < 106 && y > -1586 ||
        x > -4166 && x < -3638 && y < 94 && y > -1586 ||
        x > -3662 && x < -2810 && y < -1562 && y > -2342 ||
        x > -2258 && x < -1526 && y < -1610 && y > -1946 ||
        x > -796 && x < -667 && y < 114 && y > 54 ||
        x > -1051 && x < -929 && y < 114 && y > 54 ||
        x > -40 && x < 152 && y < 500 && y > 402)
        return (1);
    else
        return (0);
}

int check_down(game_content_t *game)
{
    int x = sfSprite_getPosition(game->bg.bg_sprite).x + 20;
    int y = sfSprite_getPosition(game->bg.bg_sprite).y - 20;

    if (x > -2848 && x < 164 && y < -2345 && y > -2609 ||
        x > -2248 && x < -1552 && y < -1637 && y > -1949 ||
        x > -3616 && x < -2836 && y < -1568 && y > -2936)
        return (1);
    else
        return (0);
}