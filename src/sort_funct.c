/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : sort function
*/
#include "../include/shell.h"

void *init;
char *fst_type;

static int check_args_selec(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "NAME") != 0 && my_strcmp(args[i], "ID") != 0
        && my_strcmp(args[i], "TYPE") != 0 && my_strcmp(args[i], "-r") != 0)
            return 84;
    }
    return 0;
}

linked_list_t *reverse_funct(linked_list_t *current, char **args, int i)
{
    linked_list_t *prev = NULL;
    linked_list_t *nextN = NULL;
    linked_list_t *firstOriginal = current;

    if (args[i + 1] == NULL) {
        return current;
    }
    if (my_strcmp(args[i + 1], "-r") != 0) {
        return current;
    }
    while (current != NULL) {
        nextN = current->next;
        current->next = prev;
        prev = current;
        current = nextN;
        if (current == NULL) {
            firstOriginal->next = NULL;
        }
    }
    return prev;
}

static int which_case_cont(linked_list_t **new_list,
    char **args, int i)
{
    linked_list_t **reversed_list = malloc(sizeof(linked_list_t *) * 30);

    if (my_strcmp(args[i], "TYPE") == 0) {
        sort_type_m(new_list);
        *reversed_list = reverse_funct(*new_list, args, i);
        *(linked_list_t **)init = fusion_list(*reversed_list, init, fst_type);
        if (check_if_same_type(new_list) != NULL) {
            return sort_cont(fst_type, new_list, args, i);
        }
        return 0;
    }
    if (my_strcmp(args[i], "ID") == 0) {
        sort_id_m(new_list);
        *reversed_list = reverse_funct(*new_list, args, i);
        *(linked_list_t **)init = fusion_list(*reversed_list, init, fst_type);
        return 0;
    }
    return 84;
}

static int which_case(linked_list_t **new_list, char **args, int i)
{
    linked_list_t **reversed_list = malloc(sizeof(linked_list_t *) * 30);
    int j = 0;

    if (args[i] == NULL)
        return 0;
    if (my_strcmp(args[i], "NAME") == 0) {
        sort_name_m(new_list);
        *reversed_list = reverse_funct(*new_list, args, i);
        *(linked_list_t **)init = fusion_list(*reversed_list, init, fst_type);
        if (check_if_same_name(new_list) != NULL) {
            fst_type = my_strdup(check_if_same_name(new_list));
            return sort_cont(fst_type, new_list, args, i);
        }
        return 0;
    }
    j = which_case_cont(new_list, args, i);
    if (j == 0) {
        return 0;
    }
    return 84;
}

static void create_node(linked_list_t *current, linked_list_t **new_list)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));

    new_node->category = my_strdup(current->category);
    new_node->name = my_strdup(current->name);
    new_node->id = current->id;
    new_node->id_tot = current->id_tot;
    new_node->next = *new_list;
    *new_list = new_node;
}

int sort_cont(char *category, void *data, char **args, int i)
{
    linked_list_t *new_list = NULL;
    linked_list_t *current = *(linked_list_t **)data;

    if (args[i + 1] == NULL)
        return 0;
    if (args[i + 1][0] == '-' && args[i + 1][1] == 'r')
        i++;
    while (current != NULL) {
        if (my_strcmp(current->category, category) == 0
            || my_strcmp(current->name, category) == 0)
                create_node(current, &new_list);
        current = current->next;
    }
    if (args[i + 1] != NULL && args[i + 1][0] == '-'
        && args[i + 1][1] == 'r')
            new_list = reverse_funct(new_list, args, i);
    if (which_case(&new_list, args, i + 1) == 84)
        return 84;
    return 0;
}

static int sort_selection_cont(void *data, char **args,
    int i, linked_list_t **current)
{
    if (my_strcmp(args[i], "TYPE") == 0) {
        sort_type_m(current);
        *current = reverse_funct(*current, args, i);
        if (check_if_same_type(current) != NULL) {
            fst_type = my_strdup(check_if_same_type(current));
            return sort_cont(fst_type, data, args, i);
        }
        return 0;
    }
    if (my_strcmp(args[i], "ID") == 0) {
        sort_id_m(current);
        *current = reverse_funct(*current, args, i);
        return 0;
    }
    return 84;
}

static int sort_selection(void *data, char **args, int i)
{
    linked_list_t **current = (linked_list_t **)data;
    int j = 0;

    if (args[i] == NULL) {
        return 84;
    }
    if (my_strcmp(args[i], "NAME") == 0) {
        sort_name_m(current);
        *current = reverse_funct(*current, args, i);
        if (check_if_same_name(current) != NULL) {
            fst_type = my_strdup(check_if_same_name(current));
            return sort_cont(fst_type, current, args, i);
        }
        return 0;
    }
    j = sort_selection_cont(data, args, i, current);
    if (j == 0) {
        return 0;
    }
    return 84;
}

int sort(void *data, char **args)
{
    init = data;
    if (check_args_selec(args) == 84) {
        return 84;
    }
    if (sort_selection(data, args, 0) == 84) {
        return 84;
    }
    data = init;
    free(fst_type);
    return 0;
}
