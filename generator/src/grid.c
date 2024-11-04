/*
** EPITECH PROJECT, 2023
** src/grid
** File description:
** grid
*/
#include "../include/generator.h"

void print_usage(void)
{
    my_putstr("USAGE:\n./generator rows cols p/i\n");
    my_putstr("perfect/imperfect ");
    my_putstr("refers to if the maze should be perfect or imperfect\n");
    my_putstr("As the perfect argument is optional,");
    my_putstr("the default generation will be an imperfect maze.");
    my_putstr("We used Recursive Backtracker as the generator and ");
    my_putstr("A* as the solver algorithm\n");
    my_cat("maps/dante.txt");
}

maze_t new_grid(int rows, int cols)
{
    maze_t grid;
    int len = (rows + 1) * cols, i;

    grid.v.x = my_divide(rows);
    grid.v.y = my_divide(cols);
    grid.rows = rows;
    grid.cols = cols;
    grid.str = malloc(sizeof(char) * len);
    if (len > 2147483647) {
        free(grid.str), exit(84);
    }
    if (!grid.str)
        exit(84);
    memset(grid.str, rows > 1 && cols > 1 ? 'X' : '*', len);
    for (i = 0; i < cols ; i++) {
        grid.str[i * (rows + 1) + rows] = '\n';
    }
    return (grid);
}

maze_t initialize_visited_cells(int rows, int cols, maze_t grid)
{
    int size = my_divide(rows) * my_divide(cols), i;

    grid.tab = malloc(sizeof(visi_t) * size);
    if (!grid.tab)
        exit(84);
    for (i = 0; i < size; i++) {
        grid.tab[i].visited = 0;
        grid.tab[i].v.x = i % grid.v.x;
        grid.tab[i].v.y = i / grid.v.x;
    }
    return (grid);
}
