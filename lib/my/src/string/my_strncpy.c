/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_strncpy function
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    if (i < n) {
        dest[i] = '\0';
    }
    return (dest);
}
