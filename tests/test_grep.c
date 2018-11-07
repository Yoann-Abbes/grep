/*
** EPITECH PROJECT, 2018
** testgrep
** File description:
** testgrep
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "my.h"
#include <criterion/criterion.h>

void print_error(char*);
void do_search(int, char*, char*, char*);
char *init_buff(char *);
int my_grep(int, char*, char*);
int read_in_standard(char*, int, int, int);
int owned_coverage(int, int);

Test(test, my_grep)
{
    cr_assert(my_grep(2, "grep.c", "read") == 0);
}

Test(testac1, my_grep)
{
    cr_assert(read_in_standard("read", 1, 1, 1) == 84);
}

Test(testacm1, my_grep)
{
    cr_assert(read_in_standard("read", 1, 2, -1) == 84);
}

Test(testac2, my_grep)
{
    cr_assert(owned_coverage(5, -1) == 0);
}

Test(testac3, my_grep)
{
    cr_assert(owned_coverage(-1, 5) == 0);
}

Test(testac4, my_grep)
{
    cr_assert(owned_coverage(0, 3) == 0);
}

Test(testac5, my_grep)
{
    cr_assert(owned_coverage(3, 0) == 0);
}

Test(testno, my_grepno)
{
    int i = 0;

    i = my_grep(2, "gre.c", "read");
    cr_assert(i == 84);
}

Test(testdir, my_grepdir)
{
    int i = 0;
    i = my_grep(4, "../tests", "read");
    cr_assert(i == 84);
}

Test(testmin, my_grepdir)
{
    int i = 0;
    i = my_grep(-1, "../tests", "read");
    cr_assert(i == 84);
}

Test(testdenied, my_grepdir)
{
    int i = 0;
    i = my_grep(2, "/proc/kmsg", "read");
    cr_assert(i == 84);
}

Test(testac4, my_grepdir)
{
    int i = 0;
    i = my_grep(4, "grep.c", "read");
    cr_assert(i == 0);
}

Test(testm, my_grepm)
{
    int i = 84;
    i = my_grep(2, "grep.c", "read");
    i = my_grep(2, "main.c", "read");
    i = my_grep(2, "Makefile", "read");
    cr_assert(i == 0);
}
