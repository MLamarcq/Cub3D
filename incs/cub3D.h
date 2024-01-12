/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:45:40 by ggosse            #+#    #+#             */
/*   Updated: 2023/08/07 12:56:57 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

// ------------------------------ include ----------------------------------- //
# include "../libft/libft.h"
# include "color.h"
# include <math.h>
# include "../minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
// ---------------------------- end include --------------------------------- //

// ------------------------------ define ------------------------------------ //
# define SUCCESS 1
# define FAIL -1
// ---------------------------- end define ---------------------------------- //

// ------------------------------ struct ------------------------------------ //

typedef struct s_xpm
{
	char	*no_file_content;
	char	*no_file_map;
	char	**no_tab_file;
	int		**no_colors;
	int		*no_metadata;
	int		no_width_height;
	int		no_tab_start;
	char	*ea_file_content;
	char	*ea_file_map;
	char	**ea_tab_file;
	int		**ea_colors;
	int		*ea_metadata;
	int		ea_width_height;
	int		ea_tab_start;
	char	*we_file_content;
	char	*we_file_map;
	char	**we_tab_file;
	int		**we_colors;
	int		*we_metadata;
	int		we_width_height;
	int		we_tab_start;
	char	*so_file_content;
	char	*so_file_map;
	char	**so_tab_file;
	int		**so_colors;
	int		*so_metadata;
	int		so_width_height;
	int		so_tab_start;
}	t_xpm;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		steps;
	double	xite;
	double	yite;
	double	corr_x;
	double	corr_y;
	int		x_src;
	int		y_src;
	int		x_dest;
	int		y_dest;
	int		x_dest_prev;
	int		y_dest_prev;
	int		check_x;
	int		check_y;
	int		new_x;
	int		new_y;
}	t_line;

typedef struct s_temp
{
	int		dx;
	int		dy;
	int		steps;
	double	xite;
	double	yite;
	double	corr_x;
	double	corr_y;
	int		x_src;
	int		y_src;
	int		x_dest;
	int		y_dest;
	int		x_dest_prev;
	int		y_dest_prev;
}	t_temp;

typedef struct s_line_3d
{
	int		dx;
	int		dy;
	int		steps;
	double	xite;
	double	yite;
	double	corr_x;
	double	corr_y;
	int		x_src;
	int		y_src;
	int		x_dest;
	int		y_dest;
	int		x_dest_prev;
	int		y_dest_prev;
}	t_line_3d;

typedef struct s_map
{
	char	*file_content;
	char	*file_map;
	char	**tab_file;
	char	**map_tmp;
	char	**map_org;
	char	*wall_no;
	char	*wall_ea;
	char	*wall_so;
	char	*wall_we;
	int		*floor;
	int		*ceil;
	int		height;
	int		width;
	int		pos_y;
	int		pos_x;
	int		count_step;
	int		fd_map;
	int		north;
	int		south;
	int		east;
	int		west;
}			t_map;

typedef struct s_fov
{
	double	**wall_witch;
	int		**wall;
	int		*lines_vision;
	int		*toggle_vision;
	int		angle;
	int		nbr_ray;
	int		proj_plane;
	double	deg;
	char	toggle;
}			t_fov;

typedef struct s_game
{
	int			display_all_save_src_x;
	int			display_all_save_src_y;
	int			display_all_save_x;
	int			display_all_save_y;
	double		display_all_angle;
	double		display_all_angle_2;
	int			display_all_i_rotate;
	int			flag;
	int			view_angle;
	int			img_size;
	char		perso;
	void		*mlibx;
	void		*window;
	int			win_height;
	int			win_width;
	t_map		*map;
	t_img		*img;
	t_xpm		*xpm;
	t_line		*line;
	t_fov		*fov;
	t_line_3d	*line_3d;
	t_temp		*temp;
}			t_game;
// ---------------------------- end struct ---------------------------------- //

//srcs/xpm_so_parse.c
int		xpm_so_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_so_parse(t_game *game);
int		xpm_so_read(t_game *game, char *filename);
int		xpm_so_split_buf(int fd, t_game *game);
//srcs/draw_xpm_ud.c
int		draw_xpm_down_blue(t_game *game, int i_midline);
int		draw_xpm_down_red(t_game *game, int i_midline);
int		draw_xpm_up_blue(t_game *game, int i_midline);
int		draw_xpm_up_red(t_game *game, int i_midline);
//srcs/main.c
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		open_fd(t_game *game, int *fd, char **argv);
//srcs/pixel_and_color.c
int		get_color(int red, int green, int blue);
void	img_pix_put(t_game *game, int x, int y, int color);
//srcs/draw_xpm_ud_utils.c
void	adjust_line_3d(t_game *game);
void	draw_xpm_if_blue(t_game *game, int i);
void	draw_xpm_if_red(t_game *game, int i);
//srcs/xpm_we_correction.c
int		xpm_we_copy_tab(t_game *game, char **tmp);
int		xpm_we_correct(t_game *g);
int		xpm_we_read_1line(t_game *game);
int		xpm_we_wo_comm(t_game *g, int n_comm);
//srcs/key_tools.c
int		calcul_step_for_key_a(t_game *game);
int		calcul_step_for_key_d(t_game *game);
void	check_for_wall_a(t_game *game);
void	check_for_wall_d(t_game *game);
//srcs/free_xpm_2.c
void	free_tab_colors_ea(t_game *game, int i);
void	free_tab_colors_no(t_game *game, int i);
void	free_tab_colors_so(t_game *game, int i);
void	free_tab_colors_we(t_game *game, int i);
//srcs/xpm_no_utils.c
int		xpm_no_check_wh(t_game *game);
void	xpm_no_fill_metadata(t_game *game, char **line);
int		xpm_no_init_color(t_game *g);
char	*xpm_no_keep_metadata(char **tmp, int i_tmp);
//srcs/start_3D.c
int		first_time(t_game *game);
void	reset_img(t_game *game);
int		start_3d(t_game *game);
//srcs/display_all_blue.c
void	display_all_blue(t_game *g, int i_rotate, int len_vision);
void	display_all_blue_first(t_game *game, int i_rotate, int len_vision);
void	display_all_blue_second(t_game *game, int i_rotate, int len_vision);
//srcs/draw_xpm_down_ea.c
void	draw_xpm_down_ea(t_game *game, int i_midline);
int		draw_xpm_ea_color(t_game *game, int x, int y);
//srcs/xpm_no_colors.c
int		xpm_no_check_line_color(t_game *g, int *i_chr, int i_tab_file, \
int i_color);
int		xpm_no_hex_to_dec(t_game *g, int i_color, int i_tab_file, int i_chr);
int		xpm_no_letter_color(t_game *game, int i_color, int i_tab_file, \
int i_chr);
int		xpm_no_set_color(t_game *game, int i_color, char *tmp);
int		xpm_no_set_len_n_color(t_game *g, char **line);
//srcs/xpm_we_colors.c
int		xpm_we_check_line_color(t_game *g, int *i_chr, \
int i_tab_file, int i_color);
int		xpm_we_hex_to_dec(t_game *g, int i_color, int i_tab_file, int i_chr);
int		xpm_we_letter_color(t_game *game, int i_color, \
int i_tab_file, int i_chr);
int		xpm_we_set_color(t_game *game, int i_color, char *tmp);
int		xpm_we_set_len_n_color(t_game *g, char **line);
//srcs/draw_line.c
int		check_lines_hit_wall(t_game *game, int x_check, \
int y_check, int toggle);
int		draw_line_vision(t_game *game);
int		draw_pixel(t_game *game, int toggle);
int		init_line(t_game *game);
//srcs/free_parsing.c
int		destroy_and_free(t_game *game, char *err);
int		destroy_and_free2(t_game *game);
void	free_parsing(t_game *game, char *err);
void	free_tab_str(char **tab_str);
void	free_wall(t_game *game);
//srcs/display_3d_up.c
void	display_3d_up(t_game *game);
void	display_3d_up_red(t_game *game, int i_main);
void	fill_ceil_floor(t_game *game);
void	fill_ceil_floor_2(t_game *game);
int		init_3d_line(t_game *game);
//srcs/xpm_so_utils.c
int		xpm_so_check_wh(t_game *game);
void	xpm_so_fill_metadata(t_game *game, char **line);
int		xpm_so_init_color(t_game *g);
char	*xpm_so_keep_metadata(char **tmp, int i_tmp);
//srcs/key_move.c
int		key_is_a(t_game *game, int key);
int		key_is_d(t_game *game, int key);
void	key_is_s(t_game *game, int key);
void	key_is_w(t_game *g, int key);
//srcs/free_all.c
int		free_all(t_game *game);
int		free_ceil_floor(t_game *game);
void	free_fov(t_game *game);
//srcs/free_xpm.c
void	free_xpm(t_game *game);
void	free_xpm_ea(t_game *game, int i);
void	free_xpm_no(t_game *game, int i);
void	free_xpm_so(t_game *game, int i);
void	free_xpm_we(t_game *game, int i);
//srcs/xpm_so_correction.c
int		xpm_so_copy_tab(t_game *game, char **tmp);
int		xpm_so_correct(t_game *g);
int		xpm_so_read_1line(t_game *game);
int		xpm_so_wo_comm(t_game *g, int n_comm);
//srcs/flooding.c
int		flooding(t_game *game);
int		is_propa_finished(t_game *game);
int		propagation(t_game *game, int row, int col, int count);
//srcs/texture_part_utils.c
int		check_tx(t_game *game);
//srcs/valid_wall.c
int		check_letters_map(t_game *game);
int		check_perso(t_game *game);
int		hole_in_wall(t_game *game);
int		is_fault(t_game *game, int row, int col);
//srcs/build_map.c
void	build_content(t_game *game, char **line, int fd);
int		build_map(t_game *game, char **argv, int count, int fd);
int		create_map(t_game *game, char *line, int fd);
void	realloc_lines(t_game *game);
void	skip_empty_line(char **line, int fd);
//srcs/read_file.c
int		ft_buf_read(int fd, t_game *game);
int		ft_read_file(t_game *game, char *filename);
//srcs/xpm_we_utils.c
int		xpm_we_check_wh(t_game *game);
void	xpm_we_fill_metadata(t_game *game, char **line);
int		xpm_we_init_color(t_game *g);
char	*xpm_we_keep_metadata(char **tmp, int i_tmp);
//srcs/display_3d_down.c
void	display_3d(t_game *game);
void	display_3d_down(t_game *game);
void	display_3d_down_red(t_game *game, int i_main);
//srcs/key_rotate.c
void	key_rotate_left(t_game *game, int key);
void	key_rotate_right(t_game *game, int key);
//srcs/display_3d_down_utils.c
void	draw_line_3d_down(t_game *game, int i_main, int i_midline);
void	i_draw_blue(t_game *game, int i_midline);
void	i_draw_red(t_game *game, int i_midline);
//srcs/fov.c
int		init_fov(t_game *game);
int		init_fov_wall(t_game *game);
int		init_fov_wall_witch(t_game *game);
void	init_position(t_game *game);
//srcs/draw_xpm_down_we.c
void	draw_xpm_down_we(t_game *game, int i_midline);
int		draw_xpm_we_color(t_game *game, int x, int y);
//srcs/xpm_so_dual.c
int		xpm_so_check_dual_colors(t_game *g, int *i_chr, int i_tab_file, \
int i_color);
int		xpm_so_dual(t_game *game);
int		xpm_so_dual_letter(t_game *game, int i_color, int i_tab_file, \
int i_chr);
int		xpm_so_hex_to_dec_dual(t_game *g, int i_color, int i_tab_file, \
int i_chr);
int		xpm_so_set_dual_color(t_game *game, int i_color, char *tmp);
//srcs/display_all_red.c
void	display_all_red(t_game *game, int i_rotate, int len_vision);
void	display_all_red_first(t_game *game, int i_rotate, int len_vision);
void	display_all_red_second(t_game *game, int i_rotate, int len_vision);
void	display_all_red_third(t_game *game, int i_rotate, int len_vision);
//srcs/build_map_utils.c
int		check_nbr(char *str);
int		is_empty_line(char *line);
void	set_width(t_game *game);
int		tab_len(char **arr);
//srcs/texture_part.c
int		check_ea(t_game *game, char *line);
int		check_no(t_game *game, char *line);
int		check_so(t_game *game, char *line);
int		check_we(t_game *game, char *line);
int		texture_part(t_game *game, char *line);
//srcs/draw_xpm_up_ea.c
void	draw_xpm_up_ea(t_game *game, int i_midline);
int		draw_xpm_up_ea_color(t_game *game, int x, int y);
//srcs/xpm_ea_utils.c
int		xpm_ea_check_wh(t_game *game);
void	xpm_ea_fill_metadata(t_game *game, char **line);
int		xpm_ea_init_color(t_game *g);
char	*xpm_ea_keep_metadata(char **tmp, int i_tmp);
//srcs/display_all.c
int		display_all(t_game *g, int key);
void	last_correct_toggle(t_game *game);
void	mid_display_all(t_game *game, int i_rotate, int len_vision);
void	set_toggle(t_game *g, int i_rotate);
//srcs/tools.c
double	abs_dble(double nb);
double	abs_flt(double nb);
int		absolute_value(int nb);
double	deg_to_radian(double deg);
int		hex_to_dec(char *hexa);
//srcs/display_all_utils.c
int		init_display_all(t_game *game, int key, int *len_side);
void	move_straight(t_game *game);
void	rotate_new(t_game *game);
//srcs/player.c
int		ft_event_listen(int key, t_game *game);
void	set_pos_character(t_game *game);
//srcs/xpm_common.c
void	init_second_xpm(t_game *game);
int		init_xpm(t_game *game);
int		is_space(char chr);
int		xpm_check_width(t_game *game);
int		xpm_parse(t_game *game);
//srcs/xpm_ea_parse.c
int		xpm_ea_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_ea_parse(t_game *game);
int		xpm_ea_read(t_game *game, char *filename);
int		xpm_ea_split_buf(int fd, t_game *game);
//srcs/draw_xpm_up_we.c
void	draw_xpm_up_we(t_game *g, int i_midline);
int		draw_xpm_up_we_color(t_game *game, int x, int y);
//srcs/draw_xpm_down_so.c
void	draw_xpm_down_so(t_game *game, int i_midline);
int		draw_xpm_so_color(t_game *game, int x, int y);
//srcs/xpm_no_correction.c
int		xpm_no_copy_tab(t_game *game, char **tmp);
int		xpm_no_correct(t_game *g);
int		xpm_no_read_1line(t_game *game);
int		xpm_no_wo_comm(t_game *g, int n_comm);
//srcs/draw_xpm_down_no.c
void	draw_xpm_down_no(t_game *game, int i_midline);
int		draw_xpm_no_color(t_game *game, int x, int y);
//srcs/xpm_no_dual.c
int		xpm_no_check_dual_colors(t_game *g, int *i_chr, int i_tab_file, \
int i_color);
int		xpm_no_dual(t_game *game);
int		xpm_no_dual_letter(t_game *game, int i_color, int i_tab_file, \
int i_chr);
int		xpm_no_hex_to_dec_dual(t_game *g, int i_color, int i_tab_file, \
int i_chr);
int		xpm_no_set_dual_color(t_game *game, int i_color, char *tmp);
//srcs/draw_xpm_up_no.c
void	draw_xpm_up_no(t_game *g, int i_midline);
int		draw_xpm_up_no_color(t_game *game, int x, int y);
//srcs/xpm_no_parse.c
int		xpm_no_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_no_parse(t_game *game);
int		xpm_no_read(t_game *game, char *filename);
int		xpm_no_split_buf(int fd, t_game *game);
//srcs/check_file.c
int		check_env(char **envp);
int		check_ext(char *filename, char one, char two, char three);
int		wrong_letter_tx(char *line);
//srcs/init_img.c
int		create_image_and_get_adrr(t_game *game);
int		init_img(t_game *game);
//srcs/move_w_s.c
int		calcul_corr_for_step(t_game *game);
void	init_direction_for_s(t_game *game);
void	init_direction_for_s_2(t_game *game);
void	move_s(t_game *game);
void	move_w(t_game *game);
//srcs/floor_ceil_part.c
int		check_ceil(t_game *game, char *line, char *color);
int		check_ceil_content(t_game *g, char **color);
int		check_floor(t_game *game, char *line, char *color);
int		check_floor_content(t_game *g, char **color);
int		floor_ceil_part(t_game *game, char *line);
//srcs/xpm_we_parse.c
int		xpm_we_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_we_parse(t_game *game);
int		xpm_we_read(t_game *game, char *filename);
int		xpm_we_split_buf(int fd, t_game *game);
//srcs/display_3d_up_utils.c
void	draw_line_3d_up(t_game *game, int i_main, int i_midline);
void	i_draw_up_blue(t_game *game, int i_midline);
void	i_draw_up_red(t_game *game, int i_midline);
//srcs/xpm_so_colors.c
int		xpm_so_check_line_color(t_game *g, int *i_chr, int i_tab_file, \
int i_color);
int		xpm_so_hex_to_dec(t_game *g, int i_color, int i_tab_file, \
int i_chr);
int		xpm_so_letter_color(t_game *game, int i_color, int i_tab_file, \
int i_chr);
int		xpm_so_set_color(t_game *game, int i_color, char *tmp);
int		xpm_so_set_len_n_color(t_game *g, char **line);
//srcs/angle_len.c
void	angle_1(t_game *game, double angle_2, int len_vision);
void	angle_3(t_game *game, double angle_2, int len_vision);
void	angle_4(t_game *game, double angle_2, int len_vision);
//srcs/check_format.c
void	check_corner(t_game *game);
void	check_wall_in_map_1(t_game *game, int i_big, int i_lil);
void	check_wall_in_map_2(t_game *game, int i_big, int i_lil);
//srcs/xpm_ea_dual.c
int		xpm_ea_check_dual_colors(t_game *g, int *i_chr, int i_tab_file, \
int i_color);
int		xpm_ea_dual(t_game *game);
int		xpm_ea_dual_letter(t_game *game, int i_color, int i_tab_file, \
int i_chr);
int		xpm_ea_hex_to_dec_dual(t_game *g, int i_color, int i_tab_file, \
int i_chr);
int		xpm_ea_set_dual_color(t_game *game, int i_color, char *tmp);
//srcs/xpm_we_dual.c
int		xpm_we_check_dual_colors(t_game *g, int *i_chr, int i_tab_file, \
int i_color);
int		xpm_we_dual(t_game *game);
int		xpm_we_dual_letter(t_game *game, int i_color, int i_tab_file, \
int i_chr);
int		xpm_we_hex_to_dec_dual(t_game *g, int i_color, int i_tab_file, \
int i_chr);
int		xpm_we_set_dual_color(t_game *game, int i_color, char *tmp);
//srcs/draw_xpm_up_so.c
void	draw_xpm_up_so(t_game *g, int i_midline);
int		draw_xpm_up_so_color(t_game *game, int x, int y);
//srcs/xpm_ea_correction.c
int		xpm_ea_copy_tab(t_game *game, char **tmp);
int		xpm_ea_correct(t_game *g);
int		xpm_ea_read_1line(t_game *game);
int		xpm_ea_wo_comm(t_game *g, int n_comm);
//srcs/xpm_ea_colors.c
int		xpm_ea_check_line_color(t_game *g, int *i_chr, int i_tab_file, \
int i_color);
int		xpm_ea_hex_to_dec(t_game *g, int i_color, int i_tab_file, int i_chr);
int		xpm_ea_letter_color(t_game *game, int i_color, int i_tab_file, \
int i_chr);
int		xpm_ea_set_color(t_game *game, int i_color, char *tmp);
int		xpm_ea_set_len_n_color(t_game *g, char **line);

#endif