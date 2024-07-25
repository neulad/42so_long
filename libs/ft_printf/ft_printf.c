/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:58:14 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/31 15:46:33 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flag(char const *fmt, va_list args)
{
	if (*fmt == 'c')
		return (ft_printc(args));
	if (*fmt == 's')
		return (ft_prints(args));
	if (*fmt == 'p')
		return (ft_printp(args));
	if (*fmt == 'd')
		return (ft_printd(args));
	if (*fmt == 'i')
		return (ft_printd(args));
	if (*fmt == 'u')
		return (ft_printu(args));
	if (*fmt == 'x')
		return (ft_print_x(args));
	if (*fmt == 'X')
		return (ft_print_upper_x(args));
	if (*fmt == '%')
		return (ft_print_percent());
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;
	int		bytes_wrote;

	if (!fmt)
		return (0);
	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			len += write(1, fmt, 1);
		else
		{
			++fmt;
			bytes_wrote = ft_print_flag((char *)fmt, args);
			if (bytes_wrote < 0)
				return (-1);
			len += bytes_wrote;
		}
		++fmt;
	}
	return (len);
}
/* #include <stdio.h>
int	main(void)
{
	int k = 12;
	int n = printf("%i\n", 2147483649);
	printf("Bytes read: %d", n);
	return (0);
} */
