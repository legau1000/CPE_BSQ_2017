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
	int ind_x = *index;
	int ind_y = *index + colms - 1;
	int ind_x2 = ind_x;
	int ind_y2 = ind_y;
	int nb_boucle = 0;
	int nb_x = 0;
	int nb_y = 0;
	int d = 0;
	int i = 0;

	while (d == 0) {
		i++;
		ind_x++;
		ind_y++;
		ind_x2 = ind_x;
		ind_y2 = ind_y;
		while (nb_boucle != i) {
			if (tab[ind_x2] != '.')
				d++;
			ind_x2 = ind_x2 + colms;
			nb_boucle++;
		}
		nb_boucle = 0;
		while (nb_boucle != i) {
			if (tab[ind_y2] != '.')
				d++;
			ind_y2 = ind_y2 + 1;
			nb_boucle++;
		}
		nb_boucle = 0;
	}
	printf("%d\n", *index);
	if (i >= rect->value) {
		rect->value = i;
		rect->x = *index;
	}
	*index = *index + i;
}

void print_x(char *tab, s_rect *rect, int colms)
{
	int x = 0;
	int y = 0;
	int s_x = rect->x;

	printf("%d\n", rect->x);
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
		if (tab[index] == '\n')
			index++;
		if (tab[index] == '.') {
			if (rect1->value > rect2->value)
				search_rect_size(rect2, colms, tab, &index);
			else
				search_rect_size(rect1, colms, tab, &index);				
		}
		printf("rect1 %d\n", rect1->value);
		printf("rect2 %d\n", rect2->value);
		printf("rect1x %d\n", rect1->x);
		printf("rect2x %d\n", rect2->x);
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
