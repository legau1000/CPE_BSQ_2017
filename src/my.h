/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef __DEF_H__
#define __DEF_H__

#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct t_rect
{
	int value;
	int x;
	int y;
}s_rect;

int my_getnbr(char*);
void algo(char *tab, int colms, int lines, int idx);
void stock_on_tab(char *tab, char **av, struct stat *size);

#endif
