/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:20:27 by gael              #+#    #+#             */
/*   Updated: 2023/06/08 14:11:27 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "color.h"

# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft/libft.h"

# define SUCCESS 1
# define FAIL -1

typedef struct s_letters
{
	int	letter_c;
	int	letter_p;
	int	letter_e;
}		t_letters;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		steps;
	float	xite;
	float	yite;
	float	corr_x;
	float	corr_y;
	int		x_src;
	int		y_src;
	int		x_dest;
	int		y_dest;
	
}	t_line;

typedef struct s_map
{
	char		*map_build;
	char		**map_org;
	char		**map_chck;
	int			h;
	int			w;
	int			pos_x;
	int			pos_y;
	int			p_y;
	int			p_y_2;
	int			p_x;
	int			p_x_2;
	int			count_step;
	int			fd_map;
	t_letters	check_letters;
}				t_map;

typedef struct s_game
{
	t_img	***tab_img;
	void	*mlibx;
	void	*window;
	int		img_size;
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_c;
	void	*img_e;
	t_map	*map;
	t_img	*img;
	t_line	*line;
}			t_game;

/********************************** PARSING ***********************************/

// ft_check_format.C
int		ft_check_rectangular(t_game *game);
int		ft_wrong_letters(t_game *game);
int		ft_nbr_letters(t_game *game);
int		ft_if_wall(t_game *game);

// ft_check_filemap.c
int		ft_read_file(t_game *game, char *filename);
int		ft_check_ext(char *filename);
void	ft_build_map(t_game *game);
int		ft_is_letter(char chr);
int		ft_check_map(char *str, t_game *game);

// ft_so_long.c
int		ft_create_game(t_game *game);
int		ft_parsing(t_game *game, char **argv);
void	ft_print_map_s(char **tab);
void	ft_print_map_xl(char **tab);

// ft_valid_path.c
int		ft_propagation(t_game *game);
int		ft_replace_around(t_game *game, int ite_big, int ite_lil);
int		ft_valid_path(t_game *game);
int		ft_exit_reachable(t_game *game, int e_row, int e_col);

/************************************ MLX *************************************/

// ft_create_game.c
int		ft_display_map(t_game *game);
int		ft_destroy_and_free(t_game *game, char *err);
int		ft_destroy_and_free2(t_game *game);
void	display_line(t_game *game);
void	find_one_coor(t_game *game);

// ft_move.c
void	ft_move_w(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_a(t_game *game);
void	ft_move_d(t_game *game);

void	ft_find_p(t_game *game);
void	ft_free_parsing(t_game *game, char *err);
void	ft_init_img(t_game *game);

void	ft_find_p(t_game *game);
void	ft_remove_p(t_game *game);
void	ft_place_p(t_game *game, int new_y, int new_x);



int	absolute_value(int nb);
void	do_line(t_game *game);
void	init_img(t_game	*game);
void	draw_line(t_game *game);
void	create_image_and_addr(t_game *game);
void	img_pix_put(t_game *game, int x, int y, int color);
int	put_line_in_img(t_game *game);
int	init_line(t_game *game);
int	get_color(int red, int green, int blue);
void	img_pix_put_2(t_game *game, int x, int y, int color, int i, int j);
int	image_tab_to_window(t_game *game);


#endif