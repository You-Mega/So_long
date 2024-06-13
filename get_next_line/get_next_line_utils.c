/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:22:57 by ysouhail          #+#    #+#             */
/*   Updated: 2024/02/24 13:22:57 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_jwan(char *s, char *p)
{
	char	*total;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total = malloc((ft_strlenn(s) + ft_strlenn(p) + 1) * sizeof(char));
	if (!total)
		return (NULL);
	while (s[i])
	{
		total[i] = s[i];
		i++;
	}
	while (p[j])
	{
		total[i + j] = p[j];
		j++;
	}
	total[i + j] = '\0';
	free(s);
	return (total);
}

char	*ft_strjwan(char *s, char *p)
{
	if (!s)
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		s[0] = '\0';
	}
	return (str_jwan(s, p));
}

char	*ft_strchrr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlenn(char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
