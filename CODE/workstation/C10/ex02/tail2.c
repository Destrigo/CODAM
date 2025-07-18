/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:23:22 by mtaranti          #+#    #+#             */
/*   Updated: 2025/06/22 15:44:22 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft.h"

void	func(int argc, int i, char **argv, char *arr);
void	secondelse(int sizearr, char *arr, int fd);
int		countbytes(char *arr, int sizearr);
int getnumber(int argc, int i, char **argv);
int checkc (int argc, char **argv);
int checknextc(int argc, char **argv);
void funcbytes(int argc, int i, char **argv, char *arr);
void	secondelseagain(int sizearr, char *arr, int fd, int z);

int	countbytes(char *arr, int sizearr)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (counter != 9 && sizearr >= 0)
	{
		if (arr[sizearr] == '\n')
			counter++;
		sizearr--;
		i++;
	}
	return (i);
}

int checkc(int argc, char **argv)
{
	int i;

	i = 0;
	while (argc > 1)
	{
		i = 0;
		argc--;
		while (argv[argc][i] == 32)
			i++;
		if (argv[argc][i] == '-' && argv[argc][i + 1] == 'c')
		{
			i = i + 2;
			while (argv[argc][i] == 32)
				i++;
			if (argv[argc][i] >= '0' && argv[argc][i] <= '9')
				return (getnumber(argc, i, argv));
			else if (argv[argc][i] == '\0')
				return (-5);
			else
			{
				write(0, "tail: invalid number of bytes: ‘", 30);
				while (argv[argc][i] != '\0')
				{
					write(0, &argv[argc][i], 1);
					i++;
				}
				write(0, "'", 1);
				return (-2);
			}
		}
	}
	return (-1);
}

int checknextc(int argc, char **argv)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (argc > 1)
	{
		i = 0;
		argc--;
		while (argv[argc][i] == 32)
			i++;
		if (argv[argc][i] == '-' && argv[argc][i + 1] == 'c')
		{
			num = getnumber(argc + 1, i, argv);
			if (num < 0)
			{
				write(0, "tail: invalid number of bytes: ‘", 30);
				while (argv[argc][i] != '\0')
				{
					write(0, &argv[argc][i], 1);
					i++;
				}
				write(0, "'", 1);
			}
		return (num);
		}
	}
	return (num);
}

//atoi
int getnumber(int argc, int i, char **argv)
{
	int num;

	num = -1;
	while (argv[argc][i] == 32)
		i++;
	if (argv[argc][i] >= '0' && argv[argc][i] <= '9')
		num = 0;
	while (argv[argc][i] >= '0' && argv[argc][i] <= '9')
	{
		num = (num * 10) + (argv[argc][i] - '0');
		i++;
	}
	return (num);
}

// gets last 10 lines
void	func(int argc, int i, char **argv, char *arr)
{
	char	c;
	int		fd;
	int		sizearr;
	int		z;

	z = 0;
	while (argc >= 2 && i < argc)
	{
		sizearr = 0;
		fd = open(argv[i], O_RDONLY);
		while (read(fd, &c, 1) != 0)
			sizearr++;
		close(fd);
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(2, "Cannot read file.\n", 18);
			close(fd);
			return ;
		}
		else
			secondelse(sizearr, arr, fd);
		close(fd);
		i++;
	}
}

// for second else of function "func"
void	secondelse(int sizearr, char *arr, int fd)
{
	int	z;

	z = 0;
	arr = malloc(sizeof(char) * (sizearr + 1));
	while (read(fd, &arr[z], 1) != 0)
		z++;
	z = 1;
	while (z < countbytes(arr, sizearr))
	{
		write (1, &arr[(sizearr - countbytes(arr, sizearr) + z)], 1);
		z++;
	}
	free(arr);
}

void funcbytes(int argc, int i, char **argv, char *arr)
{
	char	c;
	int		fd;
	int		sizearr;
	int		z;

	z = 0;
	while (argc >= 2 && i < argc)
	{
		sizearr = 0;
		fd = open(argv[i], O_RDONLY);
		while (read(fd, &c, 1) != 0)
			sizearr++;
		close(fd);
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(2, "Cannot read file.\n", 18);
			close(fd);
			return ;
		}
		else
			z = checknextc(argc, argv);
			secondelseagain(sizearr, arr, fd, z);
		close(fd);
		i++;
	}
}

// for second else of function "funcbytes"
void	secondelseagain(int sizearr, char *arr, int fd, int c)
{
	int	z;

	z = 0;
	arr = malloc(sizeof(char) * (sizearr + 1));
	while (read(fd, &arr[z], 1) != 0)
		z++;
	z = 1;
	while (z < (sizearr - c))
	{
		write (1, &arr[(sizearr - (sizearr - c) + z)], 1);
		z++;
	}
	free(arr);
}
