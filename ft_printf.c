/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:55:53 by rabouzia          #+#    #+#             */
/*   Updated: 2023/11/27 11:52:20 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

int	check(const char c, int i)
{
	if (c == 'c')
		ft_putchar();
	if (c == 's')
		ft_putstr();
	if (c == 'p')
		print_adress();
	if (c == 'd')
		ft_putnbr();
	if (c == 'i')
		base_10();
	if (c == 'u')
		uns_int();
	if (c == 'x')
		hex_low();
	if (c == 'X')
		hex_up();
	if (c == '%')
		ft_putchar("%%");
    if (c == '-0')
        ???;
    if ( c == '# +')
        ???;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	print_adress;

void	ft_putnbr(int nb)
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
}
int		base_10;
int		uns_int;

char	hex_low;

char	hex_up;

int	search_flag(const char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		if (str[i] == "%%")
		{
			i + 1;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list va_arg;
    int i;
	
    i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			check(str, &i);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
