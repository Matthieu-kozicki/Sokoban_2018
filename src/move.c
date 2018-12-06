/*
** EPITECH PROJECT, 2018
** we need to
** File description:
** move
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include <stdio.h>

char **up(char **array, pos_t *pos)
{
    if (array[pos->y - 1][pos->x] == 'X' &&
        array[pos->y - 2][pos->x] == ' ') {
        array[pos->y - 1][pos->x] = ' ';
        array[pos->y - 2][pos->x] = 'X';
    }
    if (array[pos->y - 1][pos->x] == 'X' &&
        array[pos->y - 2][pos->x] == 'O') {
        array[pos->y - 1][pos->x] = ' ';
        array[pos->y - 2][pos->x] = 'V';
    }
    if (array[pos->y - 1][pos->x] == 'V' &&
        array[pos->y - 2][pos->x] != '#') {
        array[pos->y - 1][pos->x] = 'O';
        array[pos->y - 2][pos->x] = 'X';
    }
    if (array[pos->y - 1][pos->x] != 'X' &&
        array[pos->y - 1][pos->x] != 'V') {
        pos->y = pos->y - 1;
    }
    return (array);
}

char **down(char **array, pos_t *pos)
{
    if (array[pos->y + 1][pos->x] == 'X' &&
        array[pos->y + 2][pos->x] == ' ') {
        array[pos->y + 1][pos->x] = ' ';
        array[pos->y + 2][pos->x] = 'X';
    }
    if (array[pos->y + 1][pos->x] == 'X' &&
        array[pos->y + 2][pos->x] == 'O') {
        array[pos->y + 1][pos->x] = ' ';
        array[pos->y + 2][pos->x] = 'V';
    }
    if (array[pos->y + 1][pos->x] == 'V' &&
        array[pos->y + 2][pos->x] != '#') {
        array[pos->y + 1][pos->x] = 'O';
        array[pos->y + 2][pos->x] = 'X';
    }
    if (array[pos->y + 1][pos->x] != 'X' &&
        array[pos->y + 1][pos->x] != 'V') {
        pos->y = pos->y + 1;
    }
    return (array);
}

char **right(char **array, pos_t *pos)
{
    if (array[pos->y][pos->x + 1] == 'X' &&
        array[pos->y][pos->x + 2] == ' ') {
        array[pos->y][pos->x + 1] = ' ';
        array[pos->y][pos->x + 2] = 'X';
    }
    if (array[pos->y][pos->x + 1] == 'X' &&
        array[pos->y][pos->x + 2] == 'O') {
        array[pos->y][pos->x + 1] = ' ';
        array[pos->y][pos->x + 2] = 'V';
    }
    if (array[pos->y][pos->x + 1] == 'V' &&
        array[pos->y][pos->x + 2] != '#') {
        array[pos->y][pos->x + 1] = 'O';
        array[pos->y][pos->x + 2] = 'X';
    }
    if (array[pos->y][pos->x + 1] != 'X' &&
        array[pos->y][pos->x + 1] != 'V') {
        pos->x = pos->x + 1;
    }
    return (array);
}

char **left(char **array, pos_t *pos)
{
    if (array[pos->y][pos->x - 1] == 'X' &&
        array[pos->y][pos->x - 2] == ' ') {
        array[pos->y][pos->x - 1] = ' ';
        array[pos->y][pos->x - 2] = 'X';
    }
    if (array[pos->y][pos->x - 1] == 'X' &&
        array[pos->y][pos->x - 2] == 'O') {
        array[pos->y][pos->x - 1] = ' ';
        array[pos->y][pos->x - 2] = 'V';
    }
    if (array[pos->y][pos->x - 1] == 'V' &&
        array[pos->y][pos->x - 2] != '#') {
        array[pos->y][pos->x - 1] = 'O';
        array[pos->y][pos->x - 2] = 'X';
    }
    if (array[pos->y][pos->x - 1] != 'X' &&
        array[pos->y][pos->x - 1] != 'V') {
        pos->x = pos->x - 1;
    }
    return (array);
}

char **move_it(char **array, pos_t *pos, int key, info_t *info)
{
    resizing(info, array);
    if (key == KEY_UP && array[pos->y - 1][pos->x] != '#' &&
        array[pos->y - 1][pos->x] != 0)
        array = up(array, pos);
    if (key == KEY_DOWN && array[pos->y + 1][pos->x] != '#' &&
        array[pos->y + 1][pos->x] != 0)
        array = down(array, pos);
    if (key == KEY_RIGHT && array[pos->y][pos->x + 1] != '#' &&
        array[pos->y][pos->x + 1] != 0)
        array = right(array, pos);
    if (key == KEY_LEFT && array[pos->y][pos->x - 1] != '#' &&
        array[pos->y][pos->x - 1] != 0)
        array = left(array, pos);
    clear();
    print_2d_array(array, info);
    mvprintw(pos->y, pos->x, "P");
    return (array);
}
