/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:52:48 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:13:17 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(t_map map, int coords[2])
{
	int	x;
	int	y;

	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
		{
			if (map[y][x] == 'P')
			{
				coords[0] = x;
				coords[1] = y;
			}
		}
	}
}

int	if_all_collected(t_map map)
{
	int	x;
	int	y;

	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
		{
			if (map[y][x] != 'X' && map[y][x] != '1' && map[y][x] != 'M')
				return (0);
		}
	}
	return (1);
}
