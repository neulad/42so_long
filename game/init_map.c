/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:36:36 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:34:05 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../libs/minilibx/mlx.h"
#include "../utils/utils.h"
#include "./game.h"
#include <stdlib.h>

static void	load_sprites(t_game *game)
{
	int	h;
	int	w;

	game->s->bg
		= mlx_xpm_file_to_image(game->mlx, "sprites/background.xpm", &w, &h);
	game->s->f
		= mlx_xpm_file_to_image(game->mlx, "sprites/border.xpm", &w, &h);
	game->s->c
		= mlx_xpm_file_to_image(game->mlx, "sprites/collectible.xpm", &w, &h);
	game->s->en
		= mlx_xpm_file_to_image(game->mlx, "sprites/enemy.xpm", &w, &h);
	game->s->ex
		= mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &w, &h);
	game->s->rp
		= mlx_xpm_file_to_image(game->mlx, "sprites/rplayer.xpm", &w, &h);
	game->s->lp
		= mlx_xpm_file_to_image(game->mlx, "sprites/lplayer.xpm", &w, &h);
}

static void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_sprites(game, x, y);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(game->mlx, game->w, game->s->rp,
		game->pp[0] * SZ, game->pp[1] * SZ);
}

static void	set_init_coords(t_game *game)
{
	int	x;
	int	y;

	game->collecs = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->pp[0] = x;
				game->pp[1] = y;
				game->map[y][x] = '0';
			}
			else if (game->map[y][x] == 'C')
				++(game->collecs);
			++x;
		}
		++y;
	}
}

void	draw_sprites(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->w, g->s->f, x * SZ, y * SZ);
	else if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->w, g->s->bg, x * SZ, y * SZ);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->w, g->s->ex, x * SZ, y * SZ);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->w, g->s->rp, x * SZ, y * SZ);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->w, g->s->c, x * SZ, y * SZ);
	else if (g->map[y][x] == 'M')
		mlx_put_image_to_window(g->mlx, g->w, g->s->en, x * SZ, y * SZ);
}

void	init_map(t_game *game)
{
	game->width = map_width(game->map);
	game->height = map_height(game->map);
	game->mlx = mlx_init();
	game->w
		= mlx_new_window(game->mlx, game->width * SZ, game->height * SZ, "g");
	game->s = malloc(sizeof(t_sprites));
	set_init_coords(game);
	game->n_collected = 0;
	game->player_look = 1;
	load_sprites(game);
	draw_map(game);
	set_hooks(game);
	mlx_loop(game->mlx);
}
