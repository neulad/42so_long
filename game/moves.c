/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:31:37 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:37:00 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./game.h"
#include <stdlib.h>
#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../utils/utils.h"

void	animate_player(int new_x, int new_y, int x_off, t_game *g)
{
	if (x_off == 0)
	{
		if (g->player_look == 1)
			mlx_put_image_to_window(g->mlx, g->w,
				g->s->rp, new_x * SZ, new_y * SZ);
		else
			mlx_put_image_to_window(g->mlx, g->w,
				g->s->lp, new_x * SZ, new_y * SZ);
	}
	else if (x_off > 0)
	{
		g->player_look = 1;
		mlx_put_image_to_window(g->mlx, g->w,
			g->s->rp, new_x * SZ, new_y * SZ);
	}
	else
	{
		g->player_look = 2;
		mlx_put_image_to_window(g->mlx, g->w,
			g->s->lp, new_x * SZ, new_y * SZ);
	}
}

void	draw_counter(t_game *game)
{
	static int	counter = 0;
	char		*temp_counter;
	char		*temp_string;

	++counter;
	temp_counter = ft_itoa(counter);
	temp_string = ft_strjoin("Moves: ", temp_counter);
	draw_sprites(game, 0, 0);
	draw_sprites(game, 1, 0);
	mlx_string_put(game->mlx, game->w, 10, 10, 0x00FFFFFF, temp_string);
	free(temp_counter);
	free(temp_string);
}

void	move_player(int x_off, int y_off, t_game *game)
{
	int	new_y;
	int	new_x;

	new_x = game->pp[0] + x_off;
	new_y = game->pp[1] + y_off;
	if (game->map[new_y][new_x] == 'C')
	{
		++(game->n_collected);
		game->map[new_y][new_x] = '0';
	}
	else if (game->map[new_y][new_x] == 'E'
		&& game->n_collected >= game->collecs)
		end_game(game);
	else if (game->map[new_y][new_x] == 'M')
		end_game(game);
	else if (game->map[new_y][new_x] != '1')
	{
		draw_sprites(game, game->pp[0], game->pp[1]);
		game->pp[0] = new_x;
		game->pp[1] = new_y;
		animate_player(new_x, new_y, x_off, game);
		draw_counter(game);
	}
}
