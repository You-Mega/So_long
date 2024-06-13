/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:35:32 by ysouhail          #+#    #+#             */
/*   Updated: 2023/12/30 11:45:57 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	x;
	char	*str;

	x = 0;
	str = (char *)malloc((ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
// int main()
// {
//     char *x = "hellow";
//     printf("%s\n",strdup(x));
// 	// if(s1 == NULL)
// 	//     return (NULL);
//     printf("%s\n",ft_strdup(x));
// }