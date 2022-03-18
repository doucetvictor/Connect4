/*
** EPITECH PROJECT, 2022
** duostumper2
** File description:
** Options
*/

#include <stdlib.h>
#include <string.h>
#include "connect.h"
#include "my.h"

static int check_number(int i, int argc, char **argv, int *ptr)
{
    char *str = NULL;

    if (argc <= i + 1) {
        my_fprintf(2, "Error: Missing argument with %s\n", argv[i]);
        return (-1);
    }
    strtol(argv[i + 1], &str, 10);
    if (strlen(str) > 0) {
        my_fprintf(2, "Error: Width must be a number\n");
        return (-1);
    }
    *ptr = atoi(argv[i + 1]);
    return (i + 1);
}

static int check_character(int i, int argc, char **argv, char *ptr)
{

    if (argc <= i + 1) {
        my_fprintf(2, "Error: Missing argument with %s\n", argv[i]);
        return (-1);
    } else if (strlen(argv[i + 1]) != 1) {
        my_fprintf(2, "Error: Avatar and referees must be 1 character\n");
        return (-1);
    }
    *ptr = argv[i + 1][0];
    return (i + 1);
}

static int check_argument(int i, int argc, char **argv, game_t *game)
{
    if (strcmp(argv[i], "-w") == 0) {
        return (check_number(i, argc, argv, &game->width));
    } else if (strcmp(argv[i], "-h") == 0) {
        return (check_number(i, argc, argv, &game->height));
    }
    if (strcmp(argv[i], "-p1") == 0) {
        return (check_character(i, argc, argv, &game->avatar1));
    } else if (strcmp(argv[i], "-p2") == 0) {
        return (check_character(i, argc, argv, &game->avatar2));
    }
    if (strcmp(argv[i], "-a") == 0) {
        return (check_character(i, argc, argv, &game->referee));
    }
    my_fprintf(2, "Error: Unknown argument %s\n", argv[i]);
    return (-1);
}

int get_options(int argc, char **argv, game_t *game)
{
    int result = 1;

    for (int i = 1; i < argc && i > -1; i++) {
        result = check_argument(i, argc, argv, game);
        if (result == -1) {
            return (0);
        } else {
            i = result;
        }
    }
    return (1);
}
