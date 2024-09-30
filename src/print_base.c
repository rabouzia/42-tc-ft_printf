/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:47:00 by ramzerk           #+#    #+#             */
/*   Updated: 2024/09/30 23:40:26 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_putnbr_base_unsigned(unsigned long nbr, char *base)
{
	unsigned long	a;
	unsigned long	i;

	i = 0;
	a = ft_strlen(base);
	if (nbr >= a)
	{
		i += ft_putnbr_base_unsigned(nbr / a, base);
		i += ft_putnbr_base_unsigned(nbr % a, base);
	}
	else
	{
		ft_putchar(base[nbr]);
		i++;
	}
	return (i);
}

int	print_decimal(int a)
{
	return (ft_putnbr_base(a, dec));
}

int	ft_putnbr_base(long nbr, char *base)
{
	if (nbr < 0)
		return (ft_putchar('-') + ft_putnbr_base_unsigned(-nbr, base));
	return (ft_putnbr_base_unsigned(nbr, base));
}

int	print_address(unsigned long a, char *s)
{
	if (a == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putnbr_base_unsigned(a, s));
}
