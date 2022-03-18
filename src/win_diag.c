/*
** EPITECH PROJECT, 2022
** connect4
** File description:
** win_diag.c
*/

#include "connect.h"

static int check_diag_top(game_t *game, char avatar, int x, int y)
{
    char c = 0;
    int j = 0;

    while (y > 0 && game->map[x + 1]) {
        --y;
        ++x;
    }
    for (int i = 0; x - i >= 0 && (c = game->map[x - i][y + i]); i++) {
        j = (c == avatar ? j + 1 : 0);
        if (j == 4) {
            win_diag_referee_top(game, y + i, x - i);
            return 1;
        }
    }
    return 0;
}

static int check_diag_bottom(game_t *game, char avatar, int x, int y)
{
    char c = 0;
    int j = 0;

    while (x > 0 && y > 0) {
        --x;
        --y;
    }
    for (int i = 0; game->map[x + i] && (c = game->map[x + i][y + i]); i++) {
        j = (c == avatar ? j + 1 : 0);
        if (j == 4) {
            win_diag_referee_bottom(game, y + i, x + i);
            return 1;
        }
    }
    return 0;
}

int check_diag(game_t *game, char avatar, int x, int y)
{
    int diag_top = check_diag_top(game, avatar, x, y);
    int diag_bottom = check_diag_bottom(game, avatar, x, y);

    return diag_top || diag_bottom;
}
