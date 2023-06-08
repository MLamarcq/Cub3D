/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by ggosse            #+#    #+#             */
/*   Updated: 2023/02/09 14:42:40 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_exit(t_game *game)
{
	int	ite_collect1;
	int	ite_collect2;

	ite_collect1 = -1;
	while (game->map->map_org[++ite_collect1])
	{
		ite_collect2 = -1;
		while (game->map->map_org[ite_collect1][++ite_collect2])
		{
			if (game->map->map_org[ite_collect1][ite_collect2] == 'C')
				return (FAIL);
		}
	}
	return (SUCCESS);
}

void	ft_move_w(t_game *game)
{
	if (game->map->map_org[game->map->p_y - 1][game->map->p_x] == '0' ||
		game->map->map_org[game->map->p_y - 1][game->map->p_x] == 'C')
	{
		ft_find_p(game);
		ft_remove_p(game);
		ft_place_p(game, game->map->p_y - 1, game->map->p_x);
		mlx_destroy_image(game->mlibx, game->img_p);
		game->img_p = mlx_xpm_file_to_image(game->mlibx,
				"./sprites/ship_up.xpm", &game->img_size, &game->img_size);
		if (game->img_p == NULL)
			ft_destroy_and_free(game, "Error\nproblem with image...");
		ft_printf("step: %i\n", game->map->count_step);
		game->map->count_step++;
	}
	else if (game->map->map_org[game->map->p_y - 1][game->map->p_x] == 'E')
	{
		if (ft_check_exit(game) == SUCCESS)
		{
			ft_printf("step: %i\n", game->map->count_step);
			game->map->count_step++;
			ft_putstr_fd("You won :)\n", 1);
			ft_destroy_and_free(game, NULL);
		}
	}
}

void	ft_move_s(t_game *game)
{
	if (game->map->map_org[game->map->p_y + 1][game->map->p_x] == '0' ||
		game->map->map_org[game->map->p_y + 1][game->map->p_x] == 'C')
	{
		ft_find_p(game);
		ft_remove_p(game);
		ft_place_p(game, game->map->p_y + 1, game->map->p_x);
		mlx_destroy_image(game->mlibx, game->img_p);
		game->img_p = mlx_xpm_file_to_image(game->mlibx,
				"./sprites/ship_down.xpm", &game->img_size, &game->img_size);
		if (game->img_p == NULL)
			ft_destroy_and_free(game, "Error\nproblem with image...");
		ft_printf("step: %i\n", game->map->count_step);
		game->map->count_step++;
	}
	else if (game->map->map_org[game->map->p_y + 1][game->map->p_x] == 'E')
	{
		if (ft_check_exit(game) == SUCCESS)
		{
			ft_printf("step: %i\n", game->map->count_step);
			game->map->count_step++;
			ft_putstr_fd("You won :)\n", 1);
			ft_destroy_and_free(game, NULL);
		}
	}
}

void	ft_move_a(t_game *game)
{
	if (game->map->map_org[game->map->p_y][game->map->p_x - 1] == '0' ||
		game->map->map_org[game->map->p_y][game->map->p_x - 1] == 'C')
	{
		ft_find_p(game);
		ft_remove_p(game);
		ft_place_p(game, game->map->p_y, game->map->p_x - 1);
		mlx_destroy_image(game->mlibx, game->img_p);
		game->img_p = mlx_xpm_file_to_image(game->mlibx,
				"./sprites/ship_left.xpm", &game->img_size, &game->img_size);
		if (game->img_p == NULL)
			ft_destroy_and_free(game, "Error\nproblem with image...");
		ft_printf("step: %i\n", game->map->count_step);
		game->map->count_step++;
	}
	else if (game->map->map_org[game->map->p_y][game->map->p_x - 1] == 'E')
	{
		if (ft_check_exit(game) == SUCCESS)
		{
			ft_printf("step: %i\n", game->map->count_step);
			game->map->count_step++;
			ft_putstr_fd("You won :)\n", 1);
			ft_destroy_and_free(game, NULL);
		}
	}
}

void	ft_move_d(t_game *game)
{
	if (game->map->map_org[game->map->p_y][game->map->p_x + 1] == '0' ||
		game->map->map_org[game->map->p_y][game->map->p_x + 1] == 'C')
	{
		ft_find_p(game);
		ft_remove_p(game);
		ft_place_p(game, game->map->p_y, game->map->p_x + 1);
		mlx_destroy_image(game->mlibx, game->img_p);
		game->img_p = mlx_xpm_file_to_image(game->mlibx,
				"./sprites/ship_right.xpm", &game->img_size, &game->img_size);
		if (game->img_p == NULL)
			ft_destroy_and_free(game, "Error\nproblem with image...");
		ft_printf("step: %i\n", game->map->count_step);
		game->map->count_step++;
	}
	else if (game->map->map_org[game->map->p_y][game->map->p_x + 1] == 'E')
	{
		if (ft_check_exit(game) == SUCCESS)
		{
			ft_printf("step: %i\n", game->map->count_step);
			game->map->count_step++;
			ft_putstr_fd("You won :)\n", 1);
			ft_destroy_and_free(game, NULL);
		}
	}
}
