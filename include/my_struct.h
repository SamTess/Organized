/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : struct header
*/

#ifndef _MY_STRUCT_
    #define _MY_STRUCT_
    #include "../include/shell.h"


typedef enum type {
    ACTUATORS,
    DEVICES,
    PROCESSORS,
    SENSORS,
    WIRES
}type_t;

typedef struct linked_list_s {
    struct linked_list_s *prev;
    char *name;
    int id;
    int id_tot;
    char *category;
    struct linked_list_s *next;
} linked_list_t;

#endif /* !_MY_STRUCT_ */
