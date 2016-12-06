/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/23 19:45:48 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_if_start_found(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_rooms_line)
	{
		while (env->path[i] == NULL)
			++i;
		if (ft_strccmp(env->path[i], env->start, ' ') == 0)
			return (true);
		++i;
	}
	return (false);
}

int8_t	check_if_room_is_already_stored(t_env *env, int iter)
{
	int	i;

	i = 0;
	while (i < env->nb_rooms_line)
	{
		while (env->path[i] == NULL)
			++i;
		if (env->split_path[iter] == NULL)
		{
			ft_fprintf(2, RED"No path found\n"END);
			exit(EXIT_FAILURE);
		}
		if (ft_strcmp(env->path[i], env->split_path[iter]) == 0)
			return (true);
		++i;
	}
	return (false);
}

int8_t	looking_for_connected_room(t_env *env, int iter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strccmp(env->path[iter], env->room_link[i], ',') != 0)
	{
		i++;
		if (env->room_link[i] == NULL)
			print_simple_error();
	}
	while (j < env->nb_rooms_line)
	{
		while (env->path[j] == NULL)
			++j;
		if (ft_strccmp(env->path[j], env->room_link[i], ',') == 0)
		{
			env->split_path = ft_strsplit(env->room_link[i], ',');
			return (true);
		}
		++j;
	}
	return (false);
}

void	looking_for_path(t_env *env)
{
	int		iter;
	int		i;

	iter = env->nb_rooms_line - 1;
	env->path = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	env->path[iter] = ft_strcdup(env->end, ' ');
	if (check_if_start_and_and_are_connected(env) == true)
	{
		env->path[--iter] = ft_strcdup(env->start, ' ');
		return ;
	}
	while (check_if_start_found(env) == false)
	{
		i = 1;
		if (looking_for_connected_room(env, iter) == true)
		{
			while (check_if_room_is_already_stored(env, i) == true)
				i++;
			--iter;
			env->path[iter] = ft_strdup(env->split_path[i]);
			ft_2d_tab_free(env->split_path, ft_count_2d_tab(env->split_path));
		}
	}
}

int8_t	algo(t_env *env)
{
	check_if_room_exist(env);
	looking_for_path(env);
	return (EXIT_SUCCESS);
}
