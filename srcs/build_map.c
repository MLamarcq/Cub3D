/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:38:48 by gael              #+#    #+#             */
/*   Updated: 2023/07/28 19:15:32 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	skip_empty_line(char **line, int fd)
{
	while ((*line) && (*line)[0] != '\0' && is_empty_line((*line)) == SUCCESS)
	{
		free((*line));
		(*line) = gnl(fd);
	}
}

void	build_content(t_game *game, char **line, int fd)
{
	char *temp;

	temp = NULL; // rajoute pour valgrind le 28/07, a tester
	if (game->map->file_map == NULL)
		game->map->file_map = ft_strdup((*line));
	else
	{
		temp = ft_strdup(game->map->file_map);// rajoute pour valgrind le 28/07, a tester
		free(game->map->file_map);// rajoute pour valgrind le 28/07, a tester
		game->map->file_map = ft_strjoin(temp, (*line));
		free(temp);// rajoute pour valgrind le 28/07, a tester
	}
	free((*line));
	(*line) = gnl(fd);
	game->map->height++;
}

void	realloc_lines(t_game *game)
{
	int		i_realloc;
	int		len;
	char	*str_tmp;

	i_realloc = -1;
	len = 0;
	str_tmp = NULL;
	while (game->map->map_org[++i_realloc])
	{
		len = ft_strlen(game->map->map_org[i_realloc]);
		if (len < (int)game->map->width)
		{
			str_tmp = ft_strdup(game->map->map_org[i_realloc]);
			free(game->map->map_org[i_realloc]);
			free(game->map->map_tmp[i_realloc]);
			game->map->map_org[i_realloc] = \
			ft_strdup_pad(str_tmp, game->map->width, ' ');
			game->map->map_tmp[i_realloc] = \
			ft_strdup_pad(str_tmp, game->map->width, ' ');
		}
	}
}

int	create_map(t_game *game, char *line, int fd)
{
	int	i_init_map;

	game->map->height = 0;
	i_init_map = -1;
	skip_empty_line(&line, fd);
	while (line && line[0] != '\0' && is_empty_line(line) == FAIL)
		build_content(game, &line, fd);
	skip_empty_line(&line, fd);
	if (line && line[0] == '\0')
	{
		if (game->map->height != 0)
			printf("file_map after gnl: %s\n", game->map->file_map);
		// game->map->map_org = malloc((sizeof(char *)) * (game->map->height + 1));
		// if (!game->map->map_org)
		// 	return (printf("malloc map_org failed\n"), FAIL);
		// while (++i_init_map < game->map->height)
		// 	game->map->map_org[i_init_map] = NULL;
		// modifie le 28/07
		game->map->map_org = ft_split(game->map->file_map, '\n');
		game->map->map_tmp = ft_split(game->map->file_map, '\n');
		free(game->map->file_map); // rajoute pour valgrind le 28/07, a tester
		set_width(game);
		realloc_lines(game);
		free(line); // rajoute pour valgrind le 28/07, a tester
		return (close(fd), SUCCESS);
	}
	free(line); // rajoute pour valgrind le 28/07, a tester
	(void)i_init_map;
	return (FAIL);
}

int	build_map(t_game *game, char **argv)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = -1;
	if (open_fd(game, &fd, argv) == FAIL)
		return (FAIL);
	line = gnl(fd);
	while (line && line[0] != '\0')
	{
		if (is_empty_line(line) == FAIL && count < 4)
		{
			if (texture_part(game, line) == FAIL)
				return (FAIL);
			count++;
		}
		else if (is_empty_line(line) == FAIL && count < 6)
		{
			if (floor_ceil_part(game, line) == FAIL)
				return (FAIL);
			count++;
		}
		else if (count >= 6 && game->map->map_org == NULL)
			return (create_map(game, line, fd));
		free(line);
		line = gnl(fd);
	}
	return (SUCCESS);
}
