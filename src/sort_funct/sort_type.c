/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : sort name
*/
#include "../../include/shell.h"

void sep_list_type(linked_list_t *begin, linked_list_t **start,
    linked_list_t **end)
{
    linked_list_t *fst = begin->next;
    linked_list_t *slw = begin;

    while (fst != NULL) {
        fst = fst->next;
        if (fst != NULL) {
            slw = slw->next;
            fst = fst->next;
        }
    }
    *start = begin;
    *end = slw->next;
    slw->next = NULL;
}

linked_list_t *sorted_type(linked_list_t *temp_a, linked_list_t *temp_b)
{
    linked_list_t *result = NULL;

    if (temp_a == NULL) {
        return temp_b;
    } else if (temp_b == NULL) {
        return temp_a;
    }
    if (my_strcmpv(temp_a->category, temp_b->category) <= 0) {
        result = temp_a;
        result->next = sorted_type(temp_a->next, temp_b);
    } else {
        result = temp_b;
        result->next = sorted_type(temp_a, temp_b->next);
    }
    return result;
}

void sort_type_m(linked_list_t **data)
{
    linked_list_t *begin = *data;
    linked_list_t *temp_a;
    linked_list_t *temp_b;

    if (begin == NULL || begin->next == NULL) {
        return;
    }
    sep_list_type(begin, &temp_a, &temp_b);
    sort_type_m(&temp_a);
    sort_type_m(&temp_b);
    *data = sorted_type(temp_a, temp_b);
}

static int is_equal(linked_list_t *list1, linked_list_t *list2)
{
    if (list1 == NULL || list2 == NULL)
        return 0;
    return my_strcmp(list1->category, list2->category);
}

static char *check_if_same_bis(linked_list_t *list1, linked_list_t *list2)
{
    while (list2 != NULL) {
        if (is_equal(list1, list2) == 0) {
            return list1->category;
        }
        list2 = list2->next;
    }
    return NULL;
}

char *check_if_same_type(linked_list_t **current)
{
    linked_list_t *list1 = *current;
    linked_list_t *list2 = NULL;
    char *result = malloc(sizeof(char) * 50);

    while (list1 != NULL) {
        list2 = list1->next;
        result = check_if_same_bis(list1, list2);
        if (result != NULL) {
            return result;
        }
        list1 = list1->next;
    }
    free(result);
    return NULL;
}
