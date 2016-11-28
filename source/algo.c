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

void	looking_for_path(t_env *env)
{
	char	**path;
	char	**split;
	int		iter;
	int		i;
	int		j;
	int		k;


	i = 1;
	j = 0;
	k = 0;
	iter = env->nb_rooms_line -1;
	path = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	path[iter] = ft_strcdup(env->end, ' ');
	while (path[0] == NULL)
	{
		split = ft_strsplit(env->room_link[j], ',');
		ft_fprintf(1, RED"env->room_link[j] = %s\n"END, env->room_link[j]);
		while (split[i])
		{
			if (ft_strcmp(path[iter], split[i]) == 0)
			{
				ft_fprintf(1, CYAN"path[iter] = %s, split[i] = %s\n"END, path[iter], split[i]);
				iter--;
				path[iter] = ft_strdup(split[0]);
				i = 0;
				j = 0;
			}
			ft_fprintf(1, "path[iter] = %s, split[i] = %s\n", path[iter], split[i]);
			++i;
		}
		ft_2d_tab_free(split, 3);
		++j;
		i = 1;
	}
	path[0] = ft_strcdup(env->start, ' ');
	for(int a = 0; a < env->nb_rooms_line; ++a)
		ft_fprintf(1, PURPLE"%s\n"END, path[a]);
}

int8_t	algo(t_env *env)
{
	/*count_nb_link_by_room(env);*/
	/*stock_info_room(env);*/
	looking_for_path(env);
	return (EXIT_SUCCESS);
}
