/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** battle2.c
*/

#include "../include/my.h"

char *int_to_string(int nb)
{
    int pow = 1;
    int nbcpy = nb;
    char *buffer = malloc(sizeof(char) * 4);
    int i = 0;
    while (nbcpy > 9) {
        pow = pow * 10;
        nbcpy = nbcpy / 10;
    }
    while (nb > 9) {
        buffer[i] = nb / pow + 48;
        nb = nb % pow;
        pow = pow / 10;
        i++;
    }
    buffer[i] = nb + 48;
    buffer[i + 1] = '\0';
    return (buffer);
}

int test_heal(struct combat *combat, game_content_t *game, int life_char)
{
    sfEvent event;

    if (event.type == sfEvtMouseButtonPressed &&
    sfMouse_getPositionRenderWindow(game->game_w).x >= 550
    && sfMouse_getPositionRenderWindow(game->game_w).x <= 740
    && sfMouse_getPositionRenderWindow(game->game_w).y >= 600
    && sfMouse_getPositionRenderWindow(game->game_w).y <= 640
    && combat->wolf_turn != '1') {
        sfClock_restart(combat->time);
        sfText_setString(combat->disp, "You gain 3 HP"); 
        combat->wolf_turn = '1';
        if (life_char >= 13)
            return (15);
        return (life_char + 3);
    }
    return (life_char);
}

int window_event(struct combat *combat, int life_wolf, game_content_t *game, int life_char)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(game->game_w, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->game_w);
        if (event.type == sfEvtMouseButtonPressed &&
        sfMouse_getPositionRenderWindow(game->game_w).x >= 100
        && sfMouse_getPositionRenderWindow(game->game_w).x <= 350
        && sfMouse_getPositionRenderWindow(game->game_w).y >= 600
        && sfMouse_getPositionRenderWindow(game->game_w).y <= 640
        && combat->wolf_turn != '1') {
            sfClock_restart(combat->time);
            sfText_setString(combat->disp, "Hit !"); 
            combat->wolf_turn = '1';
            srand(time(0));
            int life_retired = rand() % 5 + 1;
            if (life_retired > life_wolf)
                life_wolf = life_retired;
            return (life_wolf - life_retired);
        }
        test_run(combat, event, game);
    }
    return (life_wolf);
}

void draw_sprite(struct combat *combat, game_content_t *game)
{
    sfRenderWindow_drawSprite(game->game_w, combat->bg, NULL);
    sfRenderWindow_drawSprite(game->game_w, combat->wolf, NULL);
    sfRenderWindow_drawText(game->game_w, combat->life_char, NULL);
    sfRenderWindow_drawText(game->game_w, combat->life_wolf, NULL);
    sfRenderWindow_drawText(game->game_w, combat->disp, NULL);
    sfRenderWindow_drawText(game->game_w, combat->max_life_char, NULL);
    sfRenderWindow_drawText(game->game_w, combat->max_life_wolf, NULL);
    sfRenderWindow_display(game->game_w);
}

void set_scale_pos(struct combat *combat, game_content_t *game)
{
    sfSprite_setScale(combat->bg, (sfVector2f){1, 0.67});
    sfSprite_setPosition(combat->bg, (sfVector2f){0, 0});
    sfSprite_setScale(combat->wolf, (sfVector2f){3, 3});
    sfSprite_setPosition(combat->wolf, (sfVector2f){900, 100});
}

void print_text(struct combat *combat, int life_wolf,
int life_char, game_content_t *game)
{
    sfFont *font = sfFont_createFromFile("img/Pokemon_GB.ttf");
    combat->disp = sfText_create();
    if (life_wolf == 15)
        sfText_setString(combat->disp, "A wild wolf appeard");  
    if (sfTime_asSeconds(sfClock_getElapsedTime(combat->time)) >= 3)
        sfText_setString(combat->disp, "Attack      Heal       Run");
    sfText_setFont(combat->disp, font);
    sfText_setCharacterSize(combat->disp, 40);
    sfText_setColor(combat->disp, (sfColor) sfBlack);
    sfText_setPosition(combat->disp, (sfVector2f){100, 600});
}