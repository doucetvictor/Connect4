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

int connect(int argc, char **argv);
int get_options(int argc, char **argv, game_t *game);
int get_player_choice(char c, game_t *game);
void board_display(char **map);
void game_loop(game_t *game);

#endif
