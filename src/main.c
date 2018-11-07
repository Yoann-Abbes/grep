/*
** EPITECH PROJECT, 2018
** grep
** File description:
** grep
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"

int my_grep(int, char*, char*, int);
int read_in_standard(char*, int, int, int);

int main(int ac, char **av)
{
    int j = 2;
    int error = 0;

    if (ac == 2 || ac == 1)
        error = read_in_standard(av[1], 1, ac, 0);
    else {
        for (; j < ac; j++)
            error = my_grep(ac, av[j], av[1], 0);
    }
    return (error);
}
