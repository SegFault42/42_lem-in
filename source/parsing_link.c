/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:00:56 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/19 00:15:53 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	parsing_link(t_env *env)
{
	int	i;

	i = env->room_line + 1;
	while (i < env->nb_lines_map -1)
	{
		ft_fprintf(1, PURPLE"%s\n"END, env->map[i]);
		++i;
	}
	(void)env;
}
