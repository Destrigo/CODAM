/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:28:19 by mtaranti          #+#    #+#             */
/*   Updated: 2025/06/12 18:06:22 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		check(char *base);

int		baseindex(char c, char *base);

int		retrules(int num, int sig);

int		number(char *str, int sig, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sig;
	int	num;

	i = 0;
	sig = 0;
	num = 0;
	if (check(base) == 0)
		write(1, "", 1);
	else
		num = number(str, sig, base);
	return (num);
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
				if ((base[z] == base[i]) || base[i] == 43
					|| base[i] == 45 || base[i] == ' ')
					return (0);
				z++;
			}
			i++;
		}
	}
	return (1);
}

int	number(char *str, int sig, char *base)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (baseindex(str[i], base) != baseindex('\0', base))
			num = (num * baseindex('\0', base)) + baseindex(str[i], base);
		else
			return (retrules(num, sig));
		i++;
	}
	return (retrules(num, sig));
}

int	retrules(int num, int sig)
{
	if ((sig % 2) == 1)
		return (num * -1);
	else
		return (num);
}

int	baseindex(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index] != c && base[index] != '\0')
		index++;
	return (index);
}

// int main(void)
// {
// 	char string[] = "     -+FFaab567";
//  	printf("%i", ft_atoi_base(string, "0123465789ABCDEF"));
// }