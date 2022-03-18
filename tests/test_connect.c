/*
** EPITECH PROJECT, 2022
** duostumper2
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "connect.h"

Test(error_handling, width_no_number)
{
    char *argv[3] = { "./connect", "-w", "a" };
    int out = connectfour(3, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, height_no_number)
{
    char *argv[3] = { "./connect", "-h", "a" };
    int out = connectfour(3, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, player_1_empty)
{
    char *argv[3] = { "./connect", "-p1", "" };
    int out = connectfour(3, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, player_2_too_many_chars)
{
    char *argv[3] = { "./connect", "-p2", "qz" };
    int out = connectfour(3, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, unknown_arg)
{
    char *argv[3] = { "./connect", "-g", "" };
    int out = connectfour(3, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, no_width)
{
    char *argv[2] = { "./connect", "-w" };
    int out = connectfour(2, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, no_a)
{
    char *argv[2] = { "./connect", "-a" };
    int out = connectfour(2, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, same_player)
{
    char *argv[7] = { "./connect", "-w", "5", "-p1", "R", "-p2", "R" };
    int out = connectfour(7, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, width_upscale)
{
    char *argv[3] = { "./connect", "-w", "150" };
    int out = connectfour(3, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, height_downscale)
{
    char *argv[3] = { "./connect", "-g", "-4" };
    int out = connectfour(3, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, too_small_grid)
{
    char *argv[3] = { "./connect", "-w", "1" };
    int out = connectfour(3, argv);

    cr_assert_eq(out, 84);
}

Test(error_handling, player_referee_same)
{
    char *argv[5] = { "./connect", "-p1", "Z", "-a", "Z" };
    int out = connectfour(5, argv);

    cr_assert_eq(out, 84);
}

Test(win_handling, win_row)
{
    game_t *game = malloc(sizeof(game_t));
    int out = 0;

    init_game(game);
    init_map(game);
    game->map[0][0] = 'X';
    game->map[0][1] = 'X';
    game->map[0][2] = 'X';
    game->map[0][3] = 'X';
    out = check_win(game, 'X', 0, 0);
    cr_assert_eq(out, 1);
}

Test(win_handling, win_col)
{
    game_t *game = malloc(sizeof(game_t));
    int out = 0;

    init_game(game);
    init_map(game);
    game->map[0][0] = 'X';
    game->map[1][0] = 'X';
    game->map[2][0] = 'X';
    game->map[3][0] = 'X';
    out = check_win(game, 'X', 0, 0);
    cr_assert_eq(out, 1);
}

Test(win_handling, win_diag_top)
{
    game_t *game = malloc(sizeof(game_t));
    int out = 0;

    init_game(game);
    init_map(game);
    game->map[0][3] = 'X';
    game->map[1][2] = 'X';
    game->map[2][1] = 'X';
    game->map[3][0] = 'X';
    out = check_win(game, 'X', 0, 3);
    cr_assert_eq(out, 1);
}

Test(win_handling, win_diag_bottom)
{
    game_t *game = malloc(sizeof(game_t));
    int out = 0;

    init_game(game);
    init_map(game);
    game->map[0][0] = 'X';
    game->map[1][1] = 'X';
    game->map[2][2] = 'X';
    game->map[3][3] = 'X';
    out = check_win(game, 'X', 0, 0);
    cr_assert_eq(out, 1);
}
