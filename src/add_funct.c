/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : add function
*/
#include "../include/shell.h"

static int put_after(char **args, void *data, int i)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));

    new_node->next = *(linked_list_t **)data;
    new_node->category = my_strdup(args[i]);
    new_node->name = my_strdup(args[i + 1]);
    new_node->id = count_id + 1;
    count_id += 1;
    mini_printf("%s n°%d - \"%s\" added.\n", new_node->category,
    new_node->id, new_node->name);
    *(linked_list_t **)data = new_node;
    if (args[i + 2] != NULL) {
        check_args(args, i + 2, data);
    }
    return 0;
}

static int put_first(char **args, void *data, int i)
{
    linked_list_t *new_node = malloc(sizeof(struct linked_list_s));

    new_node->category = my_strdup(args[i]);
    new_node->name = my_strdup(args[i + 1]);
    new_node->id = count_id;
    new_node->id_tot = count_id;
    new_node->next = *(linked_list_t **)data;
    *(linked_list_t **)data = new_node;
    mini_printf("%s n°%d - \"%s\" added.\n", new_node->category,
    new_node->id, new_node->name);
    if (args[i + 2] != NULL) {
        check_args(args, i + 2, data);
    }
    return 0;
}

static int put_list(char **args, void *data, int i)
{
    linked_list_t *current = *(linked_list_t **)data;

    if (current == NULL && count_id == 0) {
        if (put_first(args, data, i) == 84)
            return 84;
    } else {
        if (put_after(args, data, i) == 84)
            return 84;
    }
    return 0;
}

static int check_name_bis(char **args, int i, void *data)
{
    if (my_strcmp(args[i + 1], "PROCESSOR") == 0) {
        return 84;
    }
    if (my_strcmp(args[i + 1], "SENSOR") == 0) {
        return 84;
    }
    if (my_strcmp(args[i + 1], "WIRE") == 0) {
        return 84;
    } else {
        return put_list(args, data, i);
    }
}

static int check_name(char **args, int i, void *data)
{
    if (args[i + 1] == NULL) {
        return 84;
    }
    if (my_strcmp(args[i + 1], "ACTUATOR") == 0) {
        return 84;
    }
    if (my_strcmp(args[i + 1], "DEVICE") == 0) {
        return 84;
    }
    if (check_name_bis(args, i, data) == 84) {
        return 84;
    }
    return 0;
}

static int check_args_bis(char **args, int i, void *data)
{
    if (my_strcmp(args[i], "PROCESSOR") == 0) {
        return check_name(args, i, data);
    }
    if (my_strcmp(args[i], "SENSOR") == 0) {
        return check_name(args, i, data);
    }
    if (my_strcmp(args[i], "WIRE") == 0) {
        return check_name(args, i, data);
    } else {
        return 84;
    }
}

int check_args(char **args, int i, void *data)
{
    if (my_strcmp(args[i], "ACTUATOR") == 0) {
        return check_name(args, i, data);
    }
    if (my_strcmp(args[i], "DEVICE") == 0) {
        return check_name(args, i, data);
    }
    if (check_args_bis(args, i, data) == 84) {
        return 84;
    }
    return 0;
}

int add(void *data, char **args)
{
    if (args[0] == NULL) {
        return 84;
    }
    return check_args(args, 0, data);
}
