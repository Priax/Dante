/*
** EPITECH PROJECT, 2023
** dante_solve
** File description:
** number in maze for solve
*/
#include "../include/my.h"

int clos_end(open_t **head, tab *solvtab, int end, open_t *ptr)
{
    int row = solvtab->row;
    int col = solvtab->col;
    int i = 0;

    if (col - 1 >= 0 && solvtab->arr[row][col - 1] == '*'){
        solvtab->col -= 1;
        set_add_o(&(*head), end, solvtab, ptr);
        solvtab->arr[solvtab->row][solvtab->col] = 'P';
        solvtab->col += 1;
        i++;
    }
    return (i);
}

int clos_next(open_t **head, tab *solvtab, int end, open_t *ptr)
{
    int row = solvtab->row;
    int col = solvtab->col;
    int i = 0;

    if (col + 1 <= solvtab->colmax && solvtab->arr[row][col + 1] == '*') {
        solvtab->col += 1;
        set_add_o(&(*head), end, solvtab, ptr);
        solvtab->arr[solvtab->row][solvtab->col] = 'P';
        solvtab->col -= 1;
        i++;
    }
    if (row - 1 >= 0 && solvtab->arr[row - 1][col] == '*'){
        solvtab->row -= 1;
        set_add_o(&(*head), end, solvtab, ptr);
        solvtab->arr[solvtab->row][solvtab->col] = 'P';
        solvtab->row += 1;
        i++;
    }
    i += clos_end(head, solvtab, end, ptr);
    return (i);
}

void clos(open_t **head, open_t **tail, tab *solvtab)
{
    int i = 0;
    int end = 0;
    int row;
    int col;
    open_t *ptr = *head;

    solvtab->row = ptr->node->row;
    solvtab->col = ptr->node->col, set_add_c(tail, ptr->node);
    row = solvtab->row;
    col = solvtab->col;
    end = (solvtab->colmax - col) + (solvtab->rowmax - row);
    solvtab->start = ptr->node->start + 1;
    solvtab->arr[row][col] = 'C';
    if (row + 1 <= solvtab->rowmax && solvtab->arr[row + 1][col] == '*') {
        solvtab->row += 1, set_add_o(&(*head), end, solvtab, ptr);
        solvtab->arr[solvtab->row][solvtab->col] = 'P';
        solvtab->row -= 1;
        i++;
    }
    i += clos_next(head, solvtab, end, ptr), del_node(&(*head), 0);
}

void make_path(open_t **tail, tab *solvtab)
{
    int i = 0;
    open_t *ptr = *tail;

    for (i = 0; ptr->node->col != solvtab->col
        || ptr->node->row != solvtab->row; i++)
        ptr = ptr->next;
    while (ptr->node->parent != NULL){
        solvtab->arr[ptr->node->row][ptr->node->col] = 'o';
        ptr->node = ptr->node->parent;
    }
    solvtab->row = ptr->node->row;
    solvtab->col = ptr->node->col;
}

void find_path(tab *solvtab)
{
    int i = 0;
    open_t *head = init_list(solvtab);
    open_t *tail = init_list(solvtab);

    while (solvtab->arr[solvtab->rowmax][solvtab->colmax] != 'C') {
        if (head == NULL){
            my_putstr("no solution found");
            return;
        }
        clos(&head, &tail, solvtab);
    }
    make_path(&tail, solvtab);
    for (i = 0; solvtab->arr[i] != NULL; i++)
        change_c(solvtab, i);
    solvtab->arr[solvtab->row][solvtab->col] = 'o';
    free_list(tail);
    free_list(head);
    print_2d_array(solvtab->arr);
}
