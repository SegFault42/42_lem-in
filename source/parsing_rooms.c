/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:05:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/20 22:57:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_split_line(char *line, t_env *env)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	i = ft_count_2d_tab(split);
	if (i != 3)
	{
		ft_2d_tab_free(split, i);
		return (EXIT_FAILURE);
	}
	/*env->nb_room_line++;*/
	ft_2d_tab_free(split, i);
	(void)env;
	return (EXIT_SUCCESS);
}

int8_t	check_forbidden_charctere(char *line)
{
	if (line[0] == '#' || line[0] == 'L' || line[0] == '-') // forbidden charactere
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

int8_t	check_room_valid(char *line, t_env *env)
{
	if (check_forbidden_charctere(line) == EXIT_ERROR)
		return (EXIT_ERROR);
	if (check_split_line(line, env) == EXIT_ERROR)
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

int8_t	check_if_is_comment(char *line)
{
	if (line[0] == '#' && ft_strcmp(line, "##start") != 0 && ft_strcmp(line, "##end") != 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int8_t	check_if_is_command(char *line)
{
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int8_t	count_all(t_env *env)
{
	int		i;
	int8_t	ret_check_room;

	i = 1;
	env->index_map = (int *)ft_memalloc(sizeof(int) * env->nb_lines_map); // dont't forget to free !*/
	env->index_map[0] = ANTS;
	while (i < env->nb_lines_map)
	{
		if (ft_strstr(env->map[i], "-") != NULL && env->map[i][0] != '#') // exit function when a line link found
		{
			env->index_map[i] = LINK;
			++i;
			continue ;
		}
		if (check_if_is_command(env->map[i]) == EXIT_SUCCESS)
		{
			env->index_map[i] = CMD;
			++i;
			continue ;
		}
		if (check_if_is_comment(env->map[i]) == EXIT_SUCCESS)
		{
			env->index_map[i] = CMT;
			++i;
			continue ;
		}
		ret_check_room = check_room_valid(env->map[i], env);
		if (ret_check_room == EXIT_ERROR)
			return (EXIT_ERROR);
		else if (ret_check_room == EXIT_SUCCESS)
			env->index_map[i] = ROOM;
		++i;
	}
	for(int k = 0; k < env->nb_lines_map; k++)
		ft_fprintf(1, "%d\n", env->index_map[k]);
	return (EXIT_SUCCESS);
}
