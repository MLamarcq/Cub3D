/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:05:22 by mael              #+#    #+#             */
/*   Updated: 2023/07/30 19:09:56 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	free_xpm(t_game *game)
{
	int i;
	
	i = 0;
	printf("game->xpm->tab_start: %d\n", game->xpm->tab_start);
	while (i < game->xpm->tab_start)
	{
		free(game->xpm->colors[i]);
		i++;
	}
	free(game->xpm->colors);
	free_tab_str(game->xpm->tab_file);
	free(game->xpm->file_content);
	free(game->xpm);
	return (SUCCESS);
}

int	free_ceil_floor(t_game *game)
{
	// int i;

	// i = 0;
	// while (i < 3)
	// {
	// 	printf("game->map->ceil[i]: %i\n", game->map->ceil[i]);
	// 	i++;
	// }
	free(game->map->ceil);
	free(game->map->floor);
	return (SUCCESS);
}

void	free_fov(t_game *game)
{
	int i;
	
	i = 0;
	while (i < game->fov->nbr_ray)
	{
		free(game->fov->wall[i]);
		free(game->fov->wall_witch[i]);
		i++;
	}
	if (game->fov->wall)
		free(game->fov->wall);
	if (game->fov->wall_witch)
		free(game->fov->wall_witch);
	free(game->fov->lines_vision);
	free(game->fov->toggle_vision);
	free(game->fov);
	(void)i;
}

int	free_all(t_game *game)
{
	//printf(BOLD_BLUE"Je rentre dans free all avec echap"RST"\n");
	free_ceil_floor(game);
	free_xpm(game);
	free_fov(game);
	free(game->img);
	free_parsing(game, NULL);
	return (SUCCESS);
}