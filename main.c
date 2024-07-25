/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:57:28 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 21:57:21 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libs/minilibx/mlx.h"
#include "map/map.h"
#include "game/game.h"
#include "map/validate/validate.h"
#include "game/game.h"
#include "libs/ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
	{
		ft_printf("error: must provide map file");
		return (0);
	}
	game.map = parse_map(argv[1]);
	validate_map(game.map);
	init_map(&game);
}
