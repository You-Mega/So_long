/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:14:08 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/08 22:39:52 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = 0;
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == (char)c)
			str = (char *)(s + i);
		i++;
	}
	return (str);
}
// int main()
// {
// const char *s = "Yousseef souhail";
// char c = 'e';
// char *result = ft_strrchr(s, c);
// printf("%s", result);
// }