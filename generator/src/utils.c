/*
** EPITECH PROJECT, 2023
** utils
** File description:
** Dante
*/
#include "../include/generator.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return (i);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void free_2d_array(char **array)
{
    int i;

    for (i = 0; array[i]; i++) {
        free(array[i]);
    }
    free(array);
}

void print_2d_array(char **arr)
{
    while (*arr != NULL) {
        my_putstr(*arr++);
        my_putchar('\n');
    }
}
