/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_common.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:22:47 by gael              #+#    #+#             */
/*   Updated: 2023/08/03 10:03:57 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_xpm(t_game *game)
{
	game->xpm = malloc(sizeof(t_xpm));
	if (!game->xpm)
		return (printf("Init fov failed \n"), FAIL);
	game->xpm->no_file_content = NULL;
	game->xpm->no_file_map = NULL;
	game->xpm->no_tab_file = NULL;
	game->xpm->no_colors = NULL;
	game->xpm->no_metadata = NULL;
	game->xpm->no_width_height = FAIL;
	game->xpm->no_tab_start = FAIL;
	game->xpm->ea_file_content = NULL;
	game->xpm->ea_file_map = NULL;
	game->xpm->ea_tab_file = NULL;
	game->xpm->ea_colors = NULL;
	game->xpm->ea_metadata = NULL;
	game->xpm->ea_width_height = FAIL;
	game->xpm->ea_tab_start = FAIL;
	init_second_xpm(game);
	return (SUCCESS);
}

void	init_second_xpm(t_game *game)
{
	game->xpm->we_file_content = NULL;
	game->xpm->we_file_map = NULL;
	game->xpm->we_tab_file = NULL;
	game->xpm->we_colors = NULL;
	game->xpm->we_metadata = NULL;
	game->xpm->we_width_height = FAIL;
	game->xpm->we_tab_start = FAIL;
	game->xpm->so_file_content = NULL;
	game->xpm->so_file_map = NULL;
	game->xpm->so_tab_file = NULL;
	game->xpm->so_colors = NULL;
	game->xpm->so_metadata = NULL;
	game->xpm->so_width_height = FAIL;
	game->xpm->so_tab_start = FAIL;
}

int	xpm_parse(t_game *game)
{
	if (init_xpm(game) == FAIL)
		return (FAIL);
	if (xpm_no_parse(game) == FAIL)
		return (FAIL);
	if (xpm_we_parse(game) == FAIL)
		return (FAIL);
	if (xpm_ea_parse(game) == FAIL)
		return (FAIL);
	if (xpm_so_parse(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	is_space(char chr)
{
	if (chr == 32 || chr == 9)
		return (SUCCESS);
	return (FAIL);
}
