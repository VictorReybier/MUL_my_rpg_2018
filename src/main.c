/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "my.h"

int check_for_errors(int ac, char **av)
{
    if (ac == 2) {
        if (my_strcmp("-h", av[1]) == 0) {
            wrt_error("USAGE\n\n./my_rpg\n    starts the game.\n");
            return (84);
        }
        else {
           wrt_error("ERROR: game doesnt need argument.\n");
            return (84);
        }
    }
    return (0);
}

int main(int argc, char **argv)
{   
    game_content_t game;

    if (check_for_errors(argc, argv) == 84)
        return (84);
    my_hitboxes(&game);
    battle(&game);
	return (0);
}
