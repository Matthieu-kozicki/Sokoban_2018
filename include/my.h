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
int fs_open_file(char const *filepath);
char **copy_2d(char **array, char **copy, info_t *info);
void print_2d_array(char **array, info_t *info);
char **move_it(char **array, pos_t *pos, int key, info_t *info);
int check_win(char **array, info_t *info);
int get_row(char *str);
int sokoban(char **array, info_t *info, pos_t *pos);
void resizing(info_t *info, char **array);
char **reset_map(char **array, char **copy, info_t *info, pos_t *pos);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void free_2d(char **str, int nb_rows, int nb_cols);
void my_putstr(char const *str);
int get_col(char *str);
int my_strlen(char const *str);

#endif
