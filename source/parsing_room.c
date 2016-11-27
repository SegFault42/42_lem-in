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
	int	i;
	int	len;
	char **tmp;

	i = 0;
	len = 0;
	tmp = (char **)ft_memalloc(sizeof(char *));
	env->room_only = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	while (i < env->nb_rooms_line)
	{
		len += ft_strlen(env->room[i]);
		++i;
	}
	len += i;
	i = 0;
	while (i < env->nb_rooms_line)
	{
		env->room_only[i] = (char *)ft_memalloc(sizeof(char) * (env->nb_rooms_line * len));
		tmp = ft_strsplit(env->room[i], ' ');
		ft_strcpy(env->room_only[i], tmp[0]);
		/*ft_fprintf(1, PURPLE"%s\n"END, env->room_only[i]);*/
		++i;
		free(tmp[0]);
	}
}

int8_t	check_if_room_is_stocked(char *room_link, char *link)
{
	char	**split;
	int		i;
	int		j;

	j = 0;
		i = 0;
	split = ft_strsplit(room_link, ',');
	while(split[i])
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
	(void)link;
	(void)room_link;
}

void	stock_link_with_room(t_env *env)
{
	int	i;
	int	j;
	char	**link;
	char	*room;

	i = 0;
	env->room_link = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	while (i < env->nb_rooms_line)
	{
		env->room_link[i] = (char *)ft_memalloc(sizeof(char ) * 1000);
		ft_strcat(env->room_link[i], env->room_only[i]);
		j = 0;
		room = ft_strdup(env->room_only[i]);
		while (j < env->nb_link_line)
		{
			link = ft_strsplit(env->link[j], '-');
			if (ft_strcmp(room, link[0]) == 0)
			{
				ft_strcat(env->room_link[i], ",");
				ft_strcat(env->room_link[i], link[1]);
			}
			else if (ft_strcmp(room, link[1]) == 0)
			{
				ft_strcat(env->room_link[i], ",");
				ft_strcat(env->room_link[i], link[0]);
			}
			++j;
			ft_2d_tab_free(link, 3);
		}
		/*ft_fprintf(1, CYAN"%s\n"END, env->room_link[i]);*/
		++i;
	}
}

int8_t	check_forbidden_charactere(char *line)
{
	if (line[0] == '#' || line[0] == 'L') // forbidden charactere
		return (EXIT_ERROR_ROOM);
	return (EXIT_SUCCESS);
}

int8_t	check_split_line(char *line)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = ft_strsplit(line, ' ');
	i = ft_count_2d_tab(split);
	if (i != 3)
	{
		ft_2d_tab_free(split, i);
		return (EXIT_ERROR_ROOM);
	}
	ft_2d_tab_free(split, i);
	return (EXIT_SUCCESS);
}

int8_t	check_nb_room(t_env *env)
{
	if (env->nb_rooms_line == 0)
		return (EXIT_ERROR_ROOM);
	return (EXIT_SUCCESS);
}

int8_t	check_room_valid(char *line)
{
	if (check_forbidden_charactere(line) == EXIT_ERROR_ROOM)
		return (EXIT_ERROR_ROOM);
	if (check_split_line(line) == EXIT_ERROR_ROOM)
		return (EXIT_ERROR_ROOM);
	return (EXIT_SUCCESS);
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
