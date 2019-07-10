/*
** EPITECH PROJECT, 2019
** load_game.c
** File description:
** load_game
*/

#include "my.h"

void load_game(game_content_t *game)
{
    game->bg.video_mode.width = 1280; 
    game->bg.video_mode.height = 769; 
    game->bg.video_mode.bitsPerPixel = 32;
    game->inventory.sinv_text = sfTexture_createFromFile("img/bag.png", NULL);
    game->inventory.sinv_sprite = sfSprite_create();
    sfSprite_setPosition(game->inventory.sinv_sprite, (sfVector2f){0, 695});
    sfSprite_setTexture(game->inventory.sinv_sprite, game->inventory.sinv_text, sfTrue);
    game->quest.font_quest = sfFont_createFromFile("img/font.ttf");
    game->quest.text_quest = sfText_create();
    game->quest.quest_text = sfTexture_createFromFile("img/bulle.png", NULL);
    game->quest.quest_sprite = sfSprite_create();
    sfSprite_setTexture(game->quest.quest_sprite, game->quest.quest_text, sfTrue);
    game->game_w = sfRenderWindow_create(game->bg.video_mode, "RPG", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(game->game_w, 60);
    game->bg.bg_text = sfTexture_createFromFile("img/final_map.png", NULL);
    game->bg.bg_sprite = sfSprite_create();
    sfSprite_setTexture(game->bg.bg_sprite, game->bg.bg_text, sfTrue);
    load_char_info(game);
    sfSprite_setTextureRect(game->pers.char_sprite, (sfIntRect){25, 0, 25, 35});
    game->music = sfMusic_createFromFile("img/game.ogg");
    sfMusic_setVolume(game->music, 3);
    sfMusic_play(game->music);
    game->inventory.inv_text = sfTexture_createFromFile("img/inventory_op.png", NULL);
    game->inventory.inv_sprite = sfSprite_create();
    my_game(game);
}

int open_inventory(inventory_t inventory, game_content_t *game)
{
    inventory.inv_size.x = 1;
    inventory.inv_size.y = 1;
    sfSprite_setTexture(game->inventory.inv_sprite, game->inventory.inv_text, sfTrue);
    sfEvent event;

    while (sfRenderWindow_isOpen(game->game_w)) {
    	while (sfRenderWindow_pollEvent(game->game_w, &event)) {
	        sfRenderWindow_drawSprite(game->game_w, inventory.inv_sprite, NULL);
	        sfRenderWindow_display(game->game_w);
	    	switch (event.type) {
	    		case sfEvtMouseButtonPressed:
			        if (event.mouseButton.y > game->inventory.inv_rect.top &&
			       	event.mouseButton.y < game->inventory.inv_rect.height &&
			     	event.mouseButton.x > game->inventory.inv_rect.left &&
			        event.mouseButton.x < game->inventory.inv_rect.width)
			        	return (0);
				}
	    }
	}
}

void my_game(game_content_t *game)
{
    int x = 0;
    int y = 0;
    sfEvent event;

    while (sfRenderWindow_isOpen(game->game_w)) {
        x = sfSprite_getPosition(game->bg.bg_sprite).x + 10;
        y = sfSprite_getPosition(game->bg.bg_sprite).y + 10;
        my_quest(game, x, y);
        while (sfRenderWindow_pollEvent(game->game_w, &event)) {
            switch (event.type) {
                case sfEvtClosed:
                    sfRenderWindow_close(game->game_w);
                    break;
                case sfEvtKeyPressed:
                    if (event.key.code == sfKeyEscape) {
                        my_hitboxes_p(game);
                    }
                    break;
            }
        }
        my_display_background(game);
        find_battle(game);
        animated_char(game, event);
    }
    sfMusic_destroy(game->music);
    sfRenderWindow_destroy(game->game_w);
}

void my_display_background(game_content_t *game)
{
    sfRenderWindow_drawSprite(game->game_w, game->bg.bg_sprite, NULL);
    sfRenderWindow_drawSprite(game->game_w, game->pers.char_sprite, NULL);
    sfRenderWindow_drawSprite(game->game_w, game->inventory.sinv_sprite, NULL);
    sfRenderWindow_display(game->game_w);
}
