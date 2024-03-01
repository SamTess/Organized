/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : main header
*/

#ifndef SHELL_H
    #define SHELL_H
    #include "../include/my_struct.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>

int mini_printf(char const *format, ...);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int check_valid_arg(int argc, char const *argv[]);
int sort(void *data, char **args);
int add(void *data, char **args);
int disp(void *data, char **args);
int sort(void *data, char **args);
int workshop_shell(void *data);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int check_args(char **args, int i, void *data);
int my_getnbr(char *str);
int my_strcmpv(char const *p1, char const *p2);
void sort_name_m(linked_list_t **data);
void sort_id_m(linked_list_t **data);
void sort_type_m(linked_list_t **data);
extern int count_id;
int del_main(void *data, char **args, int i);
char *check_if_same_name(linked_list_t **current);
char *check_if_same_type(linked_list_t **current);
int check_if_same_id(linked_list_t **current);
char *my_strdup(char *str);
int sort_cont(char *category, void *data, char **args, int i);
linked_list_t *fusion_list(linked_list_t *new_list,
    void *init, char *category);
linked_list_t *remove_duplicates(linked_list_t *head);

#endif /* !SHELL_H */
