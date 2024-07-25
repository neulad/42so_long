/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:19:49 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:13:36 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	free_map(t_map map)
{
	t_map	cmap;

	cmap = map;
	while (*map)
	{
		free(*map);
		++map;
	}
	free(cmap);
}
