/*
** EPITECH PROJECT, 2018
** basic_functions.c
** File description:
** basic functions
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0')) {
        i = i + 1;
    }
    return (s1[i] - s2[i]);
}

void wrt_error(char *str)
{
    write(2, str, my_strlen(str));
}

void move_main_char(game_content_t *game, char direction)
{
    if (direction == 'u') {
        if (check_up(game) == 0)
            move_up(game);
    }
    if (direction == 'd') {
        if (check_down(game) == 0)
            move_down(game);
    }
    if (direction == 'l') {
        if (check_left(game) == 0)
            move_left(game);
    }
    if (direction == 'r') {
        if (check_right(game) == 0)
            move_right(game);
    }
}
