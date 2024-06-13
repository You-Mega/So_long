/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:03:00 by ysouhail          #+#    #+#             */
/*   Updated: 2024/06/12 13:44:24 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	size_t	n;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	n = ft_strlen(s1) + ft_strlen(s2);
	x = malloc((n + 1));
	if (x == NULL)
		return (NULL);
	ft_strlcpy(x, s1, ft_strlen(s1) + 1);
	ft_strlcat(x, s2, n + 1);
	free((char *)s1);
	return (x);
}
// int main()
// {
//     char x[] = "hello";
//     char *y = "hew";
//     printf("%s", ft_strjoin(x , y));
// }
// while(j < ft_strlen(s2))
// {
//     x[i + j] = s2[j];
//     j++;
// }
// while(i < ft_strlen(s1))
// {
//     x[i + j] = s1[i];
//     i++;
// }