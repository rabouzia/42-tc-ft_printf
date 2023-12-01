/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:47:00 by ramzerk           #+#    #+#             */
/*   Updated: 2023/12/01 10:08:36 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	is_valid_base(char *base)
{
    int i;
    int j;

    if (ft_strlen(base) < 2)
        return 0;
    i = 0;
    while (base[i++])
    {
        if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
            return 0;
        j = i + 1;
        while (base[j++])
        {
            if (base[i] == base[j])
                return 0;
        }
    }
    return 1;
}

int ft_putnbr_base(int nbr, char *base)
{
    long a;
    int i;

    i = 0;
    if (!is_valid_base(base))
        return;
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
    return(i);
}

int	ft_putnbr(int nb)
{
	long	nbr;
    int i;
    
    i = 0;
	nbr = nb;
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