/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:28:41 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/09 12:38:36 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	a;
	size_t	b;
	size_t	space_left;

	a = ft_strlen(dst);
	b = ft_strlen(src);
	space_left = dstsize - a - 1;
	x = 0;
	if (a >= dstsize)
		return (b + dstsize);
	while (src[x] != '\0' && x < space_left)
	{
		dst[a + x] = src[x];
		x++;
	}
	dst[a + x] = '\0';
	return (a + b);
}
