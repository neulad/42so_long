/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:00:41 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:11:43 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include "../../libs/libft/libft.h"
#include <stdlib.h>
#include "../../utils/utils.h"
#include "../../utils/utils.h"

static void	free_map_till(t_map map, int n)
{
	int	i;

	i = -1;
	while (++i, i < n)
		free(map[i]);
	free(map);
}

static t_map	dup_map(t_map map)
{
	t_map	map_copy;
	int		i;
	int		height;

	height = map_height(map);
	map_copy = malloc(sizeof(char *) * (height + 1));
	i = -1;
	map_copy[height] = NULL;
	while (++i, map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_map_till(map, i);
			return (NULL);
		}
	}
	return (map_copy);
}

static void	flood_fill(int x, int y, t_map map_copy)
{
	if (map_copy[y][x] == 'X' || map_copy[y][x] == '1')
		return ;
	map_copy[y][x] = 'X';
	flood_fill(x, y - 1, map_copy);
	flood_fill(x, y + 1, map_copy);
	flood_fill(x - 1, y, map_copy);
	flood_fill(x + 1, y, map_copy);
}

void	validate_exit(t_map map)
{
	t_map	map_copy;
	int		player_coords[2];

	map_copy = dup_map(map);
	if (!map_copy)
		error(map, "error: internal error");
	find_player(map, player_coords);
	flood_fill(player_coords[0], player_coords[1], map_copy);
	if (!if_all_collected(map_copy))
	{
		free_map(map_copy);
		error(map, "no correct way out");
	}
	free_map(map_copy);
}
