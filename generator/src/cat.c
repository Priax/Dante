/*
** EPITECH PROJECT, 2023
** libC
** File description:
** cat
*/
#include "../include/generator.h"

int my_cat(char *path)
{
    int fd;
    int size;
    char buf[30000];

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        my_putstr("Error with open\n");
        return (84);
    }
    size = read(fd, buf, 30000);
    if (size <= 1) {
        my_putstr("The read of size 1 is forbidden\n");
    } else
        write(1, buf, size);
    close(fd);
    return (0);
}
