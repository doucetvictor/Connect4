/*
** EPITECH PROJECT, 2022
** duostumper2
** File description:
** Header
*/

#ifndef CONNECT_H
    #define CONNECT_H

typedef struct game_s {
    char **map;
    int width;
    int height;
    char avatar1;
    char avatar2;
    char referee;
} game_t;

int check_win(game_t *game, char avatar, int x, int y);
int connect(int argc, char **argv);
int get_options(int argc, char **argv, game_t *game);
int get_player_choice(char c, game_t *game);
void board_display(char **map);
void game_loop(game_t *game);
void win_col_referee(game_t *game, int x, int y);
void win_diag_referee_top(game_t *game, int x, int y);
void win_diag_referee_bottom(game_t *game, int x, int y);
void win_row_referee(game_t *game, int x, int y);
int check_diag(game_t *game, char avatar, int x, int y);

#endif
