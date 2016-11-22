/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/22 21:08:39 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

#define ROOM_ITER	0
#define LINK_ITER	1
#define CMD_ITER	2
#define CMT_ITER	3

int8_t	count_all(t_env *env)
{
	int		i;
	int8_t	ret_check_room;

	i = 1;
	env->index_map = (int *)ft_memalloc(sizeof(int) * env->nb_lines_map); // dont't forget to free !*/
	env->index_map[0] = ANTS;
	ft_fprintf(1, CYAN"%d\n"END, env->nb_ants);
	while (i < env->nb_lines_map)
	{
		if (ft_strstr(env->map[i], "-") != NULL && env->map[i][0] != '#') // exit function when a line link found
		{
			if (ft_strchr(env->map[i], ' ') != NULL)
				return (EXIT_ERROR_ROOM);
			env->index_map[i] = LINK;
			++i;
			++env->nb_link_line;
			continue ;
		}
		else if (check_if_is_command(env->map[i]) == EXIT_SUCCESS)
		{
			env->index_map[i] = CMD;
			++i;
			++env->nb_cmd_line;
			continue ;
		}
		else if (check_if_is_comment(env->map[i]) == EXIT_SUCCESS)
		{
			env->index_map[i] = CMT;
			++i;
			++env->nb_cmt_line;
			continue ;
		}
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
	return (EXIT_SUCCESS);
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
			ft_fprintf(1, YELLOW"%s\n"END, env->room[iter[ROOM_ITER]]);
			++iter[ROOM_ITER];
		}
		else if (env->index_map[i] == LINK)
		{
			env->link[iter[LINK_ITER]] = ft_strdup(env->map[i]);
			ft_fprintf(1, ORANGE"%s\n"END, env->link[iter[LINK_ITER]]);
			++iter[LINK_ITER];
		}
		else if (env->index_map[i] == CMD)
		{
			env->cmd[iter[CMD_ITER]] = ft_strdup(env->map[i]);
			ft_fprintf(1, RED"%s\n"END, env->cmd[iter[CMD_ITER]]);
			++iter[CMD_ITER];
		}
		else if (env->index_map[i] == CMT)
		{
			env->cmt[iter[CMT_ITER]] = ft_strdup(env->map[i]);
			ft_fprintf(1, PURPLE"%s\n"END, env->cmt[iter[CMT_ITER]]);
			++iter[CMT_ITER];
		}
		++i;
	}
	if (ft_strstr(env->cmd[0], env->cmd[1]) != NULL)
		return (EXIT_ERROR_CMD);
	return (EXIT_SUCCESS);
}

int8_t	alloc_room_link_cmt_cmd(t_env *env)
{
	env->room = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	env->link = (char **)ft_memalloc(sizeof(char *) * env->nb_link_line);
	env->cmd = (char **)ft_memalloc(sizeof(char *) * env->nb_cmd_line);
	env->cmt = (char **)ft_memalloc(sizeof(char *) * env->nb_cmt_line);
	if (fill_room_link_cmt_cmd(env) == EXIT_ERROR_CMD)
		return (EXIT_ERROR_CMD);
	return (EXIT_SUCCESS);
}

int8_t	stock_all(t_env *env)
{
	if (alloc_room_link_cmt_cmd(env) == EXIT_ERROR_CMD) // don't forget to free all !
		return (EXIT_ERROR_CMD);
	return (EXIT_SUCCESS);
}

