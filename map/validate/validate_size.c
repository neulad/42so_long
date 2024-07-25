/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:25:46 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:11:28 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/utils.h"
#include "../../libs/libft/libft.h"
#include "../../so_long.h"
#include "../../utils/utils.h"

void	validate_size(t_map map)
{
	char	**cmap;
	size_t	line_len;

	cmap = map;
	line_len = map_width(map);
	if (map_height(map) < 3 || line_len < 4)
		error(map, "malformed map");
	while (*cmap)
	{
		if (ft_strlen(*cmap) != line_len)
			error(map, "malformed map");
		++cmap;
	}
}
