/*
** EPITECH PROJECT, 2023
** recursive
** File description:
** Dante
*/
#include "../include/generator.h"

visi_t **get_neighbour(visi_t *node, maze_t *grid, int *nb)
{
    static visi_t *neighbour[4] = {NULL, NULL, NULL, NULL};
    neighbor_t tab[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int size = 0;
    int i;
    neighbor_t coord;

    *neighbour = NULL;
    for (i = 0; i < 4 ; i++) {
        coord.x = node->v.x + tab[i].x;
        coord.y = node->v.y + tab[i].y;
        if (is_invalid_neighbour(coord, grid))
            continue;
        if (!grid->tab[grid->v.x * (coord.y) + (coord.x)].visited) {
            neighbour[size++] = &grid->tab[grid->v.x * (coord.y) + (coord.x)];
        }
    }
    *nb = size;
    return (neighbour);
}

void remove_wall(visi_t *current, visi_t *neighbour, maze_t *grid, int perfect)
{
    int i = neighbour->v.y;
    int j = neighbour->v.x;
    int height = grid->rows + 1;
    neighbor_t coord;

    coord.x = neighbour->v.x - current->v.x;
    coord.y = neighbour->v.y - current->v.y;
    grid->str[(i * height) * 2 + j * 2] = '*';
    i = current->v.y;
    j = current->v.x;
    if (perfect) {
        grid->str[(i * height) * 2 + j * 2] = '*';
    } else {
        grid->str[(i * height) + j * 2] = '*';
    }
    grid->str[(i * height) * 2 + j * 2 + (height * coord.y + coord.x)] = '*';
}

visi_t *backtrack(visi_t **stack, int *size)
{
    if (*size)
        return stack[--(*size)];
    else
        return 0;
}

void randomized_dfs(maze_t *grid, visi_t **stack, int perfect)
{
    visi_t *current = grid->tab, **neighbour, *tmp;
    int size = 0;
    int nb = 0;
    int times = grid->v.y * grid->v.x - 1;

    while (times) {
        current->visited = 1;
        neighbour = get_neighbour(current, grid, &nb);
        if (*neighbour) {
            times--;
            tmp = neighbour[rand() % nb];
            stack[size++] = current;
            remove_wall(current, tmp, grid, perfect);
            current = tmp;
            continue;
        } else {
            current = backtrack(stack, &size);
        }
    }
}
