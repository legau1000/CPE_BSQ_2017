/*
** EPITECH PROJECT, 2017
** lecture
** File description:
** lecture
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

int fs_colums(char **av)
{
	int x = 0;
	int size = 1;
	char buff[2];
	int fd = open(av[1], O_RDONLY);

	buff[0] = 0;
	buff[1] = '\0';
	while (size != 0 && buff[0] != '\n') {
		size = read(fd, buff, 1);
	}
	buff[0] = 0;
	while (buff[0] != '\n' && size != 0) {
		size = read(fd, buff, 1);
		x++;
	}
	close(fd);
	return (x);
}

int main(int ac, char **av)
{
	struct stat size;
	int stats = stat(av[1], &size);
	int idx = 0;
	char buf[12];
	int colms;
	char *tab = malloc(size.st_size);

	if (stats == -1)
		return (84);
	colms = fs_colums(av);
	stock_on_tab(tab, av, &size);
	algo(tab, colms, idx);
	my_putstr(tab);
	free(tab);
	return (0);
}
