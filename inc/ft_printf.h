/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:49:01 by ramzerk           #+#    #+#             */
/*   Updated: 2024/09/30 23:22:55 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

#define HEX "0123456789ABCDEF"
#define hex "0123456789abcdef"
#define dec "0123456789"

typedef int (*t_func)(va_list *args);  // Define a function pointer type that takes va_list* and returns int

int				check(va_list *args, char c);

int				ft_printf(const char *str, ...);

//###### BASE #############

unsigned int	is_valid_base(char *base);

int				ft_putnbr_base(long nbr, char *base);

long			ft_putnbr_base_unsigned(unsigned long nbr, char *base);

int				print_address(unsigned long a, char *s);

int				print_decimal(int a);

//###### UTILS #############

long			ft_putnbr(int nb);

int				ft_putchar(const char c); 

int				ft_strlen(const char *str);

int				ft_putstr(const char *str);


#endif
