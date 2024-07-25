/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:20:50 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 22:12:03 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "../../so_long.h"
#include <unistd.h>

void	validate_map(t_map map)
{
	validate_size(map);
	validate_border(map);
	validate_sprites(map);
	validate_exit(map);
}
