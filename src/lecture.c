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

void my_putstr(char const *str);

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

int fs_colums(char *buf, char **av)
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

void mal_all(char **tab, int y, int x)
{
	int i = 0;

	while (i != x) {
		tab[i] = malloc(sizeof(char) * y);
		printf("%d\n", i);
		i++;
	}
	tab[i - 1] = NULL;
}

void fre_all(char **tab, int x)
{
	int i = 0;

	while (i != x + 1) {
		printf("%d\n", i);
		free(tab[i]);
		i = i + 1;
	}
}

int main(int ac, char **av)
{
	int idx = 0;
	char buf[12];
	int lines = fs_lines(buf, av);
	int colms = fs_colums(buf, av);
	struct stat size;
	int stats = stat(av[1], &size);
	char *tab = malloc(size.st_size);

	int fd = open(av[1], O_RDONLY);
	read(fd, tab, size.st_size - 1);
	while(tab[idx] != '\n')
		idx = idx + 1;
	idx++;
	algo(tab, colms, lines, idx);
	printf("\n");
	printf("\n");
	while (tab[idx]) {
		printf("%c", tab[idx]);
		idx++;
	}
	printf("\n");
	free(tab);
	return (0);
}
