/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/20 23:46:48 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_error_ants(char **map, int y_tab)
{
	ft_fprintf(2, RED"Ants : bad information\n"END);
	ft_2d_tab_free(map, y_tab);
	exit(EXIT_FAILURE);
}

void	print_error_room(char **map, int y_tab)
{
	ft_fprintf(2, RED"Room : bad information\n"END);
	ft_2d_tab_free(map, y_tab);
	exit(EXIT_FAILURE);
}

void	check_error_gnl(char **line)
{
	if (*line == NULL)
	{
		ft_fprintf(2, RED"GNL_EXIT_ERROR !\n"END);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_env	env;
	int8_t	ret;

	memset(&env, 0, sizeof(env));
	if (argc == 1)
		save_map(&env);
	/*else if (argc == 2)*/
		/*parsing_map_file(&env);*/
	ret = parsing_map_stdin(&env);
	if (ret == ERROR_ANTS)
		print_error_ants(env.map, env.nb_lines_map);
	else if (ret == ERROR_ROOM)
		print_error_room(env.map, env.nb_lines_map);
	ft_2d_tab_free(env.map, env.nb_lines_map);
	(void)argc;
	(void)argv;
}
