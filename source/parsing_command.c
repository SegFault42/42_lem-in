/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:09:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/23 17:57:05 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_nb_cmd(t_env *env)
{
	if (env->nb_cmd_line != 2)
		return (EXIT_ERROR_CMD);
	return (EXIT_SUCCESS);
}

int8_t	check_if_is_command(char *line)
{
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int8_t	get_start_and_end(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_lines_map)
	{
		if (ft_strcmp(env->map[i], "##start") == 0)
			env->start = ft_strdup(env->map[++i]);
		else if (ft_strcmp(env->map[i], "##end") == 0)
			env->end = ft_strdup(env->map[++i]);
		++i;
		if (i == env->nb_lines_map--)
			break ;
		if (env->start != NULL && env->end != NULL)
			break ;
	}
	if (env->start == NULL || env->end == NULL)
		return (EXIT_ERROR_CMD);
	if (check_room_valid(env->start) == EXIT_ERROR_ROOM)
		return (EXIT_ERROR_ROOM);
	if (check_room_valid(env->end) == EXIT_ERROR_ROOM)
		return (EXIT_ERROR_ROOM);
	return (EXIT_SUCCESS);
}
