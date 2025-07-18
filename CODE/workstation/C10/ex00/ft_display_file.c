/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:58:01 by mtaranti          #+#    #+#             */
/*   Updated: 2025/06/21 18:48:21 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	c[1024];

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	if (argc == 1)
		return (0);
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc > 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		close(fd);
		return (0);
	}
	else
	{
		while (read(fd, &c, 1) != 0)
			write(1, &c, 1);
	}
	close(fd);
	return (0);
}
