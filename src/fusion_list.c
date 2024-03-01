/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : fusion list function
*/
#include "../include/shell.h"

int check_data(linked_list_t *list1, char *category)
{
    if ((my_strcmp(list1->category, category) == 0)
    || (my_strcmp(list1->name, category) == 0)) {
        return 0;
    } else {
        return 1;
    }
}

void free_node(linked_list_t *node)
{
    free(node->category);
    free(node->name);
    free(node);
}

int compare_nodes(linked_list_t *node1, linked_list_t *node2)
{
    if (my_strcmp(node1->category, node2->category) == 0 &&
        my_strcmp(node1->name, node2->name) == 0 &&
        node1->id == node2->id &&
        node1->id_tot == node2->id_tot) {
            return 1;
        } else {
            return 0;
        }
}

static void remove_dupl_cont(linked_list_t *current)
{
    linked_list_t *runner = current;
    linked_list_t *temp = NULL;

    while (runner->next != NULL) {
        if (compare_nodes(current, runner->next) == 1) {
            temp = runner->next;
            runner->next = runner->next->next;
            free(temp);
        } else {
            runner = runner->next;
        }
    }
}

linked_list_t *remove_duplicates(linked_list_t *head)
{
    linked_list_t *current = head;
    linked_list_t *temp = NULL;

    while (current != NULL) {
        remove_dupl_cont(current);
        if (current->next != NULL
            && compare_nodes(current, current->next) == 1) {
                temp = current->next;
                current->next = current->next->next;
                free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

static void fusion_cont(linked_list_t *final_list,
    linked_list_t *current_init, linked_list_t *new_list)
{
    linked_list_t *new_copy_list = NULL;

    if (current_init != NULL) {
        new_copy_list = new_list;
        while (new_copy_list != NULL) {
            final_list->next = malloc(sizeof(linked_list_t));
            final_list->next->category = my_strdup \
                (new_copy_list->category);
            final_list->next->name = my_strdup(new_copy_list->name);
            final_list->next->id = new_copy_list->id;
            final_list->next->id_tot = new_copy_list->id_tot;
            final_list = final_list->next;
            new_copy_list = new_copy_list->next;
        }
        final_list->next = current_init;
    }
}

linked_list_t *fusion_list(linked_list_t *new_list, void *init, char *category)
{
    linked_list_t *current_init = *(linked_list_t **)init;
    linked_list_t *final_list = NULL;
    linked_list_t *saveHead = NULL;

    if (check_data(current_init, category) == 0) {
        final_list = new_list;
        new_list = new_list->next;
        saveHead = final_list;
    } else {
        final_list = current_init;
        saveHead = final_list;
        while (current_init != NULL
            && check_data(current_init, category) != 0) {
            final_list = current_init;
            current_init = current_init->next;
        }
    }
    fusion_cont(final_list, current_init, new_list);
    *(linked_list_t **)init = remove_duplicates(saveHead);
    return *(linked_list_t **)init;
}
