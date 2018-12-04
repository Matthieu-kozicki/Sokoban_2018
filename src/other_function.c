/*
** EPITECH PROJECT, 2018
** can we
** File description:
** 2d array
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

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
