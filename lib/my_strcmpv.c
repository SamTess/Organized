/*
** EPITECH PROJECT, 2023
** B-CPE-110
** File description:
** Organized : my_strcmp more precise
*/
#include "../include/shell.h"



int my_strcmpv(char const *p1, char const *p2)
{
    const unsigned char *s1 = (const unsigned char *) p1;
    const unsigned char *s2 = (const unsigned char *) p2;
    unsigned char c1;
    unsigned char c2;
    int result = 0;

    do {
        c1 = (unsigned char) *s1;
        s1++;
        c2 = (unsigned char) *s2;
        s2++;
        if (c1 == '\0') {
            result = c1 - c2;
            return result;
        }
    } while (c1 == c2);
    return c1 - c2;
}
