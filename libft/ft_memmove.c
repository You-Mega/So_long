/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:42:16 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/06 12:59:43 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*x;
	char	*y;
	size_t	i;

	i = len;
	x = (char *)dst;
	y = (char *)src;
	if (dst > src)
		while (i--)
			x[i] = y[i];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
