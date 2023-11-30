/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:55:53 by rabouzia          #+#    #+#             */
/*   Updated: 2023/11/30 15:32:31 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft.h"

#include <stdarg.h>
#include <unistd.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
/*
int	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
	return (1);
}

//int		uns_int;

int	search_flag(const char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		if (str[i] == "%%")
			i++;
	}
}
*/
int	print_string(const char *s)
{
	ft_putstr(s);
	return (ft_strlen(s));
}

int	check(va_list *args, char c)
{
	if (c == 'c') // ok
		ft_putchar(va_arg(*args, int));
	if (c == 's') // ok
		return (print_string(va_arg(*args, char *)));
	// if (c == 'p')
	//	print_adress();
	// if (c == 'd')
	// ft_putnbr();
	// if (c == 'u')
	//	uns_int();
	// if (c == 'x' || c == 'X' || c == 'i')
	//	ft_putnbr_base(' ');
	// if (c == '%')
	// ft_putchar("%%");
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
	char moi = 'R';
	ft_printf("Je m'appelle %c", moi);
	// printf("Je m'appelle %c", moi);
}