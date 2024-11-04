/*
** EPITECH PROJECT, 2023
** my_gen
** File description:
** Dante
*/
#include "../include/generator.h"

int set_error_rc(int *rows, int *cols, char **argv)
{
    *rows = atoi(argv[1]);
    *cols = atoi(argv[2]);
    if (*rows <= 0 || *cols <= 0
        || *rows > 50000 || *cols > 50000)
        return (84);
    return (0);
}

void entry_exit(maze_t grid)
{
    int dec = (grid.rows + 1) * grid.cols;

    if (!grid.rows || !grid.cols)
        return;
    grid.str[0] = '*';
    grid.str[dec - 2] = '*';
    if (!(grid.rows & 1) && !(grid.cols & 1))
        grid.str[dec - 3] = '*';
}

int backtrack_generator(int rows, int cols, int perfect)
{
    maze_t grid;
    visi_t **stack;

    grid = new_grid(rows, cols);
    grid = initialize_visited_cells(rows, cols, grid);
    stack = malloc(sizeof(visi_t) * (grid.v.x * grid.v.y));
    if (!grid.str || !(stack))
        return (84);
    entry_exit(grid);
    if (rows > 1 && cols > 1) {
        randomized_dfs(&grid, stack, perfect);
    }
    write(1, grid.str, (rows + 1) * cols - 1);
    free(grid.str), free(grid.tab), free(stack);
    return (0);
}

int is_invalid_neighbour(neighbor_t coord, maze_t *grid)
{
    if (coord.x < 0 || coord.x > grid->v.x - 1
    || coord.y < 0 || coord.y > grid->v.y - 1) {
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    int rows = 0;
    int cols = 0;
    int perfect = 0;

    if (argc < 2 || argc > 4)
        return (84);
    srand(time(NULL));
    parse_inputs(argv, &perfect);
    if (set_error_rc(&rows, &cols, argv) == 84)
        return (84);
    return (backtrack_generator(rows, cols, perfect));
}
