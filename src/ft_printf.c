/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:55:53 by rabouzia          #+#    #+#             */
/*   Updated: 2024/09/30 23:45:25 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list *args, char c)
{
	if (c == 'c')
		return(ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (print_address((unsigned long)va_arg(*args, void *),hex));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), hex));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), HEX));
	if (c == 'i' || c == 'd')
		return (print_decimal(va_arg(*args, int)));
	if (c == '%')
		return(ft_putchar('%'));
	if (c == 'u')
		return (ft_putnbr_base((long)va_arg(*args, unsigned int), dec));
	if (c == 'f')
		return 0;
	return (0);
}



int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		res;

	va_start(list, str);
	if ((str[0] == '%' && str[1] == '\0') || !str)
		return (-1);
	i = -1;
	res = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			res += check(&list, str[++i]);
		else
		{
			ft_putchar(str[i]);
			res++;
		}
	}
	va_end(list);
	return (res);
}

int main()
{
	ft_printf("%d\n", 32);
	// printf("%-");
}


// #include <stdarg.h>
// #include <stdio.h>  // Assuming you have the implementations of ft_putchar, ft_putstr, etc.


// // Declare all the functions you're calling, assuming they're implemented elsewhere
// int ft_putchar(int c);
// int ft_putstr(char *str);
// int print_address(unsigned long addr, char *base);
// int ft_putnbr_base(unsigned int nbr, char *base);
// int print_decimal(int n);

// // Individual functions for each specifier
// int handle_char(va_list *args) { return ft_putchar(va_arg(*args, int)); }
// int handle_string(va_list *args) { return ft_putstr(va_arg(*args, char *)); }
// int handle_address(va_list *args) { return print_address((unsigned long)va_arg(*args, void *), "0123456789abcdef"); }
// int handle_hex_lower(va_list *args) { return ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef"); }
// int handle_hex_upper(va_list *args) { return ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF"); }
// int handle_decimal(va_list *args) { return print_decimal(va_arg(*args, int)); }
// int handle_unsigned(va_list *args) { return ft_putnbr_base(va_arg(*args, unsigned int), "0123456789"); }
// int handle_percent(va_list *args) { (void)args; return ft_putchar('%'); }  // % doesn't use args

// // Mapping specifiers to corresponding functions
// t_func get_function(char c) {
//     if (c == 'c') 
// 		return handle_char;
//     if (c == 's') 
// 		return handle_string;
//     if (c == 'p') 
// 		return handle_address;
//     if (c == 'x') 
// 		return handle_hex_lower;
//     if (c == 'X') 
// 		return handle_hex_upper;
//     if (c == 'i' || c == 'd') 
// 		return handle_decimal;
//     if (c == 'u') return 
// 		handle_unsigned;
//     if (c == '%') 
// 		return handle_percent;
//     return NULL;  // If no valid specifier is found
// }

// int check(va_list *args, char c) {
//     t_func handler = get_function(c);
//     if (handler)
//         return handler(args);  // Call the appropriate function
//     return 0;  // If the specifier is invalid, return 0
// }
 