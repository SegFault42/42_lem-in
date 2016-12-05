/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/23 17:54:44 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

#define ROOM_ITER	0
#define LINK_		1
#define CMD_		2
#define CMT_		3

int8_t	count_all_2(t_env *env, int *i)
{
	if (ft_strstr(env->map[*i], "-") != NULL && env->map[*i][0] != '#')
	{
		if (ft_strchr(env->map[*i], ' ') != NULL)
			return (EXIT_ERROR_ROOM);
		env->index_map[*i] = LINK;
		++*i;
		++env->nb_link_line;
		return (true);
	}
	else if (check_if_is_command(env->map[*i]) == EXIT_SUCCESS)
	{
		env->index_map[*i] = CMD;
		++*i;
		++env->nb_cmd_line;
		return (true);
	}
	else if (check_if_is_comment(env->map[*i]) == EXIT_SUCCESS)
	{
		env->index_map[*i] = CMT;
		++*i;
		++env->nb_cmt_line;
		return (true);
	}
	return (false);
}

int8_t	count_all(t_env *env)
{
	int		i;
	int8_t	ret_check_room;

	i = 1;
	env->index_map = (int *)ft_memalloc(sizeof(int) * env->nb_lines_map);
	env->index_map[0] = ANTS;
	while (i < env->nb_lines_map)
	{
		if (count_all_2(env, &i) == true)
			continue ;
		ret_check_room = check_room_valid(env->map[i]);
		if (ret_check_room == EXIT_ERROR_ROOM)
			return (EXIT_ERROR_ROOM);
		else if (ret_check_room == EXIT_SUCCESS)
		{
			env->index_map[i] = ROOM;
			++env->nb_rooms_line;
		}
		++i;
	}
	if (check_nb_cmd(env) == EXIT_ERROR_CMD)
		return (EXIT_ERROR_CMD);
	if (check_nb_room(env) == EXIT_ERROR_ROOM)
		return (EXIT_ERROR_ROOM);
	return (EXIT_SUCCESS);
}

int8_t	parsing_map_stdin(t_env *env)
{
	int8_t	error;
	char	*ants;

	if (check_ants_valid(env) == EXIT_FAILURE)
		return (EXIT_ERROR_ANTS);
	error = count_all(env);
	ants = ft_itoa(env->nb_ants);
	env->print_map = fill_print_map(env->print_map, ants);
	free(ants);
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
	error = get_start_and_end(env);
	if (error == EXIT_ERROR_ROOM || error == EXIT_ERROR_CMD)
		return (EXIT_ERROR_CMD);
	get_room_only(env);
	stock_link_with_room(env);
	return (EXIT_SUCCESS);
}

void	fill_room_link_cmt_cmd_2(t_env *env, int *iter, int i)
{
	if (env->index_map[i] == LINK)
	{
		env->link[iter[LINK_]] = ft_strdup(env->map[i]);
		env->print_map = fill_print_map_nbn(env->print_map, "\e[38;5;208m");
		env->print_map = fill_print_map(env->print_map, env->link[iter[LINK_]]);
		env->print_map = fill_print_map_nbn(env->print_map, "\e[0m");
		++iter[LINK_];
	}
	else if (env->index_map[i] == CMD)
	{
		env->cmd[iter[CMD_]] = ft_strdup(env->map[i]);
		env->print_map = fill_print_map_nbn(env->print_map, "\e[31m");
		env->print_map = fill_print_map(env->print_map, env->cmd[iter[CMD_]]);
		env->print_map = fill_print_map_nbn(env->print_map, "\e[0m");
		++iter[CMD_];
	}
	else if (env->index_map[i] == CMT)
	{
		env->cmt[iter[CMT_]] = ft_strdup(env->map[i]);
		env->print_map = fill_print_map_nbn(env->print_map, "\e[35;5;208m");
		env->print_map = fill_print_map(env->print_map, env->cmt[iter[CMT_]]);
		env->print_map = fill_print_map_nbn(env->print_map, "\e[0m");
		++iter[CMT_];
	}
}

int8_t	fill_room_link_cmt_cmd(t_env *env)
{
	int	i;
	int	iter[4];

	i = 0;
	ft_memset(iter, 0, sizeof(int) * 4);
	while (i < env->nb_lines_map)
	{
		if (env->index_map[i] == ROOM)
		{
			env->room[iter[ROOM_ITER]] = ft_strdup(env->map[i]);
			env->print_map = fill_print_map_nbn(env->print_map, "\e[33;5;208m");
			env->print_map = fill_print_map(env->print_map,
			env->room[iter[ROOM_ITER]]);
			env->print_map = fill_print_map_nbn(env->print_map, "\e[0m");
			++iter[ROOM_ITER];
		}
		else
			fill_room_link_cmt_cmd_2(env, iter, i);
		++i;
	}
	if (ft_strstr(env->cmd[0], env->cmd[1]) != NULL)
		return (EXIT_ERROR_CMD);
	return (EXIT_SUCCESS);
}
