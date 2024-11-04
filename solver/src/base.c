/*
** EPITECH PROJECT, 2023
** Dante_solve
** File description:
** main temporaire
*/
#include "../include/my.h"

void calc_end(tab *solvtab, int *end_col, int *end_row)
{
    for (*end_row = 0; solvtab->arr[*end_row] != NULL; (*end_row)++);
    while (solvtab->arr[0][*end_col] != '\n'
    && solvtab->arr[0][*end_col] != '\0')
        (*end_col)++;
}

int main(int argc, char **argv)
{
    int end_row = 0;
    int end_col = 0;
    tab *solvtab = malloc(sizeof(tab));

    if (argc != 2 && argc != 4) {
        free(solvtab);
        return (84);
    }
    solvtab->arr = load_file(argv[1]);
    calc_end(solvtab, &end_col, &end_row);
    if (argc == 2) {
        solvtab->rowmax = end_row - 1;
        solvtab->colmax = end_col - 1;
    } else {
        solvtab->rowmax = atoi(argv[2]) - 1;
        solvtab->colmax = atoi(argv[3]) - 1;
    }
    find_path(solvtab), free_array(solvtab->arr);
    free(solvtab);
    return (0);
}
