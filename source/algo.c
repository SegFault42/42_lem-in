/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:00:29 by rabougue          #+#    #+#             */
/*   Updated: Mon Nov 28 22:45:27 2016                                        */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_if_path_ok(char **split, char **path, t_env *env, int k)
{
	int	i;
	int	j;

	i = env->nb_rooms_line;
	j = 0;
	while (path[i])
	{
		ft_fprintf(1, GREEN"%s, %s\n"END, split[k], path[i]);
		if (ft_strcmp(split[k], path[i]) == 0)
		{
			return (true);
		}
		--i;
	}
	(void)split;
	(void)path;
	(void)env;
	return (false);
}

void	looking_for_path(t_env *env)
{
	char	**path;
	char	**split;
	char	**split_b;
	int		iter;
	int		i;
	int		j;
	int		k;

	int l = env->nb_rooms_line -1 ;
	i = 0;
	j = 0;
	k = 1;
	iter = env->nb_rooms_line -1;
	path = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	path[iter] = ft_strcdup(env->end, ' ');
	while (j < env->nb_rooms_line)
	{
		split_b = ft_strsplit(env->room_link[j], ',');
		if (ft_strncmp(split_b[0], env->start, ft_strlen(split_b[0])) == 0)
			break ;
		++j;
	}
	j = 0;
	ft_fprintf(1, GREEN"%s\n"END, split_b[0]);
	while (path[0] == NULL)
	{
		split = ft_strsplit(env->room_link[j], ',');
		ft_fprintf(1, "%s\n", env->room_link[j]);
		while (split[i])
		{
			/*if (check_if_path_ok(split, path, env, k) == true)*/
				/*++k;*/
			while (path[l])
			{
				if (ft_strcmp(path[l], split[k]) == 0)
					k++;
				--l;
			}
			if (ft_strcmp(split[0], path[iter]) == 0)
			{
				iter--;
				path[iter] = ft_strdup(split[k]);
				j = -1;
				k = 1;
				l = env->nb_rooms_line -1;
				if (ft_strccmp(path[iter], env->start, ' ') == 0)
				{
					for(int a = 0; a < env->nb_rooms_line; ++a)
						ft_fprintf(1, PURPLE"%s\n"END, path[a]);
					return ;
				}
			}
			i++;
		}
		/*ft_2d_tab_free(split, len_tab);*/
		++j;
		i = 0;
	}
	/*for(int a = 0; a < env->nb_rooms_line; ++a)*/
		/*ft_fprintf(1, PURPLE"%s\n"END, path[a]);*/
}

int8_t	algo(t_env *env)
{
	/*count_nb_link_by_room(env);*/
	/*stock_info_room(env);*/
	looking_for_path(env);
	return (EXIT_SUCCESS);
}
