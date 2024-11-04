/*
** EPITECH PROJECT, 2023
** dante_utils
** File description:
** Dante
*/
#include "../include/generator.h"

void my_putstr_endl(char const *str)
{
    write(1, str, my_strlen(str)), my_putchar('\n');
}

int is_even(int nb)
{
    return (!(nb & 1));
}

int is_odd(int nb)
{
    return (nb & 1);
}

int my_divide(int nb)
{
    return (is_odd(nb) ? (nb >> 1) + 1 : nb >> 1);
}

void parse_inputs(char **argv, int *perfect)
{
    if (my_strcmp(argv[1], "-h") == 0) {
        print_usage();
        exit(0);
    }
    if (argv[3]) {
        if (!(my_strcmp(argv[3], "perfect") == 0
            || my_strcmp(argv[3], "imperfect") == 0))
                exit(84);
        if (my_strcmp(argv[3], "perfect") == 0)
            *perfect = 1;
    }
}
