/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:33:32 by mtaranti          #+#    #+#             */
/*   Updated: 2025/06/17 19:39:53 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	didit(int rest, int nb);

void	ft_putnbr(int nb)
{
	int		rest;

	rest = 0;
	if (nb >= 0)
		didit(rest, nb);
	else
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		else
		{
			nb = nb *(-1);
			didit(rest, nb);
		}
	}
}

void	didit(int rest, int nb)
{
	char	buff[25];
	int		div;
	int		z;

	z = 0;
	div = 0;
	while (nb > 9)
	{
		div = nb / 10;
		rest = nb % 10;
		nb = div;
		buff[z] = rest + '0';
		z++;
	}
	rest = nb % 10;
	buff[z] = rest + '0';
	while (z >= 0)
	{
		write(1, &buff[z], 1);
		z--;
	}
}

// int main()
// {
// 	ft_putnbr(-214783648);
// }
