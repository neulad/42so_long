/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:06:30 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/30 23:01:50 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_upper_x_len(unsigned int x)
{
	int	n;

	n = 0;
	if (x == 0)
		return (1);
	while (x && ++n)
		x /= 16;
	return (n);
}

static void	ft_upper_x_print(unsigned int x)
{
	if (x <= 9)
		return (ft_putchar(x + '0'));
	if (x <= 15)
		return (ft_putchar(x % 10 + 'A'));
	ft_upper_x_print(x / 16);
	ft_upper_x_print(x % 16);
}

int	ft_print_upper_x(va_list args)
{
	unsigned int	d;
	int				len;

	d = va_arg(args, unsigned int);
	len = ft_upper_x_len(d);
	ft_upper_x_print(d);
	return (len);
}
