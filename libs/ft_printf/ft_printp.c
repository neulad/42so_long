/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:16:14 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/31 14:26:42 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_upper_x_len(unsigned long long ptr)
{
	int	n;

	n = 0;
	while (ptr && ++n)
		ptr /= 16;
	return (n);
}

static void	ft_upper_x_print(unsigned long long ptr)
{
	if (ptr <= 9)
		return (ft_putchar(ptr + '0'));
	if (ptr <= 15)
		return (ft_putchar(ptr % 10 + 'a'));
	ft_upper_x_print(ptr / 16);
	ft_upper_x_print(ptr % 16);
}

int	ft_printp(va_list args)
{
	unsigned long long int	ptr;
	int						len;

	ptr = va_arg(args, unsigned long long int);
	if (!ptr)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	if (!ptr)
		return (len + write(1, "0", 1));
	len += ft_upper_x_len(ptr);
	ft_upper_x_print(ptr);
	return (len);
}
