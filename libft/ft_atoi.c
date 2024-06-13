/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:29:45 by ysouhail          #+#    #+#             */
/*   Updated: 2024/05/31 22:52:20 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int				x;
	int				sign;
	long			r;

	x = 0;
	sign = 1;
	r = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sign *= (-1);
		x++;
	}
	else if (str[x] && ft_isdigit(str[x]) == 0)
		exit (write (2, "Error\n", 6));
	while (str[x] >= '0' && str[x] <= '9')
		r = r * 10 + (str[x++] - '0');
	if (str[x] && ft_isdigit(str[x]) == 0)
		exit(write(2, "Error\n", 6));
	r = r * sign;
	if (r > INT_MAX || r < INT_MIN)
		exit (write (2, "Error\n", 6));
	return (r);
}
