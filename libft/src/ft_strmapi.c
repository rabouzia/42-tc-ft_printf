/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:20:32 by rabouzia          #+#    #+#             */
/*   Updated: 2023/11/17 17:53:04 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*isma;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	isma = (char *)s;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (isma[i])
	{
		str[i] = f(i, isma[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
