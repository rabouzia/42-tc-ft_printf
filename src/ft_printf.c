/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:55:53 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/03 18:17:08 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"
#include <stdio.h>

int	check(va_list *args, char c)
{
	if (c == 'c') // ok
		ft_putchar(va_arg(*args, int));
	if (c == 's') // ok
		return (print_string(va_arg(*args, char *)));
	if (c == 'p')
		print_adress(va_arg(*args, void *), "0123456789abcdef");
	/*attention a la valeur NULL cas special ,
	print 0x puis le truc en hexa*/
	if (c == 'x')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		ft_putnbr_base(va_arg(*args, int), "0123456789ABCDEF");
	if (c == 'i' || c == 'd')
		ft_putnbr_base(va_arg(*args, int), "0123456789");
	if (c == '%')
		ft_putchar('%');
	if (c == 'u')
		ft_putnbr_base((long)va_arg(*args, unsigned int), "0123456789");
	return (1);
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
			ft_putchar(str[i]);
		res++;
		i++;
	}
	va_end(list);
	return (res);
}
#include <stdio.h>

int	main(void)
{
	int	moi;
	int	p;

	moi = NULL;
	p = &moi;
	ft_printf("adress: %p\n", p);
	printf("adress: %p\n", p);
}
