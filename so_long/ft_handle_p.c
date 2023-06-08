/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:37:34 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/08 13:43:30 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_find_p(t_game *game)
{
	int	ite_row;
	int	ite_col;

	ite_row = 0;
	ite_col = 0;
	while (game->map->map_org[ite_row])
	{
		ite_col = 0;
		while (game->map->map_org[ite_row][ite_col])
		{
			if (game->map->map_org[ite_row][ite_col] == 'P')
			{
				game->map->p_x = ite_col;
				game->map->p_y = ite_row;
				break ;
			}
			ite_col++;
		}
		ite_row++;
	}
}

void	ft_remove_p(t_game *game)
{
	int	ite_row;
	int	ite_col;

	ite_row = 0;
	ite_col = 0;
	while (game->map->map_org[ite_row])
	{
		ite_col = 0;
		while (game->map->map_org[ite_row][ite_col])
		{
			if (game->map->map_org[ite_row][ite_col] == 'P')
			{
				game->map->map_org[ite_row][ite_col] = '0';
				break ;
			}
			ite_col++;
		}
		ite_row++;
	}
}

void	ft_place_p(t_game *game, int new_y, int new_x)
{
	int	ite_row;
	int	ite_col;

	ite_row = 0;
	ite_col = 0;
	while (game->map->map_org[ite_row])
	{
		ite_col = 0;
		while (game->map->map_org[ite_row][ite_col])
		{
			if (ite_col == new_x && ite_row == new_y)
			{
				game->map->p_x = ite_col;
				game->map->p_y = ite_row;
				game->map->map_org[ite_row][ite_col] = 'P';
				break ;
			}
			ite_col++;
		}
		ite_row++;
	}
	// printf("x = %d\n", game->map->p_x);
	// printf("y = %d\n", game->map->p_y);
}

int	absolute_value(int nb)
{
	if (nb == 0)
		return (nb);
	else if (nb < 0)
		nb = nb * (-1);
	return (nb);
}

int	init_line(t_game *game)
{
	game->line = malloc(sizeof(t_line));
	if (!game->line)
		return (printf("Malloc failed\n"), FAIL);
	game->line->dx = 0; //x_dest - x_src
	game->line->dy = 0; //y_dest - y_src
	game->line->steps = 0;
	game->line->xite = 0;
	game->line->yite = 0;
	game->line->corr_x = 0;
	game->line->corr_y = 0;
	game->line->x_src = 0;
	game->line->y_src = 0;
	game->line->x_dest = 0;
	game->line->y_dest = 0;
	return (SUCCESS);
}

int	put_line_in_img(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->tab_img[i])
	{
		j = 0;
		while (game->tab_img[i][j])
		{
			game->line->x_src = j * game->img_size;
			game->line->y_src = i * game->img_size;
			game->line->x_dest = (j + 1) * game->img_size;
			game->line->y_dest = i * game->img_size;
			draw_line(game);
			j++;
		}
		i++;
	}
	i = 0;
	while (game->tab_img[i])
	{
		j = 0;
		while (game->tab_img[i][j])
		{
			game->line->x_src = j * game->img_size;
			game->line->y_src = i * game->img_size;
			game->line->x_dest = j * game->img_size;
			game->line->y_dest = (i + 1) * game->img_size;
			draw_line(game);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

 void	draw_line(t_game *game)
{
	int i = 0;

	game->line->dx = game->line->x_dest - game->line->x_src;
	game->line->dy = game->line->y_dest - game->line->y_src;

	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
		game->line->steps = absolute_value(game->line->dx);
	else
		game->line->steps = absolute_value(game->line->dy);

	game->line->xite = game->line->dx / (float)game->line->steps;
	game->line->yite = game->line->dy / (float)game->line->steps;

	game->line->corr_x = game->line->x_src;
	game->line->corr_y = game->line->y_src;
	
	while (i <= game->line->steps)
	{
		mlx_pixel_put(game->mlibx, game->window, round(game->line->corr_x), round(game->line->corr_y), get_color(255, 255, 255));
		game->line->corr_x = game->line->corr_x + game->line->xite;
		game->line->corr_y = game->line->corr_y + game->line->yite;
		i++;
	}
}


// void	draw_line(t_game *game, int i, int j)
// {
// 	int p = 0;

// 	game->line->dx = game->line->x_dest - game->line->x_src;
// 	game->line->dy = game->line->y_dest - game->line->y_src;

// 	if (absolute_value(game->line->dx) > absolute_value(game->line->dy))
// 		game->line->steps = absolute_value(game->line->dx);
// 	else
// 		game->line->steps = absolute_value(game->line->dy);

// 	game->line->xite = game->line->dx / (float)game->line->steps;
// 	game->line->yite = game->line->dy / (float)game->line->steps;

// 	game->line->corr_x = game->line->x_src;
// 	game->line->corr_y = game->line->y_src;
	
// 	while (p <= game->line->steps)
// 	{
// 		img_pix_put_2(game, round(game->line->corr_x), round(game->line->corr_y), get_color(255, 255, 255), i, j);
// 		game->line->corr_x = game->line->corr_x + game->line->xite;
// 		game->line->corr_y = game->line->corr_y + game->line->yite;
// 		p++;
// 	}
// }

void	do_line(t_game *game)
{
	game->map->p_x_2 = 27;
	game->map->p_y_2 = 1;
	// draw_line(game);
}