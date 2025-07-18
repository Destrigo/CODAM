/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:28:22 by mtaranti          #+#    #+#             */
/*   Updated: 2025/06/12 14:34:32 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		check(char *base);

void	hellyeahw(long int nbrchanged, char *base, int z);

int		ft_strlen(char *str);

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nbrchanged;
	int			z;

	z = 0;
	nbrchanged = (long int)nbr;
	if (check(base) == 0)
		write(1, "", 1);
	else
		hellyeahw(nbrchanged, base, z);
}

int	check(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base [1] == '\0')
		return (0);
	else
	{
		while (base[i] != '\0')
		{
			z = i + 1;
			while (base[z] != '\0')
			{
				if ((base[z] == base[i]) || base[i] == 43 || base[i] == 45)
					return (0);
				z++;
			}
			i++;
		}
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

void	hellyeahw(long int nbrchanged, char *base, int z)
{
	char	buffer[32];
	int		div;
	int		rest;

	div = 0;
	rest = 0;
	if (nbrchanged < 0)
	{
		nbrchanged = nbrchanged * -1;
		write (1, "-", 1);
	}
	while (nbrchanged > (ft_strlen(base) - 1))
	{
		div = nbrchanged / ft_strlen(base);
		buffer[z] = base[(nbrchanged % ft_strlen(base))];
		nbrchanged = div;
		z++;
	}
	rest = nbrchanged % 10;
	buffer[z] = base[(nbrchanged % ft_strlen(base))];
	while (z >= 0)
	{
		write(1, &buffer[z], 1);
		z--;
	}
}

// int main(void)
// {
// 	ft_putnbr_base(2147483647, "0132456789ABCDEF");
// }
