/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:00:29 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/15 20:01:05 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list args, char c, int size)
{
	if (c == 'c')
		size = ft_printchar(va_arg(args, int), size);
	if (c == 's')
		size = ft_printstring(va_arg(args, char *), size);
	if (c == 'p')
		size = ft_printvoid(va_arg(args, void *), size);
	if (c == 'd' || c == 'i')
		size = ft_lp(ft_itoa(va_arg(args, int)), size);
	if (c == 'u')
		size = ft_lp(ft_itoa_unsig(va_arg(args, unsigned int)), size);
	if (c == 'x')
		size = ft_lp(ft_ib(va_arg(args, int), "0123456789abcdef"), size);
	if (c == 'X')
		size = ft_lp(ft_ib(va_arg(args, int), "0123456789ABCDEF"), size);
	if (c == '%')
	{
		write(1, "%", 1);
		size++;
	}
	return (size);
}

int	ft_lp(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
		size++;
	}
	free(str);
	return (size);
}

int	ft_size(int n)
{
	size_t	size;

	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

unsigned int	ft_is_sign(int n)
{
	unsigned int	num;

	if (n > 0)
		num = n;
	else
		num = n * -1;
	return (num);
}
