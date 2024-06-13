/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:26:18 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/08 14:03:18 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*smtp;

	smtp = malloc(count * size);
	if (smtp == NULL)
		return (NULL);
	ft_bzero(smtp, count * size);
	return (smtp);
}
