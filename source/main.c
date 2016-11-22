/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/22 14:31:15 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_error(char **map, int y_tab, int8_t err_num)
{
	if (err_num == EXIT_ERROR_ANTS)
		ft_fprintf(2, RED"Ants : bad information\n"END);
	if (err_num == EXIT_ERROR_ROOM)
		ft_fprintf(2, RED"Room : bad information\n"END);
	if (err_num == EXIT_ERROR_CMD)
		ft_fprintf(2, RED"CMD : bad information\n"END);
	if (err_num == EXIT_ERROR_LINK)
		ft_fprintf(2, RED"LINK : bad information\n"END);
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

int8_t	check_multiple_same_rooms(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < env->nb_rooms_line)
	{
		j++;
		while (j < env->nb_rooms_line)
		{
			if (ft_strcmp(env->room[i], env->room[j]) == 0)
				return (EXIT_ERROR_ROOM);
			++j;
		}
		++i;
		j = i;
	}
	return (EXIT_SUCCESS);
}

int8_t	parsing_map_stdin(t_env *env)
{
	int8_t	error;

	if (check_ants_valid(env) == EXIT_FAILURE)
		return (EXIT_ERROR_ANTS);
	error = count_all(env);
	if (error == EXIT_ERROR_CMD)
		return (EXIT_ERROR_CMD);
	else if (error == EXIT_ERROR_ROOM)
		return (EXIT_ERROR_ROOM);
	if (stock_all(env) == EXIT_ERROR_CMD)
		return (EXIT_ERROR_CMD);
	if (check_multiple_same_rooms(env) == EXIT_ERROR_ROOM)
		return (EXIT_ERROR_ROOM);
	if (parsing_link(env) == EXIT_ERROR_LINK)
		return (EXIT_ERROR_LINK);
	/*if (check_multiple_same_rooms(env))*/
		/*return (EXIT_ERROR_ROOM);*/

	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_env	env;
	int8_t	ret;

	ret = 0;
	memset(&env, 0, sizeof(env));
	if (argc == 1)
		save_map(&env);
	/*else if (argc == 2)*/
		/*parsing_map_file(&env);*/
	ret = parsing_map_stdin(&env);
	if (ret >= EXIT_ERROR_LINK && ret <= EXIT_ERROR_CMD)
		print_error(env.map, env.nb_lines_map, ret);
	ft_2d_tab_free(env.map, env.nb_lines_map);
	(void)argc;
	(void)argv;
}
