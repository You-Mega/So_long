/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:41:07 by ysouhail          #+#    #+#             */
/*   Updated: 2023/12/30 11:19:50 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rs;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s);
	i = 0;
	rs = (char *)malloc(sizeof(char) * (len + 1));
	if (rs == NULL)
		return (NULL);
	while (i < len)
	{
		rs[i] = f(i, s[i]);
		i++;
	}
	rs[i] = '\0';
	return (rs);
}
// char function (unsigned int i, char s)
// {
//     i = 0;
//     if(s >= 'a' && s <= 'z')
//         s -= 32;
//     else if(s >= 'A' && s <= 'Z')
//         s += 32;
//     return (s);
// }
// int main()
// {
//     char s[] = "EeeQWlloYUFTF";
//     char *p = ft_strmapi(s, function);
//     printf("%s", p);
// }