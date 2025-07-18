/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:49:09 by mtaranti          #+#    #+#             */
/*   Updated: 2025/06/22 15:41:20 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft.h"

int	main(int argc, char *argv[])
{
	char	c;
	char	*arr;

	c = 0;
	arr = "";
	if (argc == 1)
		while (c != 3)
			read(0, &c, 1);
	if (argc == 1)
		return (0);
	
	if (checkc(argc, argv) == -1)
	{
		func(argc, 1, argv, arr);
		return (0);
	}
	if (checkc(argc, argv) == -5) // found -c but number is another argument
	{
		if (checknextc(argc, argv) >= 0)
		{
			funcbytes(argc, 1, argv, arr);
			return (0);
		}	
		else
			return (0);
	}
	if (checkc(argc, argv) == -2) // found -c but number of bytes is incorrect 
		return (0);
	
	return (0);
}
