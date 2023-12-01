/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:49:01 by ramzerk           #+#    #+#             */
/*   Updated: 2023/12/01 18:07:27 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void			ft_putstr(const char *str);

int				get_len(int n);

int				ft_strlen(const char *);

int				ft_putchar(const char c);

int				print_string(const char *s);

unsigned int	is_valid_base(char *base);

long			ft_putnbr_base(long nbr, char *base);

int				check(va_list *args, char c);

int				ft_printf(const char *str, ...);

#endif