/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu
*/

#include "my.h"

void my_hitboxes(game_content_t *game)
{
    sfVideoMode mode = {1280, 769, 32};

    game->game_w = sfRenderWindow_create(mode, "RPG", sfDefaultStyle, NULL);
    game->menu.hitbox_play.left = 0;
    game->menu.hitbox_play.top = 145;
    game->menu.hitbox_play.width = 1280;
    game->menu.hitbox_play.height = 380;

    game->menu.hitbox_quit.left = 0;
    game->menu.hitbox_quit.width = 1280;
    game->menu.hitbox_quit.top = 383;
    game->menu.hitbox_quit.height = 560;
    my_menu(game);
}

void my_menu(game_content_t *game)
{
    game->pers.char_size.top = 0;
    game->pers.char_size.left = 0;
    game->pers.char_size.width = 45;
    game->pers.char_size.height = 60;

    game->menu.menu_scale.x = 1.25;
    game->menu.menu_scale.y = 1;
    game->menu.music = sfMusic_createFromFile("img/menu.ogg");
    sfMusic_setLoop(game->menu.music, 1);
    sfMusic_setVolume(game->menu.music, 10);
    sfMusic_play(game->menu.music);
    game->menu.menu_text = sfTexture_createFromFile("img/new_menu_rpg.png", NULL);
    game->menu.menu_sprite = sfSprite_create();
    sfSprite_setTexture(game->menu.menu_sprite, game->menu.menu_text, sfTrue);
    sfSprite_setScale(game->menu.menu_sprite, game->menu.menu_scale);
    my_action(game);    
}

void my_action(game_content_t *game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->game_w)) {
        while (sfRenderWindow_pollEvent(game->game_w, &event)) {
            switch (event.type) {
                case sfEvtClosed:
                    sfRenderWindow_close(game->game_w);
                    break;
                case sfEvtMouseButtonPressed:
                    my_hitbox(game, event);
                    break;
            }
        }
        my_display_menu(game);
    }
}

void my_hitbox(game_content_t *game, sfEvent event)
{
    if (event.mouseButton.y > game->menu.hitbox_play.top &&
        event.mouseButton.y < game->menu.hitbox_play.height &&
        event.mouseButton.x > game->menu.hitbox_play.left &&
        event.mouseButton.x < game->menu.hitbox_play.width) {
        sfMusic_destroy(game->menu.music);
        sfRenderWindow_destroy(game->game_w);
        load_game(game);
    }
    else if (event.mouseButton.y > game->menu.hitbox_quit.top &&
            event.mouseButton.y < game->menu.hitbox_quit.height &&
            event.mouseButton.x > game->menu.hitbox_quit.left &&
            event.mouseButton.x < game->menu.hitbox_quit.width) {
        sfMusic_destroy(game->menu.music);
        sfRenderWindow_destroy(game->game_w);
        exit(0);
    }
}

void my_display_menu(game_content_t *game)
{
    sfRenderWindow_drawSprite(game->game_w, game->menu.menu_sprite, NULL);
    sfRenderWindow_display(game->game_w);
}