/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:41:19 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:10:35 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include "../../utils/utils.h"

static void	validate_horizontal_border(t_map map)
{
	char	*top;
	char	*bottom;

	top = map[0];
	bottom = map[map_height(map) - 1];
	while (*top)
	{
		if (*top != '1')
			error(map, "malformed border");
		++top;
	}
	while (*bottom)
	{
		if (*bottom != '1')
			error(map, "malformed border");
		++bottom;
	}
}

static void	validate_vertical_border(t_map map)
{
	int		line_len;
	t_map	cmap;

	cmap = map;
	line_len = map_width(cmap);
	while (*cmap)
	{
		if ((*cmap)[0] != '1' || (*cmap)[line_len - 1] != '1')
			error(map, "malformed border");
		++cmap;
	}
}

void	validate_border(t_map map)
{
	validate_horizontal_border(map);
	validate_vertical_border(map);
}
