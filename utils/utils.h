/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu <ukireyeu@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:12:11 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 16:23:09 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../so_long.h"
#include "../game/game.h"

void	error(t_map map, char *msg);
int		map_height(t_map map);
int		map_width(t_map map);
void	free_map(t_map map);
void	find_player(t_map map, int coords[2]);
int		if_all_collected(t_map map);
void	end_game(t_game *game);