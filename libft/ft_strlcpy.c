/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:45:59 by ysouhail          #+#    #+#             */
/*   Updated: 2023/12/23 16:25:55 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	len;

	len = ft_strlen(src);
	x = 0;
	if (src == NULL)
		return (0);
	if (dstsize == 0)
		return (len);
	while (src[x] != '\0' && x < dstsize - 1)
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (ft_strlen(src));
}
// cpy x f y if y fiha chi 7aja ktmsa7e
// int main()
// {
//     char *src = "hello";
//     char dest[5] = "hhhh";
//     ft_strlcpy(dest, src, 5);
//     printf("Before ft_strlcpy: %s\n", dest);
//     printf("Copied characters count: %zu\n", ft_strlcpy(dest, src, 9));
// }

// int main()
// {
//     char s[]= "hello";
//     char d[5]= "hhhh";
//     int x;
//     x = strlcpy(d,s,5);
//     printf("%d\n",x);
//     printf("%s",d);

//     return(0);
// }