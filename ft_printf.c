/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:20:14 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/15 19:59:05 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		i;
	int			size;

	va_start(args, str);
	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			size = ft_conversion(args, str[i + 1], size);
			i = i + 2;
		}
		else
		{
			write(1, &str[i++], 1);
			size++;
		}
	}
	va_end(args);
	return (size);
}

char	*ft_itoa_unsig(unsigned int n)
{
	char			*a;
	int				size;
	unsigned int	num;

	size = 0;
	num = n;
	if (num == 0)
		size++;
	while (num != 0)
	{
		num = num / 10;
		size++;
	}
	a = (char *)malloc((size + 1) * sizeof(char));
	if (!a)
		return (0);
	a[size--] = '\0';
	while (n >= 10)
	{
		a[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	a[size--] = n + '0';
	return (a);
}

char	*ft_itoa(int n)
{
	char			*a;
	unsigned int	num;
	size_t			size;

	num = ft_is_sign(n);
	size = ft_size(n);
	a = (char *)malloc((size + 1) * sizeof(char));
	if (!a)
		return (0);
	a[size--] = '\0';
	while (num >= 10)
	{
		a[size] = num % 10 + '0';
		num = num / 10;
		size--;
	}
	a[size--] = num + '0';
	if (n < 0)
		a[size--] = '-';
	return (a);
}

char	*ft_ib(unsigned int n, char *base)
{
	int				size;
	char			*a;
	unsigned int	num;

	size = 0;
	num = n;
	if (num == 0)
		size++;
	while (num != 0)
	{
		num = num / 16;
		size++;
	}
	a = malloc(size + 1);
	a[size] = '\0';
	size--;
	while (n >= 16 && 0 < size)
	{
		a[size] = base[n % 16];
		n = n / 16;
		size--;
	}
	a[size--] = base[n % 16];
	return (a);
}

char	*ft_itoa_void(unsigned long int n, char *base)
{
	int					size;
	char				*a;
	unsigned long int	num;

	size = 0;
	num = n;
	if (num == 0)
		size++;
	while (num != 0)
	{
		num = num / 16;
		size++;
	}
	a = malloc(size + 1);
	a[size] = '\0';
	size--;
	while (n >= 16 && 0 < size)
	{
		a[size] = base[n % 16];
		n = n / 16;
		size--;
	}
	a[size--] = base[n % 16];
	return (a);
}
