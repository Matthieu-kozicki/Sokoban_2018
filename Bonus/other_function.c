/*
** EPITECH PROJECT, 2018
** can we
** File description:
** 2d array
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"


char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int i = 0;
    char **result = malloc(sizeof(char *) * (nb_rows + 2));

    result[nb_rows + 1] = NULL;
    for (i = 0; i <= nb_rows; i++) {
        result[i] = malloc(sizeof(char) * (nb_cols + 2));
        result[i][nb_rows + 1] = '\0';
    }
    return (result);
}

void free_2d(char **str, int nb_rows, int nb_cols)
{
    int i = 0;

    for (i = 0; i <= nb_rows; i++)
        free(str[i]);
    free(str);
}

int fs_open_file(char const *filepath)
{
    int try = 0;

    try = open(filepath, O_RDONLY);
    if (try == -1)
        my_putstr("FAILURE\n");
    return (try);
}

void print_2d_array(char **array, info_t *info)
{
    int j = 0;
    int i = 0;

    for (j = 0; j < info->row; j++) {
        for (i = 0; i < info->col; i++) {
            if (array[j][i] == 'V') {
                start_color();
                init_pair(1, COLOR_GREEN, COLOR_BLACK);
                attron(COLOR_PAIR(1));
                printw("X");
                attroff(COLOR_PAIR(1));
            }
            else
                printw("%c", array[j][i]);
        }
    }
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
