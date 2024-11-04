/*
** EPITECH PROJECT, 2023
** dante_solve
** File description:
** les fonctions annexes
*/
#include "../include/my.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL) {
        return NULL;
    }
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

void free_array(char **arr)
{
    int i = 0;

    for (i = 0; arr[i] != NULL; i++){
        free(arr[i]);
    }
    free(arr);
}

void my_putnbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else {
        my_putchar('0' + nb);
    }
}

void change_c(tab *solvtab, int i)
{
    int j = 0;

    for (j = 0; solvtab->arr[i][j] != '\n'; j++) {
        if (solvtab->arr[i][j] == '\0')
            break;
        if (solvtab->arr[i][j] == 'P' || solvtab->arr[i][j] == 'C')
            solvtab->arr[i][j] = '*';
    }
}

open_t *init_list(tab *solvtab)
{
    open_t *head = malloc(sizeof(open_t));
    maze *temp = malloc(sizeof(maze));

    temp->start = 0;
    temp->end = (solvtab->colmax - 0) + (solvtab->rowmax - 0);
    temp->total = temp->end;
    temp->col = solvtab->col;
    temp->row = solvtab->row;
    temp->parent = NULL;
    head->node = temp;
    head->next = NULL;
    return (head);
}
