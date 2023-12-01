/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:44:24 by ramzerk           #+#    #+#             */
/*   Updated: 2023/12/01 16:25:28 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		ft_putchar(str[i]);
}

int get_len(int n)
{
    int i;

    i = 0;
    if (n < 0)
    {
        i++;
        n *= -1;
    }
    while (n == 0)
        return 1;
    while(n > 0)
    {
        n/=10;
        i++;
    }
    return (i);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(const char *s)
{
	ft_putstr(s);
	return (ft_strlen(s));
}
