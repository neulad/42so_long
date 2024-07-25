/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:20:50 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/30 22:59:58 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_ulen(unsigned int d)
{
	int	len;

	if (d == 0)
		return (1);
	len = 0;
	while (d)
	{
		d /= 10;
		len++;
	}
	return (len);
}

static void	ft_u_print(unsigned int d)
{
	if (d <= 9)
		return (ft_putchar(d + '0'));
	ft_u_print(d / 10);
	ft_u_print(d % 10);
}

int	ft_printu(va_list args)
{
	int	d;
	int	len;

	d = va_arg(args, unsigned int);
	len = ft_ulen(d);
	ft_u_print(d);
	return (len);
}
