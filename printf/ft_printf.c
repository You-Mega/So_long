/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:06:05 by ysouhail          #+#    #+#             */
/*   Updated: 2024/01/24 23:30:22 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ar, char r)
{
	int	cn;

	cn = 0;
	if (r == 'c')
		cn += ft_putchar(va_arg(ar, int));
	else if (r == 's')
		cn += ft_putstr(va_arg(ar, char *));
	else if (r == 'p')
		cn += ft_putptr(va_arg(ar, void *));
	else if (r == 'i' || r == 'd')
		cn += ft_putnbr(va_arg(ar, int));
	else if (r == 'u')
		cn += ft_putunsigned(va_arg(ar, unsigned int));
	else if (r == 'x' || r == 'X')
	{
		if (r == 'x')
			cn += ft_puthexa(va_arg(ar, unsigned int), "0123456789abcdef");
		else
			cn += ft_puthexa(va_arg(ar, unsigned int), "0123456789ABCDEF");
	}
	else if (r == '%')
		cn += ft_putchar(r);
	return (cn);
}

int	ft_printf(char const *str, ...)
{
	va_list	ar;
	int		cn;

	if (!str)
		return (0);
	if (*str == '%' && (*(str + 1) == '\0'))
		return (0);
	if ((write (1, 0, 0) == -1))
		return (-1);
	cn = 0;
	va_start(ar, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			cn += ft_format(ar, *str);
		}
		else
			cn += ft_putchar(*str);
		str++;
	}
	va_end(ar);
	return (cn);
}
//  int main()
// {
//     int i;
//     i = printf("%fiuvi");
//     printf("\n%d", i);
//     // printf("\n%u",-1);
// }
// int main()
// {
//     ft_printf("%x",512);
// }
// int main()
// {
// ft_printf("%x",-33775757645651651651);
// printf("\n%x",-33775757645651651651);
// int x = -2;
// int *ptr = &x;
// ft_printf("%p\n", ptr);
// printf("%p\n", ptr);
// int x = ft_printf("%s %% hellow , %d, %x 'a'\n", "347859138",121, -44);
// printf("\n%d\n",x);
// printf("%d",printf("%s %% hellow , %d, %x 'a'\n", "347859138",121, -44));
// // printf("%d",y);
// }

// int main()
// {
// int x = -34;
// ft_printf("%x",4294967262);
// int i = ft_printf("%x\n", -1);
// printf("%d", i);
// int x = ft_printf("%s %% hellow , %d, %x 'a'\n", "347859138",121, -44);
// printf("%d",x);
// int y = printf("%s", NULL);
// printf("\n%i \n%d",x,y);
// }