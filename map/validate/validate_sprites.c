/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:28:27 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:09:51 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include "../../utils/utils.h"

static int	check_sprite(char c, int *plr, int *exs, int *cs)
{
	if (c == 'P')
		++(*plr);
	else if (c == 'E')
		++(*exs);
	else if (c == 'C')
		++(*cs);
	else if (c != '1' && c != '0' && c != 'M')
		return (0);
	return (1);
}

void	validate_sprites(t_map map)
{
	int		players;
	int		exits;
	int		collecs;
	int		i;
	int		j;

	i = -1;
	players = 0;
	exits = 0;
	collecs = 0;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
			if (!check_sprite(map[i][j], &players, &exits, &collecs))
				error(map, "map is malformed");
	}
	if (players != 1 || exits != 1)
		error(map, "players must be one");
	if (collecs < 1)
		error(map, "collectibles should be >=1");
}
