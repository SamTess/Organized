/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : del funct
*/
#include "../include/shell.h"
static int print_result(linked_list_t *current, void *data)
{
    linked_list_t *check = *(linked_list_t **)data;
    linked_list_t *result = NULL;

    mini_printf("%s n°%d - \"%s\" deleted.\n", current->category,
        current->id, current->name);
    if (current->next == NULL && current == check) {
        *(linked_list_t **)data = result;
        return 84;
    }
    return 0;
}

static int set_pose(char *str)
{
    int pos = my_getnbr(str);

    if (pos < 0) {
        return 84;
    }
    if (pos == 84) {
        return 84;
    } else {
        return pos;
    }
}

static int special_case(linked_list_t *current, void *data,
    linked_list_t **cpy_list, char *str)
{
    if (set_pose(str) == current->id) {
        if (print_result(current, data) == 84) {
            free(current);
            return 84;
        }
        *cpy_list = (*cpy_list)->next;
        current = *cpy_list;
        current->id_tot += 1;
        return 84;
    }
    return 0;
}

static int error_hand(linked_list_t **cpy_list, char **args)
{
    if (*cpy_list == NULL)
        return 84;
    if (args[0] == NULL)
        return 84;
    if (set_pose(args[0]) == 84)
        return 84;
    return 0;
}

int del_cont(linked_list_t *current, void *data, int j, char **args)
{
    linked_list_t *prev = NULL;

    for (int i = 0; current != NULL && set_pose(args[j]) != current->id; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
        return 84;
    if (print_result(current, data) == 84) {
        free(current);
        return 0;
    }
    prev->next = current->next;
    free(current);
    if (args[j + 1] != NULL) {
        return del_main(data, args, j + 1);
    }
    return 0;
}

int del_main(void *data, char **args, int j)
{
    linked_list_t **cpy_list = (linked_list_t **)data;
    linked_list_t *current = *cpy_list;

    if (error_hand(cpy_list, args) == 84)
        return 84;
    if (special_case(current, data, cpy_list, args[j]) == 84) {
        if (args[j + 1] != NULL)
            return del_main(data, args, j + 1);
        else
            return 0;
    }
    if (del_cont(current, data, j, args) == 84) {
        return 84;
    }
    return 0;
}

int del(void *data, char **args)
{
    return del_main(data, args, 0);
}
