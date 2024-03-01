/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : sort id
*/
#include "../../include/shell.h"

void sep_list_id(linked_list_t *begin,
    linked_list_t **start, linked_list_t **end)
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

linked_list_t *sorted_id(linked_list_t *temp_a, linked_list_t *temp_b)
{
    linked_list_t *result = NULL;

    if (temp_a == NULL) {
        return temp_b;
    } else if (temp_b == NULL) {
        return temp_a;
    }
    if (temp_a->id <= temp_b->id) {
        result = temp_a;
        result->next = sorted_id(temp_a->next, temp_b);
    } else {
        result = temp_b;
        result->next = sorted_id(temp_a, temp_b->next);
    }
    return result;
}

void sort_id_m(linked_list_t **data)
{
    linked_list_t *begin = *data;
    linked_list_t *temp_a;
    linked_list_t *temp_b;

    if (begin == NULL || begin->next == NULL) {
        return;
    }
    sep_list_id(begin, &temp_a, &temp_b);
    sort_id_m(&temp_a);
    sort_id_m(&temp_b);
    *data = sorted_id(temp_a, temp_b);
}

static int is_equal(linked_list_t *list1, linked_list_t *list2)
{
    if (list1 == NULL || list2 == NULL)
        return 0;
    return list1->id - list2->id;
}

static int check_if_same_bis(linked_list_t *list1, linked_list_t *list2)
{
    while (list2 != NULL) {
        if (is_equal(list1, list2) == 0) {
            return 1;
        }
        list2 = list2->next;
    }
    return 0;
}

int check_if_same_id(linked_list_t **current)
{
    linked_list_t *begin = *current;
    linked_list_t *list1 = begin;
    linked_list_t *list2 = NULL;

    while (list1 != NULL) {
        list2 = list1->next;
        if (check_if_same_bis(list1, list2) == 1) {
            return 1;
        }
        list1 = list1->next;
    }
    return 0;
}
