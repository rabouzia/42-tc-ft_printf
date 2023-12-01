/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:47:00 by ramzerk           #+#    #+#             */
/*   Updated: 2023/12/01 18:38:31 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

unsigned int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13)
			|| base[i] == ' ')
			return (0);
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

long	ft_putnbr_base(long nbr, char *base)
{
	long	a;
	long	i;

	i = 0;
	if (!is_valid_base(base))
		return (-12);
	a = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
		i++;
	}
	if (nbr >= a)
	{
		ft_putnbr_base(nbr / a, base);
		ft_putnbr_base(nbr % a, base);
	}
	else
	{
		ft_putchar(base[nbr]);
		i++;
	}
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}