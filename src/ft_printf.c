/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:55:53 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/02 17:16:21 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char *str, int index, int len)
{
	char	*res;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (index > ft_strlen(str))
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (str[index] && len--)
		res[i++] = str[index++];
	res[i] = 0;
	return (res);
}

int	simple_flag(va_list *arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*arg, char)));
	if (c == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	if (c == 'p')
		return (0);
	if (c == 'd')
		return (0);
	if (c == 'i')
		return (0);
	if (c == 'u')
		return (0);
	if (c == 'x')
		return (0);
	if (c == 'X')
		return (0);
	if (c == 'f')
		return (0);
	if (c == 'o')
		return (0);
	if (c == '%')
		return (2);
}

int	read_flag(va_list *arg, int i, char *str)
{
	i++;
	if (strchr("cspdiuxX", str[i + 1]))
		return (simple_flag(arg, str[i + 1]));
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_read(char *str)
{
	"% 10d" if ()
}

int	ft_putnbr_base2(int nbr, char *base)
{
	int	a;

	ft_strlen(base);
	if (nbr > 9)
	{
		ft_putnbr_base2(nbr / a, base);
		ft_putnbr_base2(nbr % a, base);
	}
	else
		ft_putchar(base[nbr]);
	return (1);
}

int	checker(va_list *arg, char *str)
{
	int	i;
	int	a;
	int	len;

	a = 0;
	i = 0;
	while (str[len])
		len++;
	while (str[i++] != '%')
		ft_putchar(str[i]);
	while (str[i])
	{
		if (str[i] == '%')
			i += read_flag(arg, i, str);
		else if (ft_strchr(END, str[i + 1]))
			return (simple_flag(arg, str[i + 1]));
		if (ft_strchr(FLAGS, str[i + 1]))
		{
			while (ft_strchr(END, str[i]) == 0)
			{
				a++;
				i++;
			}
			ft_read(ft_substr(str, i, a));
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		value;

	value = 0;
	value += checker(&arg, str);
	va_start(arg, str);
	va_end(arg);
}

int	main(void)
{
	ft_printf("% 1ad\n", 32);
	printf("%010d\n", 32);
	printf("% 010d\n", 32);
	printf("% 14d\n", 32);
	printf("%-010d", 123);
	printf("%010d", 123);
	printf("%-10.2f", 123.45);
	printf("%010.2f", 123.45);
	printf("%-10s", "abc");
	printf("%010s", "abc");
	printf("%.3s", "abcdef");
	printf("%10.3d", 123);
	printf("%-10.3d", 123);
}