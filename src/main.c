/*
** EPITECH PROJECT, 2018
** in
** File description:
** mid
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include <stdio.h>
#include "my.h"

void print_2d_array(char **array, info_t *info)
{
    int j = 0;

    for (j = 0; j < info->row; j++) {
        printw("%s", array[j]);
    }
}

char **up(char **array, pos_t *pos)
{
    if (array[pos->y - 1][pos->x] != '#') {
        if (array[pos->y - 1][pos->x] == 'X' && array[pos->y - 2][pos->x] != '#' && array[pos->y - 2][pos->x] != 'X') {
            array[pos->y - 1][pos->x] = ' ';
            array[pos->y - 2][pos->x] = 'X';
        }
        if (array[pos->y - 1][pos->x] != 'X' && array[pos->y - 1][pos->x] != 'O') {
            array[pos->y][pos->x] = ' ';
            array[pos->y - 1][pos->x] = 'P';
            pos->y = pos->y - 1;
        }
    }
    return (array);
}

char **down(char **array, pos_t *pos)
{
    if (array[pos->y + 1][pos->x] != '#') {
        if (array[pos->y + 1][pos->x] == 'X' && array[pos->y + 2][pos->x] != '#' && array[pos->y + 2][pos->x] != 'X') {
            array[pos->y + 1][pos->x] = ' ';
            array[pos->y + 2][pos->x] = 'X';
        }
        if (array[pos->y + 1][pos->x] != 'X' && array[pos->y + 1][pos->x] != 'O') {
            array[pos->y][pos->x] = ' ';
            array[pos->y + 1][pos->x] = 'P';
            pos->y = pos->y + 1;
          }
    }
    return (array);
}

char **right(char **array, pos_t *pos)
{
    if (array[pos->y][pos->x + 1] != '#') {
        if (array[pos->y][pos->x + 1] == 'X' && array[pos->y][pos->x + 2] != '#' && array[pos->y][pos->x + 2] != 'X') {
            array[pos->y][pos->x + 1] = ' ';
            array[pos->y][pos->x + 2] = 'X';
        }
        if (array[pos->y][pos->x + 1] != 'X' && array[pos->y][pos->x + 1] != 'O') {
            array[pos->y][pos->x] = ' ';
            array[pos->y][pos->x + 1] = 'P';
            pos->x = pos->x + 1;
        }
    }
    return (array);
}

char **left(char **array, pos_t *pos)
{
    if (array[pos->y][pos->x - 1] != '#') {
        if (array[pos->y][pos->x - 1] == 'X' && array[pos->y][pos->x - 2] != '#' && array[pos->y][pos->x - 2] != 'X') {
            array[pos->y][pos->x - 1] = ' ';
            array[pos->y][pos->x - 2] = 'X';
        }
        if (array[pos->y][pos->x - 1] != 'X' && array[pos->y][pos->x - 1] != 'O') {
            array[pos->y][pos->x] = ' ';
            array[pos->y][pos->x - 1] = 'P';
            pos->x = pos->x - 1;
        }
    }
    return (array);
}

char **move_it(char **array, pos_t *pos, int key)
{
    if (key == KEY_UP)
        array = up(array, pos);
    if (key == KEY_DOWN)
        array = down(array, pos);
    if (key == KEY_RIGHT)
        array = right(array, pos);
    if (key == KEY_LEFT)
        array = left(array, pos);
    return (array);
}

char **copy_2d(char **array, char **copy, info_t *info)
{
    int i = 0;
    int  j = 0;

    while(i < info->row) {
        while (j < info->col) {
            copy[i][j] = array[i][j];
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    return (copy);
}

char **reset_map(char **array, char **copy, info_t *info, pos_t *pos)
{
    int i = 0;
    int j = 0;

    array = copy_2d(array, copy, info);
    while (i < info->row) {
        for(j = 0; j < info->col; j++) {
            if (array[i][j] == 'P') {
                pos->x = j;
                pos->y = i;
            }
        }
        i = i + 1;
    }
    return (array);
}

int sokoban(char **array, info_t *info, pos_t *pos)
{
    int key = 0;
    char **reset = mem_alloc_2d_array(info->row, info->col);

    reset = copy_2d(array, reset, info);
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    print_2d_array(array, info);
    while (key != 27) {
        wrefresh(stdscr);
        key = getch();
        if (key == 32)
            array = reset_map(reset, array, info, pos);
        array = move_it(array,pos, key);
        clear();
        print_2d_array(array, info);
    }
    clear();
    endwin();
    return (0);
}
int get_row(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            j++;
        i++;
    }
    return (j);
}

char **load(char *str, info_t *info, pos_t *pos, char **copy)
{
    int hight = 0;
    int lon = 0;
    int k = 0;

    while (hight < info->row) {
        while (str[k] != '\n') {
            if (str[k] == 'P') {
                str[k] == ' ';
                pos->x = lon;
                pos->y = hight;
            }
            copy[hight][lon] = str[k];
            lon = lon + 1;
            k = k + 1;
        }
        copy[hight][lon] = '\n';
        lon = 0;
        hight = hight + 1;
        k = k + 1;
    }
    return (copy);
}
int ban(char *str)
{
    int col = get_col(str);
    int row = get_row(str);
    info_t info = {row, col};
    pos_t pos = {0, 0};
    char **array = mem_alloc_2d_array(row, col);

    array = load(str, &info, &pos, array);
    sokoban(array, &info, &pos);
}
int get_col(char *str)
{
    int i = 0;
    int j = 0;
    int col = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n'){
            if ( j > col)
                col = j;
            j = 0;
        }
        j++;
        i++;
    }
    return (col);
}

int so(int arc, char **arg)
{
    int i = 0;
    struct stat s;
    stat(arg[1], &s);
    char buff[s.st_size + 1];
    int fd = open(arg[1], O_RDONLY);

    read (fd, buff, s.st_size);
    buff[s.st_size + 1] = '\0';
    while (buff[i] != '\0') {
        if (buff[i] == '#' || buff[i] == ' ' || buff[i] == '\n'
            || buff[i] == 'X' || buff[i] == 'P' || buff[i] == 'O')
            i = i + 1;
        else {
            my_putstr("error\n");
            return (84);
        }
    }
    ban(buff);
}
int main(int arc, char **arg)
{
    if (arc != 2) {
        my_putstr("error\n");
        return (84);
    }
    if (arg[1][0] == '-' && arg[1][1] == 'h') {
        my_putstr("USAGE\n      ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n      ");
        my_putstr("map   file representing the warehouse map, co"
                  "ntaining '#' for walls,\n");
        my_putstr("      'P' for the player, 'X' for the boxes and"
                  " 'O' for the storage locations.\n");
        return (84);
    }
    so(arc, arg);
}
