/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** strlen
*/

int	my_strlen(char const *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}
