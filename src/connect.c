/*
** EPITECH PROJECT, 2022
** duostumper2
** File description:
** Connect4
*/

#include <stdlib.h>
#include "connect.h"

int connect(int argc, char **argv)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL) {
        return (84);
    }
    if (!get_options(argc, argv, game)) {
        return (84);
    }
    return (0);
}
