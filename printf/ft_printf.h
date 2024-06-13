/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:01:56 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/25 10:39:02 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putnbr(int num);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_puthexa(unsigned long x, char *ab);
int	ft_putptr(void *ptr);
int	ft_putunsigned(unsigned int num);
#endif