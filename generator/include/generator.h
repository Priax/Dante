/*
** EPITECH PROJECT, 2020
** generator
** File description:
** Dante
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef DANTE_
    #define DANTE_
typedef struct neighbor_s {
    int x;
    int y;
} neighbor_t;

typedef struct visited_cells {
    neighbor_t v;
    int visited;
} visi_t;

typedef struct maze_s {
    neighbor_t v;
    visi_t *tab;
    char *str;
    int rows, cols;
} maze_t;

maze_t new_grid(int x, int y);
void entry_exit(maze_t grid);
void my_putstr(char const *str);
int my_cat(char *path);
int my_strcmp(char const *s1, char const *s2);
int my_divide(int nb);
void print_usage(void);
int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr_endl(char const *str);
void parse_inputs(char **argv, int *perfect);
maze_t initialize_visited_cells(int rows, int cols, maze_t grid);

/* Générateur */
visi_t **get_neighbour(visi_t *node, maze_t *grid, int *nb);
int is_invalid_neighbour(neighbor_t coord, maze_t *grid);
void remove_wall(visi_t *current,
    visi_t *neighbour, maze_t *grid, int perfect);
void randomized_dfs(maze_t *grid, visi_t **stack, int perfect);

#endif /* _DANTE_ */
