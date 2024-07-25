/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:07:26 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/31 15:44:48 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_ulen(int d)
{
	int	len;

	if (d == 0)
		return (1);
	len = 0;
	if (d < 0)
		len++;
	while (d)
	{
		d /= 10;
		len++;
	}
	return (len);
}

static void	ft_d_print(int d)
{
	if (d < 0)
	{
		if (d >= -9)
			return (ft_putchar(d * -1 + '0'));
		ft_d_print((d / 10) * -1);
		ft_d_print((d % 10) * -1);
	}
	else
	{
		if (d <= 9)
			return (ft_putchar(d + '0'));
		ft_d_print(d / 10);
		ft_d_print(d % 10);
	}
}

int	ft_printd(va_list args)
{
	int	d;
	int	len;

	d = va_arg(args, int);
	len = ft_ulen(d);
	if (d < 0)
		ft_putchar('-');
	ft_d_print(d);
	return (len);
}
