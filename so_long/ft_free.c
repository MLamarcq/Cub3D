/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:29:27 by ggosse            #+#    #+#             */
/*   Updated: 2023/02/09 16:54:15 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_free_tab_str(char **tab_str)
{
	int	ite_free_two;

	ite_free_two = -1;
	while (tab_str[++ite_free_two])
	{
		free(tab_str[ite_free_two]);
		tab_str[ite_free_two] = NULL;
	}
	free(tab_str);
	tab_str = NULL;
}

int	ft_destroy_and_free(t_game *game, char *err)
{
	if (err)
		ft_putstr_fd(err, 2);
	if (game->img_0)
		mlx_destroy_image(game->mlibx, game->img_0);
	if (game->img_1)
		mlx_destroy_image(game->mlibx, game->img_1);
	if (game->img_p)
		mlx_destroy_image(game->mlibx, game->img_p);
	if (game->img_c)
		mlx_destroy_image(game->mlibx, game->img_c);
	if (game->img_e)
		mlx_destroy_image(game->mlibx, game->img_e);
	if (game->window)
		mlx_destroy_window(game->mlibx, game->window);
	if (game->window)
		mlx_destroy_display(game->mlibx);
	free(game->mlibx);
	ft_free_tab_str(game->map->map_chck);
	ft_free_tab_str(game->map->map_org);
	free(game->map);
	exit (1);
}

int	ft_destroy_and_free2(t_game *game)
{
	if (game->img_0)
		mlx_destroy_image(game->mlibx, game->img_0);
	if (game->img_1)
		mlx_destroy_image(game->mlibx, game->img_1);
	if (game->img_p)
		mlx_destroy_image(game->mlibx, game->img_p);
	if (game->img_c)
		mlx_destroy_image(game->mlibx, game->img_c);
	if (game->img_e)
		mlx_destroy_image(game->mlibx, game->img_e);
	if (game->window)
		mlx_destroy_window(game->mlibx, game->window);
	if (game->window)
		mlx_destroy_display(game->mlibx);
	free(game->mlibx);
	ft_free_tab_str(game->map->map_chck);
	ft_free_tab_str(game->map->map_org);
	free(game->map);
	exit (1);
}

void	ft_free_parsing(t_game *game, char *err)
{
	if (err)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(err, 2);
	}
	if (game->map->map_build)
	{
		free(game->map->map_build);
		game->map->map_build = NULL;
	}	
	if (game->map->map_org)
		ft_free_tab_str(game->map->map_org);
	if (game->map->map_chck)
		ft_free_tab_str(game->map->map_chck);
	if (game->map)
	{
		free(game->map);
		game->map = NULL;
	}
}

void	ft_init_img(t_game *game)
{
	game->img_0 = 0;
	game->img_1 = 0;
	game->img_p = 0;
	game->img_c = 0;
	game->img_e = 0;
}
