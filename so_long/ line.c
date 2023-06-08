#include "ft_so_long.h"

int	absolute_value(int nb)
{
	if (nb == 0)
		return (nb);
	else if (nb < 0)
		nb = nb * (-1);
	return (nb);
}

void	draw_line_p(t_game *game)
{
	int dx;
	int dy;
	int steps;
	float xite;
	float yite;
	float x;
	float y;
	int i = 0;

	game->map->p_x_2 = 3;
	game->map->p_y_2 = 1;
	
	dx = game->map->p_x_2 - game->map->p_x;
	dy = game->map->p_y_2 - game->map->p_y;
	
	// if (absolute_value(dx) > absolute_value(dy))
	// 	steps = absolute_value(dx);
	// else
	// 	steps = absolute_value(dy);
	
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	xite = dx / (float)steps;
	yite = dy / (float)steps;

	x = game->map->p_x;
	y = game->map->p_y;

	while (i <= steps)
	{
	printf("game->x = %d\n", game->map->x);
	printf("game->y = %d\n", game->map->y);
		mlx_pixel_put(game->mlibx, game->window, round(x), round(y), 123);
		x = x + xite;
		y = y + yite;
		i++;
	}

}

void	do_line(t_game *game)
{
	game->map->p_x_2 = 27;
	game->map->p_y_2 = 1;
	// draw_line(game);
}