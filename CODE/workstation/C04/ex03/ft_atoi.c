/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:05:47 by mtaranti          #+#    #+#             */
/*   Updated: 2025/06/12 14:58:52 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	number(char *str, int i, int num, int sig);

int	ft_atoi(char *str)
{
	int	i;
	int	sig;
	int	num;

	i = 0;
	sig = 0;
	num = 0;
	return (number(str, i, num, sig));
}

// int main(void)
// {
// 	char string[] = "     -2147483648ab567";
//  	printf("%i", ft_atoi(string));
// }

int	number(char *str, int i, int num, int sig)
{
	while (str[i] == 32)
		i++;
	if ((str[i] >= 65 && str[i] <= 90)
		|| (str[i] >= 97 && str[i] <= 122))
		return (0);
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sig++;
		i++;
	}
	if ((str[i] >= 65 && str[i] <= 90)
		|| (str[i] >= 97 && str[i] <= 122))
		return (0);
	while ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if ((sig % 2) == 1)
		return (num * -1);
	else
		return (num);
}
