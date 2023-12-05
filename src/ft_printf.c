/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:55:53 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/05 16:23:59 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	check(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c') // ok
		count += ft_putchar(va_arg(*args, int));
	if (c == 's') // ok
		count += ft_putstr(va_arg(*args, char *));
	if (c == 'p')
		count += print_adress((unsigned long long)va_arg(*args, void *),
				"0123456789abcdef");
	if (c == 'x')
		count += ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789abcdef");
	if (c == 'X')
		count += ft_putnbr_base(va_arg(*args, int), "0123456789ABCDEF");
	if (c == 'i' || c == 'd')
		count += print_decimal(va_arg(*args, int));
	if (c == '%')
		ft_putchar('%');
	if (c == 'u')
		count += ft_putnbr_base((long)va_arg(*args, unsigned int),
				"0123456789");
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		res;

	va_start(list, str);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += check(&list, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
		res++;
		}
		i++;
	}
	va_end(list);
	return (res);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
		
	int	ret1, ret2;
	
	ret1 = ft_printf(" %s \n", argv[1]);
	ret2 = printf(" %s \n", argv[1]);

	printf ("ft_printf = %d / printf = %d\n", ret1, ret2);
	return (0);
}

*/