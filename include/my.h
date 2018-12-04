/*
** EPITECH PROJECT, 2018
** warning
** File description:
** nop
*/

#ifndef MY_H
#define MY_H

typedef struct info {
    int row;
    int col;
}info_t;
typedef struct pos {
    int x;
    int y;
}pos_t;
void my_putchar(char c);
int my_put_nbr(int nb);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void free_2d(char **str, int nb_rows, int nb_cols);
void my_putstr(char const *str);
int get_col(char *str);
int my_strlen(char const *str);

#endif
