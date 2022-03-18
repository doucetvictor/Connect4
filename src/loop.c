/*
** EPITECH PROJECT, 2022
** duostumper2
** File description:
** Game loop
*/

#include "connect.h"

static void place_input(game_t *game, char avatar, int row)
{
    int out = 0;

    for (int i = game->height; i > 0 && out == 0; i--) {
        if (game->map[i - 1][row - 1] == '.') {
            game->map[i - 1][row - 1] = avatar;
            out = 1;
        }
    }
}

void game_loop(game_t *game)
{
    int out = 0;
    int input = 0;

    while (!out) {
        input = get_player_choice(game->avatar1, game);
        if (input == -1) {
            return;
        }
        place_input(game, game->avatar1, input);
        board_display(game->map);
        input = get_player_choice(game->avatar2, game);
        if (input == -1) {
            return;
        }
        place_input(game, game->avatar2, input);
        board_display(game->map);
    }
}
