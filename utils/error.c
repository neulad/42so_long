/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:08:15 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:12:22 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf/ft_printf.h"
#include "../so_long.h"
#include "utils.h"
#include <stdlib.h>

void	error(t_map map, char *msg)
{
	if (map)
		free_map(map);
	ft_printf("error: %s\n", msg);
	exit(1);
}
