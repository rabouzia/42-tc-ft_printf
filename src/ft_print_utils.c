/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:44:24 by ramzerk           #+#    #+#             */
/*   Updated: 2023/12/01 10:08:40 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
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


int get_len(int n)
{
    int i;

    i = 0;
    if (n < 0)
    {
        i++;
        n *= -1;
    }
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
