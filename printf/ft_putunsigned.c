/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
		+:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+
		+#+        */
/*                                                +#+#+#+#+#+
		+#+           */
/*   Created: 2024/01/24 23:05:49 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/24 23:05:49 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int num)
{
	int	x;

	x = 0;
	if (num > 9)
		x += ft_putunsigned((num / 10));
	x += ft_putchar(('0' + num % 10));
	return (x);
}
