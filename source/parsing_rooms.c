/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:05:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/20 00:19:36 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_room_valid(char *line)
{
	char	**split;
	int		i = 0;

	split = NULL;
	if (line[0] == '#' || line[0] == 'L' || line[0] == '-')
		return (EXIT_FAILURE);
	split = ft_strsplit(line, ' ');
	while (split[i])
		++i;
	if (i != 3)
		return (ERROR);
	//stocker la salle 
	ft_2d_tab_free(split, i);
	return (EXIT_SUCCESS);
}

bool	get_rooms(t_env *env)
{
	int	i;

	i = 0;
	while (i++ < env->nb_lines_map)
	{
		if (ft_strstr(env->map[i], "-") != NULL && env->map[i][0] != '#')
			break ;
		if (check_room_valid(env->map[i]) == ERROR)
			return (EXIT_FAILURE);
		ft_fprintf(1, PURPLE"%s\n"END, env->map[i]);
	}
	return (EXIT_SUCCESS);
}
