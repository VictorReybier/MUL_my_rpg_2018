/*
** EPITECH PROJECT, 2019
** load_game.c
** File description:
** load_game
*/

#include "my.h"

void my_hitboxes_p(game_content_t *game)
{
    game->pause.hitbox_resume.left = 435;
    game->pause.hitbox_resume.height = 232;
    game->pause.hitbox_resume.width = 851;
    game->pause.hitbox_resume.top = 145;

    game->pause.hitbox_menu.left = 520;
    game->pause.hitbox_menu.height = 422;
    game->pause.hitbox_menu.width = 780;
    game->pause.hitbox_menu.top = 336;

    game->pause.hitbox_quit.left = 506;
    game->pause.hitbox_quit.height = 597;
    game->pause.hitbox_quit.top = 500;
    game->pause.hitbox_quit.width = 770;
    my_pause(game);
}

void my_pause(game_content_t *game)
{
    game->pause.pause_text = sfTexture_createFromFile("img/new_resume_rpg.png", NULL);
    game->pause.pause_sprite = sfSprite_create();
    sfSprite_setTexture(game->pause.pause_sprite, game->pause.pause_text, sfTrue);
    my_event(game);
}

int check_hitbox_pause(game_content_t *game, sfEvent event, int i)
{
    if (event.mouseButton.y > game->pause.hitbox_resume.top &&
        event.mouseButton.y < game->pause.hitbox_resume.height &&
        event.mouseButton.x > game->pause.hitbox_resume.left &&
        event.mouseButton.x < game->pause.hitbox_resume.width) {
        i = 1;
        return (i);
    }
    else if (event.mouseButton.y > game->pause.hitbox_menu.top &&
        event.mouseButton.y < game->pause.hitbox_menu.height &&
        event.mouseButton.x > game->pause.hitbox_menu.left &&
        event.mouseButton.x < game->pause.hitbox_menu.width) {
        sfRenderWindow_destroy(game->game_w);
        my_hitboxes(game);
    }
    else if (event.mouseButton.y > game->pause.hitbox_quit.top &&
        event.mouseButton.y < game->pause.hitbox_quit.height &&
        event.mouseButton.x > game->pause.hitbox_quit.left &&
        event.mouseButton.x < game->pause.hitbox_quit.width) {
        sfRenderWindow_destroy(game->game_w);
        sfMusic_destroy(game->music);
    }
}

int my_event(game_content_t *game)
{
    int i = 0;
    sfEvent event;

    while (sfRenderWindow_isOpen(game->game_w)) {
        while (i == 0) {
            while (sfRenderWindow_pollEvent(game->game_w, &event)) {
                switch (event.type) {
                    case sfEvtKeyPressed:
                        if (event.key.code == sfKeyEscape) {
                            i = 1;
                            return (0);
                        }
                        break;
                    case sfEvtMouseButtonPressed:
                        i = check_hitbox_pause(game, event, i);
                        break;
                }
            }
            sfRenderWindow_drawSprite(game->game_w, game->pause.pause_sprite, NULL);
            sfRenderWindow_display(game->game_w);
            if (i == 1)
                return (0);
        }
    }
}