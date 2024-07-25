/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:44:03 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:13:04 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_height(t_map map)
{
	int	height;

	height = 0;
	while (*map && ++height)
		++map;
	return (height);
}
