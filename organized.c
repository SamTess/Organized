/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : main files
*/
#include "include/shell.h"
int count_id;

static int open_workshop(linked_list_t *data)
{
    return workshop_shell(&data);
}

int main(void)
{
    linked_list_t *data = NULL;

    count_id = 0;
    if (open_workshop(data) == 84) {
        return 84;
    }
    return 0;
}
