/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:37:27 by gael              #+#    #+#             */
/*   Updated: 2023/02/07 15:39:49 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_propagation(t_game *game)
{
	int	ite_propa1;
	int	ite_propa2;
	int	counter_p;
	int	fail;

	fail = 0;
	counter_p = 0;
	ite_propa1 = -1;
	while (game->map->map_chck[++ite_propa1])
	{
		ite_propa2 = -1;
		while (game->map->map_chck[ite_propa1][++ite_propa2])
		{
			if (game->map->map_chck[ite_propa1][ite_propa2] == 'P')
			{
				if (ft_replace_around(game, ite_propa1, ite_propa2) == FAIL)
					fail++;
				ft_replace_around(game, ite_propa1, ite_propa2);
				counter_p++;
			}
		}
	}
	if (counter_p != fail)
		return (FAIL);
	return (SUCCESS);
}

int	ft_check_collectibles(t_game *game)
{
	int	ite_collect1;
	int	ite_collect2;

	ite_collect1 = -1;
	while (game->map->map_chck[++ite_collect1])
	{
		ite_collect2 = -1;
		while (game->map->map_chck[ite_collect1][++ite_collect2])
		{
			if (game->map->map_chck[ite_collect1][ite_collect2] == 'C')
				return (ft_free_parsing(game, \
					"Invalid path leading to C or E\n"), FAIL);
		}
	}
	return (SUCCESS);
}

int	ft_valid_path(t_game *game)
{
	int	ite_reach_row;
	int	ite_reach_col;

	while (ft_propagation(game) == FAIL)
	{
		ft_propagation(game);
	}
	ite_reach_row = 0;
	while (game->map->map_chck[ite_reach_row])
	{
		ite_reach_col = 0;
		while (game->map->map_chck[ite_reach_row][ite_reach_col])
		{
			if (game->map->map_chck[ite_reach_row][ite_reach_col] == 'E')
				if (ft_exit_reachable(game, ite_reach_row, \
					ite_reach_col) == FAIL)
					return (ft_free_parsing(game, \
					"Invalid path leading to C and E\n"), FAIL);
			ite_reach_col++;
		}
		ite_reach_row++;
	}
	return (ft_check_collectibles(game));
}

int	ft_replace_around(t_game *game, int ite_big, int ite_lil)
{
	if (game->map->map_chck[ite_big][ite_lil + 1] == '0'
	|| game->map->map_chck[ite_big][ite_lil + 1] == 'C')
	{
		game->map->map_chck[ite_big][ite_lil + 1] = 'P';
		return (SUCCESS);
	}
	else if (game->map->map_chck[ite_big][ite_lil - 1] == '0'
	|| game->map->map_chck[ite_big][ite_lil - 1] == 'C')
	{
		game->map->map_chck[ite_big][ite_lil - 1] = 'P';
		return (SUCCESS);
	}
	else if (game->map->map_chck[ite_big + 1][ite_lil] == '0'
	|| game->map->map_chck[ite_big + 1][ite_lil] == 'C')
	{
		game->map->map_chck[ite_big + 1][ite_lil] = 'P';
		return (SUCCESS);
	}
	else if (game->map->map_chck[ite_big - 1][ite_lil] == '0'
	|| game->map->map_chck[ite_big - 1][ite_lil] == 'C')
	{
		game->map->map_chck[ite_big - 1][ite_lil] = 'P';
		return (SUCCESS);
	}
	return (FAIL);
}

int	ft_exit_reachable(t_game *game, int e_row, int e_col)
{
	if (game->map->map_chck[e_row - 1][e_col] == 'P')
		return (SUCCESS);
	if (game->map->map_chck[e_row + 1][e_col] == 'P')
		return (SUCCESS);
	if (game->map->map_chck[e_row][e_col - 1] == 'P')
		return (SUCCESS);
	if (game->map->map_chck[e_row][e_col + 1] == 'P')
		return (SUCCESS);
	return (FAIL);
}
