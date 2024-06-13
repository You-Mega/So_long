/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:14:51 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/09 13:37:36 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == (char)c)
			return ((char *)&s[x]);
		x++;
	}
	if ((char)c == '\0')
		return ((char *)&s[x]);
	return (NULL);
}
// int main()
// {

//     char *p = ft_strchr(NULL,'3');
//     printf("%s", p);
// }