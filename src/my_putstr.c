/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** my_putstr
*/

#include <unistd.h>

int	my_strlen(char const*);

void	my_putstr(char const *str)
{
	int i = my_strlen(str);

	write(1, str, i);
}
