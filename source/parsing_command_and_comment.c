/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command_and_comment.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:24:27 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/22 10:42:03 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_if_is_comment(char *line)
{
	if (line[0] == '#' && ft_strcmp(line, "##start") != 0 && ft_strcmp(line, "##end") != 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int8_t	check_if_is_command(char *line)
{
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int8_t	check_multi_minus(t_env *env)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < env->nb_lines_map)
	{
		if (env->index_map[i] == LINK)
		{
			ret = ft_count_char(env->map[i], '-');
			if (ret != 1)
				return (EXIT_ERROR_LINK);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int8_t	parsing_link(t_env *env)
{
	if (check_multi_minus(env) == EXIT_ERROR_LINK)
		return (EXIT_ERROR_LINK);
	return (EXIT_SUCCESS);
}

