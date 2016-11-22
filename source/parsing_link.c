/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:09:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/22 18:10:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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
