/*
** EPITECH PROJECT, 2019
** quest.c
** File description:
** the quest
*/

#include "my.h"

void my_quest(game_content_t *game, int x, int y)
{
	game->quest.quest_size.x = 2.5;
	game->quest.quest_size.y = 1;
	game->quest.quest_pos.x = 100;
	game->quest.quest_pos.y = 570;
	game->quest.text_pos.x = 180;
	game->quest.text_pos.y = 620;
	if (game->inventory.count < 3)
		sfText_setString(game->quest.text_quest, "HELLO YOUNG MAN\nI HEARD YOU ARE LOOKING FOR SOME FIGHT\nTHERE IS SOME WOLFS IN THE SOUTH-EAST.\nGO AND KILL 3 OF THEM.\n");
	else if (game->inventory.count >= 3)
		sfText_setString(game->quest.text_quest, "WELL PLAYED !\n I WISH YOU GOOD LUCK FOR YOUR NEXT ADVENTURES\n");
	sfText_setFont(game->quest.text_quest, game->quest.font_quest);
	sfText_setCharacterSize(game->quest.text_quest, 20);
	sfText_setPosition(game->quest.text_quest, game->quest.text_pos);
	if (x > -864 && x < -684 && y > 0 && y < 48) {
		sfRenderWindow_drawText(game->game_w, game->quest.text_quest, NULL);
		sfSprite_setScale(game->quest.quest_sprite, game->quest.quest_size);
		sfSprite_setPosition(game->quest.quest_sprite, game->quest.quest_pos);
		sfRenderWindow_drawSprite(game->game_w, game->quest.quest_sprite, NULL);
		sfRenderWindow_display(game->game_w);
	}
}