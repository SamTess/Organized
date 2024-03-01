/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
    int isnega = 1;
    int nb = 0;
    int i = 0;

    if (str[i] == '-') {
        isnega *= -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb = nb + str[i] - '0';
        } else {
            return (nb * isnega);
        }
        i++;
    }
    return (nb * isnega);
}
