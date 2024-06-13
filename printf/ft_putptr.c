/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/01/24 20:24:58 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/24 20:24:58 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	cn;

	cn = 0;
	cn += ft_putstr("0x");
	cn += ft_puthexa((unsigned long long)ptr, "0123456789abcdef");
	return (cn);
}
