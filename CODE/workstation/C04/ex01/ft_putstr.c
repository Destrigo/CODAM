/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:41:59 by mtaranti          #+#    #+#             */
/*   Updated: 2025/06/12 18:05:16 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int		i;
	char	l;

	i = 0;
	while (str[i] != '\0')
	{
		l = str[i];
		write(1, &l, 1);
		i++;
	}
}

// int main(void)
// {
// 	char* string;
//  	string = "abc 123";
//  	ft_putstr(string);
// }