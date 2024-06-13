/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:04:07 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/04 13:14:03 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_isero(int n)
{
	char	*x;

	x = (char *)malloc(2);
	if (x == NULL)
		return (NULL);
	x[n] = '0';
	x[n + 1] = '\0';
	return (x);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*rs;
	long	num;

	num = n;
	count = ft_count(num);
	if (n == 0)
		return (ft_isero(n));
	rs = (char *)malloc((count + 1) * sizeof(char));
	if (rs == NULL)
		return (NULL);
	rs[count] = '\0';
	while ((count > 0) && num != 0)
	{
		if (num < 0)
		{
			rs[0] = '-';
			num = -num;
		}
		count--;
		rs[count] = (num % 10) + '0';
		num /= 10;
	}
	return (rs);
}
