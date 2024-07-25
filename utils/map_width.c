/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:55:16 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:13:00 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libs/libft/libft.h"

int	map_width(t_map map)
{
	if (!*map)
		return (0);
	return (ft_strlen(*map));
}
