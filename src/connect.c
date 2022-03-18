/*
** EPITECH PROJECT, 2022
** duostumper2
** File description:
** Connect4
*/

#include <stdlib.h>
#include "connect.h"
#include "my.h"

static void init_map(game_t *game)
{
    char **map = malloc(sizeof(char *) * (game->height + 1));
    char *line = NULL;

    if (map == NULL) {
        exit(84);
    }
    for (int i = 0; i < game->height; i++) {
        line = malloc(sizeof(char) * (game->width + 1));
        if (line == NULL) {
            exit(84);
        }
        my_strfill(line, game->width + 1, '.');
        map[i] = line;
    }
    map[game->height] = NULL;
    game->map = map;
}

static void init_game(game_t *game)
{
    game->map = NULL;
    game->width = 7;
    game->height = 6;
    game->avatar1 = 'X';
    game->avatar2 = 'O';
    game->referee = '#';
}

static int error_handling(game_t *game)
{
    int slots = game->width * game->height;
    
    if (game->avatar1 == game->avatar2) {
        my_fprintf(2, "Error: Same avatar for both players\n");
        return (0);
    } else if (slots < 20) {
        my_fprintf(2, "Error: Too small grid\n");
        return (0);
    }
    if (game->width < 1 || game->width > 80) {
        my_fprintf(2, "Error: Width must be between 1 and 80\n");
        return (0);
    } else if (game->height < 1 || game->height > 16) {
        my_fprintf(2, "Error: Height must be between 1 and 16\n");
        return (0);
    }
    return (1);
}

int connect(int argc, char **argv)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL) {
        return (84);
    }
    init_game(game);
    if (!get_options(argc, argv, game) || !error_handling(game)) {
        return (84);
    }
    init_map(game);
    game_loop(game);
    my_free_arrays(1, game->map);
    free(game);
    return (0);
}
