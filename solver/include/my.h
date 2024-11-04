/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Dante
*/

#ifndef DANTE_
    #define DANTE_
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <fcntl.h>

typedef struct tableau {
    int row;
    int col;
    int colmax;
    int rowmax;
    int start;
    char **arr;
} tab;

typedef struct maze {
    int start;
    int end;
    int total;
    int col;
    int row;
    struct maze *parent;
} maze;

typedef struct open_s {
    maze *node;
    struct open_s *next;
} open_t;

void my_putchar(char c);
int my_strlen(char const *str);
void my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_cat(char *path);
void print_usage(void);
int load_array(char *filepath);
void check_character(char **array, int i, int taille);
int error_maze(char **array);
char **load_file(char *filepath);
int put_number_maze(char **array, int i, int j);
void free_array(char **arr);
char *my_strcpy(char *dest, char *src);
int is_even(int nb);
void set_add_o(open_t **head, int end, tab *solvtab, open_t *ptr);
void set_add_c(open_t **head, maze *node);
void del_node(open_t **head, int position);
int small_number(open_t *head);
void find_path(tab *solvtab);
void my_putnbr(int nb);
void free_list(open_t *tail);
void change_c(tab *solvtab, int i);
open_t *init_list(tab *solvtab);
void print_2d_array(char **arr);

#endif /* _DANTE_ */
