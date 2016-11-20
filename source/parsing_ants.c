/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:49:09 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/20 10:39:50 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool	check_ants_valid(t_env *env)
{
	int		i;
	long	overflow;

	i = 0;
	overflow = ft_atol(env->map[0]);
	if (check_int_overflow(overflow) == EXIT_FAILURE || overflow == 0)
		return (EXIT_FAILURE);
	while (env->map[0][i] != '\0')
	{
		if (ft_isdigit(env->map[0][i]) == false)
			return(EXIT_FAILURE);
		++i;
	}
	env->nb_ants = overflow;
	printf(YELLOW"nb_ants = %d\n"END, env->nb_ants);
	return(EXIT_SUCCESS);
}
