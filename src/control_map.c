/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** check mapping
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include <stdio.h>

char **reset_map(char **array, char **copy, info_t *info, pos_t *pos)
{
    int i = 0;
    int j = 0;

    array = copy_2d(array, copy, info);
    while (i < info->row) {
        for (j = 0; j < info->col; j++) {
            if (array[i][j] == 'P') {
                pos->x = j;
                pos->y = i;
                array[i][j] = ' ';
            }
        }
        i = i + 1;
    }
    return (array);
}

void resizing(info_t *info, char **array)
{
    int i = info->col;
    int j = info->row;
    int k = 0;

    while (i > COLS || j > LINES) {
        clear();
        k = COLS/2-11;
        mvprintw(LINES/2, k, "Enlarge the terminal :)");
        wrefresh(stdscr);
        usleep(100000);
    }
}

int check_win(char **array, info_t *info)
{
    int i = 0;
    int j = 0;

    while (i < info->row) {
        for (j = 0; j < info->col; j++) {
            if (array[i][j] == 'O' || array[i][j] == 'X')
                return (1);
        }
        i = i + 1;
    }
    clear();
    return (2);
}

int sokoban(char **array, info_t *info, pos_t *pos)
{
    int key = 0;
    int i = 0;
    char **reset = mem_alloc_2d_array(info->row, info->col);

    reset = copy_2d(array, reset, info);
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    print_2d_array(array, info);
    array[pos->y][pos->x] = ' ';
    while (key != 27) {
        key = getch();
        if (key == 32)
            array = reset_map(reset, array, info, pos);
        array = move_it(array,pos, key, info);
        i = check_win(array, info);
         if (i == 2)
             break;
    }
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
