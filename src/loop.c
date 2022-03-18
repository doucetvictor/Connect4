/*
** EPITECH PROJECT, 2022
** duostumper2
** File description:
** Game loop
*/

#include "connect.h"

static int place_input(game_t *game, char avatar, int row)
{
    for (int i = game->height; i > 0; i--) {
        if (game->map[i - 1][row - 1] == '.') {
            game->map[i - 1][row - 1] = avatar;
            return (i - 1);
        }
    }
    return -1;
}

static int player_interaction(game_t *game, char avatar)
{
    int input = get_player_choice(avatar, game);
    int result = 0;

    if (input == -1) {
        return (1);
    }
    result = place_input(game, avatar, input);
    if (result == -1) {
        return (1);
    }
    if (check_win(game, avatar, result, input - 1)) {
        return (1);
    }
    board_display(game->map);
    return (0);
}

void game_loop(game_t *game)
{
    int out = 0;

    while (!out) {
        if (player_interaction(game, game->avatar1)) {
            return;
        }
        if (player_interaction(game, game->avatar2)) {
            return;
        }
    }
}
