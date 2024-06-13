/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:02:21 by ysouhail          #+#    #+#             */
/*   Updated: 2024/05/31 22:49:51 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_count(char *s, char x)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == x)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != x)
				i++;
		}
	}
	return (count);
}

void	ft_freez(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_fill(char **result, char *s, char x, int y)
{
	int		i;
	int		j;
	int		global;
	char	*tmp;

	i = 0;
	global = 0;
	while (s[i] && global < y)
	{
		while (s[i] && s[i] == x)
			i++;
		j = i;
		while (s[i] && s[i] != x)
			i++;
		tmp = ft_substr(s, j, i - j);
		if (!tmp)
		{
			result[global] = NULL;
			ft_freez(result);
			return (NULL);
		}
		result[global++] = tmp;
	}
	result[global] = NULL;
	return (result);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	if (count == 0)
		exit(write(2, "Error\n", 6));
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	result = ft_fill(result, s, c, count);
	if (!result)
		return (NULL);
	return (result);
}
