/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:47:00 by ramzerk           #+#    #+#             */
/*   Updated: 2023/12/05 18:14:56 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

int	ft_putnbr_base(long nbr, char *base)
{
	if (nbr < 0)
		return (ft_putchar('-') + ft_putnbr_base_unsigned(-nbr, base));
	return (ft_putnbr_base_unsigned(nbr, base));
}

long	ft_putnbr(int nb)
{
	long	nbr;
	long	i;

	nbr = nb;
	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
		i++;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
		i++;
	}
	return (i);
}
