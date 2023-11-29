/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:55:53 by rabouzia          #+#    #+#             */
/*   Updated: 2023/11/29 17:35:11 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft.h"

#include <stdarg.h>


int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;
	i = (long long)str;
}

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

void	ft_base_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

int		base_10;
int		uns_int;

char	hex_low(char *str)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);

}

char	hex_up(char *str)
{
	char	*hex;

	hex = "0123456789ABCDEF";
}

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
int	check(va_list args, char c)
{
	if (c == 'c')
		ft_putchar();
	if (c == 's')
		ft_putstr();
	if (c == 'p')
		print_adress();
	if (c == 'd')
		ft_putnbr();
	if (c == 'u')
		uns_int();
	if (c == 'x' || c == 'X' || c == 'i')
		ft_putnbr_base(' ');
	if (c == '%')
		ft_putchar("%%");
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
	while (str[i++])
	{
		if (str[i++] == '%')
			res += check(list, str[i + 1]);
		else
			ft_putchar(str[i]);
			res++;
	}
	va_end(list);
	return (res);
}
