/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** battle3.c
*/

#include "../include/my.h"

void print_life_wolf(struct combat *combat)
{
    sfFont *font = sfFont_createFromFile("img/Pokemon_GB.ttf");
    combat->max_life_wolf = sfText_create();
    sfText_setString(combat->max_life_wolf, "15");
    sfText_setFont(combat->max_life_wolf, font);
    sfText_setCharacterSize(combat->max_life_wolf, 70);
    sfText_setColor(combat->max_life_wolf, (sfColor) sfBlack);
    sfText_setPosition(combat->max_life_wolf, (sfVector2f){470, 100});
}

void print_life_char(struct combat *combat)
{
    sfFont *font = sfFont_createFromFile("img/Pokemon_GB.ttf");
    combat->max_life_char = sfText_create();
    sfText_setString(combat->max_life_char, "15");
    sfText_setFont(combat->max_life_char, font);
    sfText_setCharacterSize(combat->max_life_char, 70);
    sfText_setColor(combat->max_life_char, (sfColor) sfBlack);
    sfText_setPosition(combat->max_life_char, (sfVector2f){1030, 400});
}

int wolf_turn(struct combat *combat, int life_char)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(combat->time)) >= 3) {
        sfText_setString(combat->disp, "Wolf hit you !");
        sfClock_restart(combat->time);
        combat->wolf_turn = '0';
        srand(time(0));
        int life_retired = rand() % 3 + 1;
        if (life_retired > life_char)
            life_char = life_retired;
        return (life_char - life_retired);
    }
    return (life_char);
}

void text_wolf(struct combat *combat, int life_wolf)
{
    sfText_setString(combat->life_wolf, int_to_string(life_wolf));
    sfText_setFont(combat->life_wolf, combat->font);
    sfText_setCharacterSize(combat->life_wolf, 70);
    sfText_setColor(combat->life_wolf, (sfColor) sfBlack);
    sfText_setPosition(combat->life_wolf, (sfVector2f){170, 100});
}

void set_text_next(struct combat *combat, int life_char)
{
    combat->font = sfFont_createFromFile("img/Pokemon_GB.ttf");
    combat->life_char = sfText_create();
    sfText_setString(combat->life_char, int_to_string(life_char));
    sfText_setFont(combat->life_char, combat->font);
    sfText_setCharacterSize(combat->life_char, 70);
    sfText_setColor(combat->life_char, (sfColor) sfBlack);
    sfText_setPosition(combat->life_char, (sfVector2f){750, 400});
}

void test_death(struct combat *combat, int life_char, int life_wolf, game_content_t *game)
{
    if (life_char == 0) {
        sfText_setString(combat->life_char, int_to_string(life_char));
        sfClock_restart(combat->time);
        sfText_setString(combat->disp, "You are dead");
        while (sfTime_asSeconds(sfClock_getElapsedTime(combat->time)) <= 3)
            draw_sprite(combat, game);
        combat->char_life = 0;    
    }
    if (life_wolf == 0) {
        sfText_setString(combat->life_wolf, int_to_string(life_wolf));
        sfClock_restart(combat->time);
        sfText_setString(combat->disp, "You kill him !");
        while (sfTime_asSeconds(sfClock_getElapsedTime(combat->time)) <= 3)
            draw_sprite(combat, game);
        combat->char_life = 0;
        game->inventory.count++;
    }
}

int set_text(struct combat *combat, game_content_t *game, int status)
{
    static int life_char = 15;
    static int life_wolf = 15;
    static int first_call = 0;

    if (status == 1) {
        life_wolf = 15;
        first_call = 0;
        return (0);
    }
    life_wolf = window_event(combat, life_wolf, game, life_char);
    life_char = test_heal(combat, game, life_char);
    if (combat->wolf_turn == '1')
        life_char = wolf_turn(combat, life_char);
    else if (sfTime_asSeconds(sfClock_getElapsedTime(combat->time)) >= 3 ||
    first_call == 0)
        print_text(combat, life_wolf, life_char, game);
    test_death(combat, life_char, life_wolf, game);
    set_text_next(combat, life_char);
    text_wolf(combat, life_wolf);
    first_call++;
}