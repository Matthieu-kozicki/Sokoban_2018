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
#include "my.h"
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
