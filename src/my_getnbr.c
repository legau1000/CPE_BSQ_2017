/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_getnbr
*/

int	my_getnbr(char const *str)
{
	int	i = 0;
	int	neg = 1;
	int	nb = 0;

	while (str[i]) {
		while (str[i] == '-' || str[i] == '+') {
			if (str[i] == '-')
				neg = -neg;
			i++;
		}
		while ('0' <= str[i] && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + (str[i] - '0');
			i++;
		}
		nb = nb * neg;
		if (str[i] > '0' || str[i] > '9')
			return (nb);
	}
	return (nb);
}
