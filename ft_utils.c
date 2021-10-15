/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:37:56 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/15 20:01:42 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c, int size)
{
	write(1, &c, 1);
	size++;
	return (size);
}

int	ft_printstring(char *str, int size)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (size + 6);
	}
	while (str[i])
	{
		write(1, &str[i++], 1);
		size++;
	}
	return (size);
}

int	ft_printvoid(void *ptr, int size)
{
	long int	ptrnum;
	char		*strnum;
	int			i;

	i = 0;
	ptrnum = (unsigned long int)ptr;
	strnum = ft_itoa_void(ptrnum, "0123456789abcdefg");
	write(1, "0x", 2);
	size = size + 2;
	while (strnum[i])
	{
		write(1, &strnum[i], 1);
		i++;
		size++;
	}
	free(strnum);
	return (size);
}
