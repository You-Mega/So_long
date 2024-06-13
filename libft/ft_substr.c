/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:09:50 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/07 17:44:43 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;
	size_t	size_to_allocate;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) > len)
		size_to_allocate = len;
	else
		size_to_allocate = ft_strlen(s + start);
	x = malloc((size_to_allocate + 1) * sizeof(char));
	if (x == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		x[i] = s[start];
		i++;
		start++;
	}
	x[i] = '\0';
	return (x);
}
