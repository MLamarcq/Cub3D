/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:16:46 by gael              #+#    #+#             */
/*   Updated: 2023/05/31 13:12:41 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_env(char **envp)
{
	int	ite_env;
	int	is_path;

	is_path = 0;
	ite_env = 0;
	while (envp[ite_env])
	{
		if (ft_strncmp(envp[ite_env], "PATH=", 5) == 0)
			is_path++;
		ite_env++;
	}
	if (is_path)
		return (SUCCESS);
	return (FAIL);
}

int	ft_parsing(t_game *game, char **argv)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (0);
	game->map->check_letters.letter_c = 0;
	game->map->check_letters.letter_e = 0;
	game->map->check_letters.letter_p = 0;
	game->map->map_build = NULL;
	game->map->map_org = NULL;
	game->map->map_chck = NULL;
	if (ft_check_ext(argv[1]) == FAIL)
		return (ft_free_parsing(game, "wrong filename extension\n"), FAIL);
	if (ft_read_file(game, argv[1]) == FAIL)
		return (FAIL);
	if (ft_check_rectangular(game) == FAIL)
		return (FAIL);
	if (ft_nbr_letters(game) == FAIL)
		return (FAIL);
	if (ft_if_wall(game) == FAIL)
		return (ft_free_parsing(game, "there are some leaks on walls\n"), FAIL);
	if (ft_wrong_letters(game) == FAIL)
		return (ft_free_parsing(game,
				"Letters allowed on your map : P, C, E, 0, 1\n"), FAIL);
	if (ft_valid_path(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	ft_create_game(t_game *game)
{
	ft_display_map(game);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_game	game;

	if (ft_check_env(envp) == FAIL)
		return (ft_putstr_fd("Error\nyou must have env. variables\n", 2), 1);
	if (argc != 2)
		return (ft_putstr_fd("Error\nyou must called one arg\n", 2), 1);
	if (ft_parsing(&game, argv) == FAIL)
		return (1);
	ft_create_game(&game);
	return (0);
}
