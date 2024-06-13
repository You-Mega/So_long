/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 05:48:30 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/24 23:31:52 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int	x;

	x = 0;
	if (num == -2147483648)
	{
		x += ft_putnbr((num / 10));
		x += ft_putchar('8');
	}
	else if (num < 0)
	{
		x += ft_putchar('-');
		x += ft_putnbr(-num);
	}
	else
	{
		if (num > 9)
			x += ft_putnbr((num / 10));
		x += ft_putchar(('0' + num % 10));
	}
	return (x);
}
