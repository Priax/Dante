/*
** EPITECH PROJECT, 2023
** Dante_solve
** File description:
** Pour charger la map dans un tableau
*/
#include "../include/my.h"

void check_character(char **array, int i, int taille)
{
    int j = 0;

    for (j = 0; array[i][j] != '\n'; j++) {
        if (array[i][j] == '\0')
            break;
        if (array[i][j] != 'X' && array[i][j] != '*') {
            free_array(array);
            exit(84);
        }
    }
    if (j != taille)
        exit(84);
}

int error_maze(char **array)
{
    int i = 0;
    int taille;

    for (i = 0; array[0][i] != '\n' && array[0][i] != '\0'; i++);
    taille = i;
    if (array[0][0] != '*'){
        my_putstr("No solution found");
        return (84);
    }
    for (i = 0; array[i] != NULL; i++)
        check_character(array, i, taille);
    return (0);
}

int load_array(char *filepath)
{
    int nbline = 0;
    FILE *stream;
    size_t taille = 0;
    ssize_t read;
    char *buffer = NULL;

    stream = fopen(filepath, "r");
    if (stream == NULL)
        return (-1);
    read = getline(&buffer, &taille, stream);
    while (read != -1) {
        read = getline(&buffer, &taille, stream);
        nbline++;
    }
    if (buffer != NULL)
        free(buffer);
    return (nbline);
}

char **load_file(char *filepath)
{
    char *buffer = '\0', **array;
    FILE *stream;
    size_t taille = 0;
    ssize_t read;
    int i = 0;

    array = malloc(sizeof(char *) * (load_array(filepath) + 1));
    stream = fopen(filepath, "r");
    if (stream == NULL || load_array(filepath) == -1)
        exit(84);
    read = getline(&buffer, &taille, stream);
    for (;read != -1; i++) {
        array[i] = my_strcpy(array[i], buffer);
        read = getline(&buffer, &taille, stream);
    }
    free(buffer), fclose(stream);
    array[i] = NULL;
    if (array[0] == NULL || error_maze(array) == 84)
        exit(84);
    return (array);
}
