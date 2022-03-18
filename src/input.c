/*
** EPITECH PROJECT, 2022
** connect4
** File description:
** input.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "connect.h"
#include "my.h"

static int check_input(char *input, game_t *game)
{
    int size = my_strlen(input);
    int number = 0;

    if (size == 0 || !my_is_number(input)) {
        return (0);
    }
    number = my_getnbr(input);
    if (number < 1 || number > game->width) {
        return (0);
    }
    if (game->map[0][number - 1] != '.') {
        return (0);
    }
    return number;
}

int get_player_choice(char c, game_t *game)
{
    char *line = 0;
    ssize_t line_len = 0;
    size_t len = 0;
    int out = 0;

    while (!out) {
        my_printf("Player %c, where do you want to play: ", c);
        line_len = getline(&line, &len, stdin);
        if (line_len >= 0) {
            line[line_len - 1] = '\0';
        } else {
            free(line);
            return -1;
        }
        out = check_input(line, game);
    }
    free(line);
    return (out);
}
