/*
** EPITECH PROJECT, 2017
** lecture
** File description:
** lecture
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

int fs_lines(char *buf, char **av)
{
	int i = 0;
	int line = 0;
	char lines[12];
	int fd = open(av[1], O_RDONLY);

	read(fd, buf, 12);
	while (buf[i] != '\n') {
		lines[i] = buf[i];
		i++;
	}
	lines[i] = '\0';
	line = my_getnbr(lines);
	close(fd);
	return (line);
}

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
	int lines;
	int colms;
	char *tab = NULL;

	if (stats == -1)
		return (84);
	tab = malloc(size.st_size);
	if (tab == NULL)
		return (84);
	lines = fs_lines(buf, av);
	colms = fs_colums(av);
	stock_on_tab(tab, av, &size);
	algo(tab, colms, lines, idx);
	my_putstr(tab);
	free(tab);
	return (0);
}
