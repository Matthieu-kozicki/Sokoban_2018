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
#include <stdio.h>
#include "my.h"

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
    int fd = fs_open_file(arg[1]);
    if (fd == -1)
        return (84);
    struct stat s;
    stat(arg[1], &s);
    char buff[s.st_size + 1];

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
    if (so(arc, arg) == 84)
        return (84);
    else
        return (0);
}
