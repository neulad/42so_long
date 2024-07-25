/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:06:56 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:33:39 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/game.h"
#include "../libs/minilibx/mlx.h"
#include "utils.h"
#include <stdlib.h>

void	end_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->s->bg);
	mlx_destroy_image(game->mlx, game->s->f);
	mlx_destroy_image(game->mlx, game->s->c);
	mlx_destroy_image(game->mlx, game->s->en);
	mlx_destroy_image(game->mlx, game->s->ex);
	mlx_destroy_image(game->mlx, game->s->lp);
	mlx_destroy_image(game->mlx, game->s->rp);
	mlx_destroy_window(game->mlx, game->w);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	free(game->s);
	exit(0);
}
