/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:56:49 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/07/19 21:59:16 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../utils/utils.h"
#include "../libs/libft/libft.h"

static char	*read_map(int fd)
{
	char	*raw_map;
	char	*new_line;
	char	*temp;

	raw_map = get_next_line(fd);
	if (!raw_map)
		error(NULL, "empty map");
	new_line = get_next_line(fd);
	while (new_line)
	{
		temp = raw_map;
		raw_map = ft_strjoin(raw_map, new_line);
		free(new_line);
		free(temp);
		new_line = get_next_line(fd);
	}
	return (raw_map);
}

char	**parse_map(char *path)
{
	int		fd;
	char	*raw_map;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error(NULL, "map can't be opened");
	raw_map = read_map(fd);
	close(fd);
	map = ft_split(raw_map, '\n');
	free(raw_map);
	return (map);
}
