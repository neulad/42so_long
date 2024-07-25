/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu <ukireyeu@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:25:04 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/18 19:48:06 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../so_long.h"
#include "../../game/game.h"

void	validate_size(t_map map);
void	validate_border(t_map map);
void	validate_map(t_map map);
void	validate_sprites(t_map map);
void	validate_exit(t_map map);