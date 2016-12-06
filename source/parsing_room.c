/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:05:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/25 20:48:12 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	get_room_only(t_env *env)
{
	int		i;
	char	**tmp;

	i = 0;
	env->room_only = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	while (i < env->nb_rooms_line)
	{
		env->room_only[i] = (char *)ft_memalloc(sizeof(char) *
		(ft_strclen(env->room[i], ' ')));
		tmp = ft_strsplit(env->room[i], ' ');
		ft_strcpy(env->room_only[i], tmp[0]);
		ft_2d_tab_free(tmp, ft_count_2d_tab(tmp));
		++i;
	}
}

int8_t	check_if_room_is_stocked(char *room_link)
{
	char	**split;
	int		i;
	int		j;

	j = 0;
	i = 0;
	split = ft_strsplit(room_link, ',');
	while (split[i])
	{
		j = 0;
		while (split[j])
		{
			ft_fprintf(1, "split[j] = %s, split[i] = %s\n", split[i], split[j]);
			if (ft_strcmp(split[i], split[j]) == 0)
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

void	stock_link_with_room_2(t_env *env, int *i)
{
	int		j;
	char	*room;
	char	**link;

	j = 0;
	room = ft_strdup(env->room_only[*i]);
	while (j < env->nb_link_line)
	{
		link = ft_strsplit(env->link[j], '-');
		if (ft_strcmp(room, link[0]) == 0)
		{
			ft_strcat(env->room_link[*i], ",");
			ft_strcat(env->room_link[*i], link[1]);
		}
		else if (ft_strcmp(room, link[1]) == 0)
		{
			ft_strcat(env->room_link[*i], ",");
			ft_strcat(env->room_link[*i], link[0]);
		}
		++j;
		ft_2d_tab_free(link, 3);
	}
	free(room);
}

void	stock_link_with_room(t_env *env)
{
	int	i;

	i = 0;
	env->room_link = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	while (i < env->nb_rooms_line)
	{
		env->room_link[i] = (char *)ft_memalloc(sizeof(char ) * 1000);
		ft_strcat(env->room_link[i], env->room_only[i]);
		stock_link_with_room_2(env, &i);
		++i;
	}
}
