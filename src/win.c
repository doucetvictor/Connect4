/*
** EPITECH PROJECT, 2022
** connect4
** File description:
** win.c
*/

#include "connect.h"
#include "my.h"

static int check_tie(game_t *game)
{
    char c = 0;

    for (int i = 0; (c = game->map[0][i]); i++) {
        if (c == '.') {
            return 0;
        }
    }
    board_display(game->map);
    my_putstr("It's a tie, nobody wins.\n");
    return 1;
}

static int check_diag(game_t *game, char avatar, int x, int y)
{
    char c = 0;
    int j = 0;

    while (x > 0 && y > 0) {
        --x;
        --y;
    }
    for (int i = 0; game->map[y + i] && (c = game->map[y + i][x + i]); i++) {
        if (c == avatar && ++j == 4) {
            win_diag_referee(game, x + i, y + i);
            return 1;
        } else {
            j = 0;
        }
    }
    return 0;
}

static int check_col(game_t *game, char avatar, int x)
{
    char c = 0;
    int j = 0;

    for (int i = 0; game->map[i] && (c = game->map[i][x]); i++) {
        if (c == avatar && ++j == 4) {
            win_col_referee(game, x, i);
            return 1;
        } else {
            j = 0;
        }
    }
    return 0;
}

static int check_row(game_t *game, char avatar, int y)
{
    char c = 0;
    int j = 0;

    for (int i = 0; (c = game->map[y][i]); i++) {
        if (c == avatar && ++j == 4) {
            win_row_referee(game, i, y);
            return 1;
        } else {
            j = 0;
        }
    }
    return 0;
}

int check_win(game_t *game, char avatar, int x, int y)
{
    int row = check_row(game, avatar, y);
    int col = check_col(game, avatar, x);
    int diag = check_diag(game, avatar, x, y);

    if (row || col || diag) {
        board_display(game->map);
        my_printf("Congrats, player %c won!\n", avatar);
        return 1;
    }
    return check_tie(game);
}
