/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : disp function
*/
#include "../include/shell.h"

int disp(void *data, char **args)
{
    linked_list_t *current = *(linked_list_t **)data;

    if (args[0] != NULL) {
        return 84;
    }
    while (current != NULL) {
        mini_printf("%s n°%d - \"%s\"\n", current->category,
            current->id, current->name);
        current = current->next;
    }
    return 0;
}
