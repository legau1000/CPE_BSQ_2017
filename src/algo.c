/*
** EPITECH PROJECT, 2017
** algo
** File description:
** algo
*/

#include <stdio.h>
#include "my.h"

void init_val(s_rect *rect1, s_rect *rect2, int idx)
{
	rect1->value = 1;
	rect2->value = 1;
	rect1->x = idx;
	rect2->x = idx;
	rect1->y = 0;
	rect2->y = 0;
}

int search_rect_size(s_rect *rect, int colms, char *tab, int *index)
{
	rect->x = 0;
	rect->value = 0;
	int x = *index;
	int y = *index;
	int x2 = x;
	int y2 = y;
	int i = 0;
	int detect = 0;
	int nb_boucle = 0;

	while(tab[x2] && tab[y2] && detect == 0) {
		i++;
		x++;
		y = y + colms;
		x2 = x;
		y2 = y;
		while (tab[x2] && nb_boucle <= i && detect == 0) {
			nb_boucle++;
			if (tab[x2] != '.')
				detect++;
			x2 = x2 + colms;
		}
		nb_boucle = 0;
		while (tab[y2] && nb_boucle <= i && detect == 0) {
			nb_boucle++;
			if (tab[y2] != '.')
				detect++;
			y2 = y2 + 1;
		}
		nb_boucle = 0;
	}
	i--;
	rect->value = i;
	rect->x = *index;
}

void print_x(char *tab, s_rect *rect, int colms)
{
	int x = 0;
	int y = 0;
	int s_x = rect->x;

	while (y <= rect->value) {
		while (x <= rect->value) {
			tab[rect->x] = 'x';
			rect->x++;
			x++;
		}
		rect->x = rect->x + colms - rect->value - 1;
		x = 0;
		y++;
	}
}

void search_more_biggest(s_rect *rect1,s_rect *rect2, int colms, char *tab)
{
	int index = rect1->x;
	int value = 0;

	while (tab[index]) {
		if (tab[index] == '.') {
			search_rect_size(rect2, colms, tab, &index);
			if (rect2->value > rect1->value) {
				rect1->value = rect2->value;
				rect1->x = rect2->x;
			}
		}
		index++;
	}
	if (rect1->value >= rect2->value)
		print_x(tab, rect1, colms);
	else
		print_x(tab, rect2, colms);
}

void algo(char *tab, int colms, int lines, int idx)
{
	s_rect rect1;
	s_rect rect2;

	init_val(&rect1, &rect2, idx);
	search_more_biggest(&rect1, &rect2, colms, tab);
}
