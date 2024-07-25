/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:16:22 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/31 15:33:39 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(va_list args)
{
	char	*cs;
	int		n;

	cs = va_arg(args, char *);
	if (!cs)
		return (write(1, "(null)", 6));
	n = 0;
	while (*cs)
	{
		write(1, cs++, 1);
		n++;
	}
	return (n);
}
