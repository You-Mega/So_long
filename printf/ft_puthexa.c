/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:28:18 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/24 23:24:40 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long num, char *ab)
{
	int	count;

	count = 0;
	if (num >= 16)
		count += ft_puthexa(num / 16, ab);
	write(1, &ab[num % 16], 1);
	count++;
	return (count);
}

// int ft_puthexa(int x, char *ab)
// {
// int count = 0;
// if(x < 0)
// {
// 	unsigned int num = (unsigned int)x;
// 	if (num >= 16)
// 		count += ft_puthexa(num / 16, ab);
// 	count++;
// 	write(1, &ab[num % 16], 1);
// }
// while(x > 0)
// {
// 	write(1, &ab[x % 16], 1);
// 	count++;
// 	x /= 16;
// }
// return (count);
// }
