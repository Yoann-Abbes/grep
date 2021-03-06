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
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "my.h"

void print_error(char*);
void do_search(int, char*, char*, char*);
int read_in_standard(char*, int, int, int);

int read_in_standard(char *s, int ret, int ac, int fd)
{
    char buff[30000];

    if (ac == 1) {
        write(2, "Usage: grep [OPTION]... PATTERN [FILE]...\n", 42);
        write(2, "Try 'grep --help' for more information.\n", 40);
        return (84);
    }
    if (fd < 0)
        return (84);
    ret = read(fd, buff, 30000);
    for (; ret > 0 && fd == 0; ret = read(fd, buff, 30000)) {
        if (ac == 2) {
            do_search(1, s, s, buff);
        }
    }
    if (ret < 0)
        return (84);
    else
        return (0);
}

int my_grep(int ac, char *file, char *s, int ret)
{
    int fd = 0;
    char buff[30000];

    if (ac < 1)
        return (84);
    fd = open(file, O_RDONLY);
    if (fd < 0) {
        print_error(file);
        return (84);
    }
    ret = read(fd, buff, 30000);
    if (ret < 0) {
        print_error(file);
        return (84);
    }
    for (; ret > 0; ret = read(fd, buff, 30000)) {
        buff[ret] = '\0';
        do_search(ac, file, s, buff);
    }
    close(fd);
    return (0);
}

void do_search(int ac, char *file, char* s, char *buff)
{
    char **tab = NULL;
    int j = 0;

    tab = my_str_to_word_array(buff);
    for (; tab[j] != NULL; j++) {
        if (my_strstr(tab[j], s) != NULL && ac > 3) {
            write(1, file, my_strlen(file));
            my_putchar(':');
            my_putstr(tab[j]);
        }
        else if (my_strstr(tab[j], s) != NULL && ac <= 3)
            my_putstr(tab[j]);
    }
    free(tab);
}

void print_error(char *s)
{
    if (errno == 2) {
        write(2, "grep: ", 6);
        write(2, s, my_strlen(s));
        write(2, ": No such file or directory\n", 28);
    }
    if (errno == 21) {
        write(2, "grep: ", 6);
        write(2, s, my_strlen(s));
        write(2, ": Is a directory\n", 17);
    }
    if (errno == 13) {
        write(2, "grep: ", 6);
        write(2, s, my_strlen(s));
        write(2, ": Permission denied\n", 20);
    }
}
