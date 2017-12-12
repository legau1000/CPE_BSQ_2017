/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef __DEF_H__
#define __DEF_H__

typedef struct t_rect
{
	int value;
	int x;
	int y;
}s_rect;

int my_getnbr(char*);
void algo(char *tab, int colms, int lines, int idx);

#endif
