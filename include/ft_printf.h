/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:49:01 by ramzerk           #+#    #+#             */
/*   Updated: 2023/12/05 16:08:36 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_putstr(const char *str);

int				get_len(int n);

int				ft_strlen(const char *);

int				ft_putchar(const char c);

unsigned int	is_valid_base(char *base);

int			ft_putnbr_base(int nbr, char *base);

long			ft_putnbr_base_unsigned(unsigned long nbr, char *base);

int				check(va_list *args, char c);

int				print_adress(int a, char *s);

int				get_digits(int n);

int				print_decimal(int a);

long			ft_putnbr(int nb);

int				ft_printf(const char *str, ...);

#endif
