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

int ko(char *str)
{
    int y = 2;
    int x = 4;
    int key = 0;

    initscr();
    keypad(stdscr, TRUE);
    while (key != 32) {
        wrefresh(stdscr);
        key = getch();
        if (key == KEY_UP)
            y = y - 1;
        if (key == KEY_DOWN)
            y = y + 1;
        if (key == KEY_RIGHT)
            x = x + 1;
	if (key == KEY_LEFT)
            x = x - 1;
	clear();
	printw("%s",str);
	move(y,x);
	printw("P");
    }
    clear();
    endwin();
    return (0);
}
int get_col(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != 'P') {
        if (str[i] == '\n')
            j = j + 1;
        i = i + 1;
    }
    str[i] = ' ';
    ko(str);
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
        if (buff[i] == '#' || buff[i] == ' ' || buff[i] == '\n' || buff[i] == 'X' || buff[i] == 'P' || buff[i] == 'O')
            i = i + 1;
        else {
            my_putstr("error\n");
            return (84);
        }
    }
    get_col(buff);
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
        my_putstr("map   file representing the warehouse map, containing '#' for walls,\n");
        my_putstr("      'P' for the player, 'X' for the boxes and 'O' for the storage locations.\n");
        return (84);
    }
    so(arc, arg);
}
