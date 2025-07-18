/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:58:01 by mtaranti          #+#    #+#             */
/*   Updated: 2025/06/22 20:30:34 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int	func(int argc, int i, char **argv);

void	ft_putstr(char *str);

int	main(int argc, char *argv[])
{
	char	c;
	int		i;

	c = 0;
	i = 1;
	if (argc == 1)
	{
		while (c != 3)
		{
			read(0, &c, 1);
			write(1, &c, 1);
		}
		return (0);
	}

	func(argc, i, argv);
	return (0);
}

int	func(int argc, int i, char **argv)
{
	char	c[1024];
	int	fd;

	while (argc >= 2 && i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(2, "Error: ", 7);
			ft_putstr(strerror(errno));
			write(2, "\n", 1);
			close(fd);
			return (0);
		}
		else
		{
			while (read(fd, &c, 1) != 0)
				write(1, &c, 1);
		}
		close(fd);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
		str++;
	}
}