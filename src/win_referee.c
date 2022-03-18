/*
** EPITECH PROJECT, 2022
** connect4
** File description:
** win_referee.c
*/

#include "connect.h"

void win_diag_referee_top(game_t *game, int x, int y)
{
    for (int i = 0; i < 4; i++) {
        game->map[y + i][x - i] = game->referee;
    }
}

void win_diag_referee_bottom(game_t *game, int x, int y)
{
    for (int i = 0; i < 4; i++) {
        game->map[y - i][x - i] = game->referee;
    }
}

void win_col_referee(game_t *game, int x, int y)
{
    for (int i = 0; i < 4; i++) {
        game->map[y - i][x] = game->referee;
    }
}

void win_row_referee(game_t *game, int x, int y)
{
    for (int i = 0; i < 4; i++) {
        game->map[y][x - i] = game->referee;
    }
}
