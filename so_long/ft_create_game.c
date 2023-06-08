/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:37:07 by gael              #+#    #+#             */
/*   Updated: 2023/06/08 17:44:20 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_put_images_to_win(t_game *game, int *ite_row, int *ite_col)
{
	if (game->map->map_org[(*ite_row)][(*ite_col)] == '0')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_0, (*ite_col) * game->img_size, (*ite_row) * game->img_size);
	else if (game->map->map_org[(*ite_row)][(*ite_col)] == '1')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_1, (*ite_col) * game->img_size, (*ite_row) * game->img_size);
	else if (game->map->map_org[(*ite_row)][(*ite_col)] == 'E')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_e, (*ite_col) * game->img_size, (*ite_row) * game->img_size);
	else if (game->map->map_org[(*ite_row)][(*ite_col)] == 'C')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_c, (*ite_col) * game->img_size, (*ite_row) * game->img_size);
	else if (game->map->map_org[(*ite_row)][(*ite_col)] == 'P')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_p, (*ite_col) * game->img_size, (*ite_row) * game->img_size);
}

void	ft_init_sprite(t_game *game)
{
	ft_init_img(game);
	game->img_0 = mlx_xpm_file_to_image(game->mlibx,
			"./sprites/water.xpm", &game->img_size, &game->img_size);
	if (game->img_0 == NULL)
		ft_destroy_and_free(game, "somthing wrong happened with sprites");
	game->img_1 = mlx_xpm_file_to_image(game->mlibx,
			"./sprites/rock.xpm", &game->img_size, &game->img_size);
	if (game->img_1 == NULL)
		ft_destroy_and_free(game, "somthing wrong happened with sprites");
	game->img_p = mlx_xpm_file_to_image(game->mlibx,
			"./sprites/ship_right.xpm", &game->img_size, &game->img_size);
	if (game->img_p == NULL)
		ft_destroy_and_free(game, "somthing wrong happened with sprites");
	game->img_c = mlx_xpm_file_to_image(game->mlibx,
			"./sprites/crystal.xpm", &game->img_size, &game->img_size);
	if (game->img_c == NULL)
		ft_destroy_and_free(game, "somthing wrong happened with sprites");
	game->img_e = mlx_xpm_file_to_image(game->mlibx,
			"./sprites/exit.xpm", &game->img_size, &game->img_size);
	if (game->img_e == NULL)
		ft_destroy_and_free(game, "somthing wrong happened with sprites");
}

void	ft_place_tiles(t_game *game)
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
			ft_put_images_to_win(game, &ite_row, &ite_col);
			ite_col++;
		}
		ite_row++;
	}
}

int	clear_img(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->tab_img[i])
	{
		j = 0;
		while (game->tab_img[i][j])
		{
			mlx_destroy_image(game->mlibx, game->tab_img[i][j]);
			game->tab_img[i][j] = NULL;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_event_listen(int key, t_game *game)
{
	if (key == 65307)
		ft_destroy_and_free(game, NULL);
	init_line(game);
	if (key == XK_w)
	{
		clear_img(game);
		game->map->pos_y = game->map->pos_y - 5;
		image_tab_to_window(game);
	}
	else if (key == XK_s)
	{
		game->map->pos_y = game->map->pos_y + 5;
		image_tab_to_window(game);
	}
	else if (key == XK_a)
	{
		game->map->pos_x = game->map->pos_x - 5;
		image_tab_to_window(game);
	}
	else if (key == XK_d)
	{
		game->map->pos_x = game->map->pos_x + 5;
		image_tab_to_window(game);
	}
	return (0);
}

void	init_img(t_game	*game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		return ;
	game->img->mlx_img = NULL;
	game->img->addr = NULL;
	game->img->bpp = 0;
	game->img->line_len = 0;
	game->img->endian = 0;
}

void	img_pix_put(t_game *game, int x, int y, int color)
{
	char	*pixel;

	pixel = game->img->addr + (y * game->img->line_len + x * (game->img->bpp / 8));
	*(int *)pixel = color;
}

void	img_pix_put_2(t_game *game, int x, int y, int color, int i, int j)
{
	char	*pixel;

	pixel = game->tab_img[i][j]->addr + (y * game->tab_img[i][j]->line_len + x * 
		(game->tab_img[i][j]->bpp / 8));
	*(int *)pixel = color;
}


int	create_tab_img(t_game *game)
{
	int i;

	
	i = 0;
	game->tab_img = (t_img ***)malloc(sizeof(t_img **) * ((game->map->h) + 1));
	if (!game->tab_img)
		return (printf("Malloc failed\n"), 0);
	game->tab_img[game->map->h] = NULL;
	while (i < game->map->h)
	{
		game->tab_img[i] = (t_img **)malloc(sizeof(t_img *) * ((game->map->w) + 1));
		if (!game->tab_img[i])
			return (printf("Malloc failed\n"), 0);
		int j = 0;
		while (j < game->map->w)
		{
			//printf("i, j: %i %i\n", i, j);
		    game->tab_img[i][j] = malloc(sizeof(t_img));
			if (!game->tab_img[i][j])
				return (printf("Malloc failed\n"), 0);
			game->tab_img[i][j]->mlx_img = NULL;
			game->tab_img[i][j]->addr = NULL;
			game->tab_img[i][j]->bpp = 0;
			game->tab_img[i][j]->line_len = 0;
			game->tab_img[i][j]->endian = 0;
			j++;
		}
		game->tab_img[i][game->map->w] = NULL;
		i++;
	}
	return (1);
}

int	create_image(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map->h)
	{
		j = 0;
		while (j < game->map->w)
		{
			game->tab_img[i][j]->mlx_img = mlx_new_image(game->mlibx, game->img_size, game->img_size);
			if (!game->tab_img[i][j])
				return (printf("Error during creating image\n"), 0);
			game->tab_img[i][j]->addr = mlx_get_data_addr(game->tab_img[i][j]->mlx_img, 
			&game->tab_img[i][j]->bpp, &game->tab_img[i][j]->line_len, 
			&game->tab_img[i][j]->endian);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

void	fill_square(t_game *game, int color, int i, int j)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->img_size)
	{
		x = 0;
		while (x < game->img_size)
		{
			img_pix_put_2(game, x, y, color, i, j);
			x++;
		}
		y++;
	}
}

int	pixel_in_tab(t_game *game)
{
	int i;
	int j;

	if (create_image(game) == 0)
		return (printf("Failed to create image\n"), FAIL);
	i = 0;
	while (game->tab_img[i])
	{
		j = 0;
		while (game->tab_img[i][j])
		{
			if (game->map->map_org[i][j] == '1')
				fill_square(game, get_color(255, 0, 230), i, j);
			else
				fill_square(game, get_color(10, 30, 240), i, j);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}


void	put_square(t_game *game)
{
	int i;
	int j;
	int x;
	int y;

	y = 0;
	while (game->tab_img[y])
	{
		x = 0;
		while (game->tab_img[y][x])
		{
			if ((x == floor(game->map->pos_x / game->img_size)) && (y == floor(game->map->pos_y / game->img_size)))
			{
				i = game->map->pos_x - 2;
				while (i < game->map->pos_x + 2)
				{
					j = game->map->pos_y - 2;
					printf("j: %i\n", j);
					while (j < game->map->pos_y + 2)
					{
						// printf("x: %i\n", x);
						// printf("y: %i\n", y);
						// printf("\n");
						// printf("j: %i\n", j);
						// printf("i: %i\n", i);
						// printf("\n.....................................\n\n");
						img_pix_put_2(game, i - 24, j - 24, get_color(1, 255, 1), y, x);
						j++;
					}
					i++;
				}
			}
			x++;
		}
		y++;
	}
}

int	set_pos_p(t_game *game)
{
	int x;
	int y;
	
	y = 0;
	while (game->tab_img[y])
	{
		x = 0;
		while (game->tab_img[y][x])
		{
			if (game->map->map_org[y][x] == 'P')
			{
				game->map->pos_x = (x * game->img_size) + (game->img_size / 2);
				printf("game->map->pos_x : %i\n", game->map->pos_x );
				game->map->pos_y = (y * game->img_size) + (game->img_size / 2);
				printf("game->map->pos_y : %i\n", game->map->pos_y );
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	image_tab_to_window(t_game *game)
{
	int i;
	int j;

	if (pixel_in_tab(game) == 0)
		return (printf("Failed to put pixel\n"), FAIL);
	put_square(game);
	i = 0;
	while (game->tab_img[i])
	{
		j = 0;
		while (game->tab_img[i][j])
		{
				mlx_put_image_to_window((game->mlibx), (game->window),
					game->tab_img[i][j]->mlx_img, j * game->img_size, i * game->img_size);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_display_map(t_game *game)
{
	(game->img_size) = 48;
	(game->mlibx) = mlx_init();
	game->window = mlx_new_window((game->mlibx),
			game->map->w * game->img_size, game->map->h * game->img_size, "so_long");
	if (game->mlibx == NULL)
		return (FAIL);
	if (game->window == NULL)
		return (free(game->window), FAIL);
	(game->img_size) = 48;
	init_img(game);
	if (create_tab_img(game) == 0)
		return (printf("Failed to create tab\n"), 0);
	set_pos_p(game);
	image_tab_to_window(game);
	init_line(game);
	put_line_in_img(game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, \
	&ft_destroy_and_free2, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &ft_event_listen, game);
	mlx_loop(game->mlibx);
	ft_destroy_and_free(game, NULL);
	return (free(game->mlibx), SUCCESS);
}
