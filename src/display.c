/*
** EPITECH PROJECT, 2022
** connect4
** File description:
** display.c
*/

#include "my.h"

static void display_top_bottom(int width)
{
    for (int i = 0; i < width + 2; i++) {
        my_putchar('+');
    }
    my_putchar('\n');
}

void board_display(char **map)
{
    int map_width = my_strlen(map[0]);

    display_top_bottom(map_width);
    for (int i = 0; map[i]; i++) {
        my_putchar('|');
        my_putstr(map[i]);
        my_putstr("|\n");
    }
    display_top_bottom(map_width);
}
