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

int8_t	check_forbidden_charactere(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
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
