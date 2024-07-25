/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:36:05 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:34:28 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../so_long.h"

#define SZ 50

typedef struct s_sprites
{
	void	*bg;
	void	*f;
	void	*c;
	void	*en;
	void	*ex;
	void	*rp;
	void	*lp;
}	t_sprites;

typedef struct s_game
{
	t_map		map;
	void		*mlx;
	void		*w;
	int			width;
	int			height;
	int			player_look;
	int			pp[2];
	int			exit_pos[2];
	int			collecs;
	int			n_collected;
	t_sprites	*s;

}	t_game;

void	init_map(t_game *game);
void	set_hooks(t_game *game);
void	draw_sprites(t_game *game, int x, int y);
void	move_player(int x_off, int y_off, t_game *game);
