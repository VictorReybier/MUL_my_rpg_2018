/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu
*/

#include "my.h"

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
    if (rect.top >= max_value)
        rect.top = 0;
    else
        rect.top = rect.top + offset;
    return (rect);
}

void animated_char(game_content_t *game, sfEvent move)
{
	game->inventory.inv_rect.top = 673;
	game->inventory.inv_rect.height = 769;
	game->inventory.inv_rect.width = 72;
	game->inventory.inv_rect.left = 0;

    if (move.mouseButton.y > game->inventory.inv_rect.top &&
       	move.mouseButton.y < game->inventory.inv_rect.height &&
     	move.mouseButton.x > game->inventory.inv_rect.left &&
        move.mouseButton.x < game->inventory.inv_rect.width) {
        open_inventory(game->inventory, game);
    	move.mouseButton.y = 0;
    	move.mouseButton.x = 0;
	}
    if (move.type == sfEvtKeyPressed) {
        if (move.key.code == sfKeyUp)
            move_main_char(game, 'u');
        else if (move.key.code == sfKeyDown)
            move_main_char(game, 'd');
        else if (move.key.code == sfKeyLeft)
            move_main_char(game, 'l');
        else if (move.key.code == sfKeyRight)
            move_main_char(game, 'r');
        if (game->pers.walk_s > 0.03) {
            sfClock_restart(game->pers.walk_c);
            game->pers.char_size = move_rect(game->pers.char_size, 27, 81);
        }
    }
    sfRenderWindow_drawSprite(game->game_w, game->pers.char_sprite, NULL);
}

void load_char_info(game_content_t *game)
{
    game->pers.walk_c = sfClock_create();
    game->pers.char_text = sfTexture_createFromFile("img/new_main_char.png", NULL);
    game->pers.char_sprite = sfSprite_create();
    sfSprite_setTexture(game->pers.char_sprite, game->pers.char_text, sfTrue);
    game->pers.char_size.top = 0;
    game->pers.char_size.left = 0;
    game->pers.char_size.width = 27;
    game->pers.char_size.height = 37;
    game->pers.walk_s = sfTime_asSeconds(game->pers.walk_t);
    game->pers.walk_t = sfClock_getElapsedTime(game->pers.walk_c);
    sfSprite_setScale(game->pers.char_sprite, (sfVector2f){2.3, 2.3});
    sfSprite_setScale(game->bg.bg_sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(game->pers.char_sprite, (sfVector2f){640, 384});
}
