/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/23 19:45:48 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	create_link_only(t_env *env, char **link_only)
{
	char	**split;
	int		i;
	int		j;
	int		iter;

	split = NULL;
	i = 0;
	j = 0;
	iter = 0;
	while (i < env->nb_link_line)
	{
		split = ft_strsplit(env->link[i], '-');
		while (split[iter])
		{
			link_only[j] = split[iter];
			++iter;
			++j;
		}
		++i;
		iter = 0;
	}
}

void		check_if_room_exist(t_env *env)
{
	int		i;
	int		j;
	char	**link_only;
	int		iter;

	i = 0;
	j = 0;
	iter = 0;
	link_only = (char **)ft_memalloc(sizeof(char *) * (env->nb_link_line * 2));
	create_link_only(env, link_only);
	while (i < env->nb_link_line * 2)
	{
		while (j < env->nb_rooms_line)
		{
			if (ft_strccmp(link_only[i], env->room_only[j], ' ') == 0)
				break ;
			++j;
			if (j >= env->nb_rooms_line)
				print_simple_error();
		}
		++i;
		j = 0;
	}
	ft_2d_tab_free(link_only, env->nb_link_line * 2);
}

static void	check_if_start_and_and_are_connected_2(t_env *env, char *start)
{
	int		i;

	i = 0;
	while (ft_strccmp(start, env->room_link[i], ',') != 0)
	{
		i++;
		if (i >= env->nb_rooms_line)
			print_simple_error();
	}
}

int8_t		check_if_start_and_and_are_connected(t_env *env)
{
	int		i;
	char	**split;
	char	*start;
	char	*end;

	i = 0;
	start = ft_strcdup(env->start, ' ');
	end = ft_strcdup(env->end, ' ');
	check_if_start_and_and_are_connected_2(env, start);
	split = ft_strsplit(env->room_link[i], ',');
	while (split[i])
	{
		if (ft_strcmp(end, split[i]) == 0)
		{
			free(start);
			free(end);
			ft_2d_tab_free(split, ft_count_2d_tab(split));
			return (true);
		}
		++i;
	}
	free(start);
	free(end);
	ft_2d_tab_free(split, ft_count_2d_tab(split));
	return (false);
}
