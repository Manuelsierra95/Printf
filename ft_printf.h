/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:53:00 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/15 19:59:16 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *str, ...);
int				ft_conversion(va_list args, char c, int size);
char			*ft_itoa(int n);
char			*ft_ib(unsigned int n, char *hexa);
char			*ft_itoa_unsig(unsigned int n);
char			*ft_itoa_void(unsigned long int n, char *base);
int				ft_size(int n);
unsigned int	ft_is_sign(int n);
int				ft_printchar(char c, int size);
int				ft_printstring(char *str, int size);
int				ft_printvoid(void *ptr, int size);
int				ft_lp(char *str, int size);
#endif
