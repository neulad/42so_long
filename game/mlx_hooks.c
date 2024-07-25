/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:51:36 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:33:39 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../libs/minilibx/mlx.h"
#include "../utils/utils.h"

static int	stop_game(t_game *game)
{
	end_game(game);
	return (0);
}

static int	move_hook(int keycode, t_game *game)
{
	if (keycode == 119)
		move_player(0, -1, game);
	else if (keycode == 97)
		move_player(-1, 0, game);
	else if (keycode == 115)
		move_player(0, 1, game);
	else if (keycode == 100)
		move_player(1, 0, game);
	else if (keycode == 65307)
		end_game(game);
	return (0);
}

void	set_hooks(t_game *game)
{
	mlx_hook(game->w, 17, 0L, stop_game, game);
	mlx_key_hook(game->w, move_hook, game);
}
