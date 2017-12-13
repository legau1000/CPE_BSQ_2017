/*
** EPITECH PROJECT, 2017
** stock
** File description:
** stock
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

void stock_on_tab(char *tab, char **av, struct stat *size)
{
	int fd = open(av[1], O_RDONLY);
	char buff[2];
	int i = 0;

	buff[0] = 0;
	buff[1] = '\0';
	while (buff[0] != '\n') {
		read(fd, buff, 1);
		buff[1] = '\0';
		i++;
	}
	read(fd, tab, size->st_size - i);
	tab[size->st_size- i] = '\0';
	close(fd);
}
