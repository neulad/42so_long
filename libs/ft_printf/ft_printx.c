/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:52:02 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/31 14:49:56 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_x_len(unsigned int x)
{
	int	n;

	n = 0;
	if (x == 0)
		return (1);
	while (x && ++n)
		x /= 16;
	return (n);
}

static void	ft_x_print(unsigned int x)
{
	if (x <= 9)
		return (ft_putchar(x + '0'));
	if (x <= 15)
		return (ft_putchar(x % 10 + 'a'));
	ft_x_print(x / 16);
	ft_x_print(x % 16);
}

int	ft_print_x(va_list args)
{
	unsigned int	d;
	int				len;

	d = va_arg(args, unsigned int);
	len = ft_x_len(d);
	ft_x_print(d);
	return (len);
}
