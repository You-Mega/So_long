/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:23:52 by ysouhail          #+#    #+#             */
/*   Updated: 2023/12/23 19:31:51 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (x > i && ft_strchr(set, s1[x - 1]))
		x--;
	return (ft_substr(s1, i, x - i));
}
// int main()
// {
//     char x[] = "owhellw";
//     char set[] = "ow";
//     printf("%s",ft_strtrim(x ,set));
// }
//     char *x;
//     while (i < ft_strlen(s1))
//     {
//         if(s1[i] == set[j])
//             j++;
//         else{
//             x[i] = s1[i];
//         }
//         i++;
//     }
//     size_t b = ft_strlen(s1);
//     while(b > 0)
//     {
//         if(s1[i] == set[j])
//             j++;
//         else{
//             x[i] = s1[i];
//         }
//         i++;
//     }
//     x[i] = '\0';
//     x = (char *)malloc((ft_strlen(s1) + 1));
//     return (x);
// }
