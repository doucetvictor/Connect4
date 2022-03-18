/*
** EPITECH PROJECT, 2022
** connect4
** File description:
** input.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int get_player_choice(char c)
{
    char *line = 0;
    ssize_t line_len = 0;
    size_t len = 0;
    int column = -1;

    do {
        my_printf("Player %c, where do you want to play: ", c);
        line_len = getline(&line, &len, stdin);
        if (line_len >= 0) {
            line[line_len - 1] = '\0';
        } else {
            free(line);
            return -1;
        }
        if (line_len > 1 && my_str_isnum(line)) {
            column = my_getnbr(line);
        }
    } while (column < 0);
    free(line);
    return column;
}
