/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/13 22:42:44 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	parsing_rooms(t_env *env)
{

}

void	parsing_ants(t_env *env)
{
	uint8_t	i;
	uint8_t	len;

	i = 0;
	len = ft_strlen(env->map[0]);
	if (ft_strlen(env->map[0]) <= 10 &&
		ft_atoi(env->map[0]) < INT_MAX && ft_atoi(env->map[0]) > 0)
	{
		while (i < len)
		{
			if (env->map[0][i] < '0' || env->map[0][i] > '9')
				print_error_ants();
			++i;
		}
		env->nb_ants = ft_atoi(env->map[0]);
		env->ants_line = 1;
	}
	else
		print_error_ants();
}

void	count_part_map(t_env *env)
{
	int	i;

	i = 1;
	while (i < env->nb_lines_map -1)
	{
		if (ft_strstr(env->map[i], "##start") != NULL ||
			ft_strstr(env->map[i], "##end") != NULL ||
			ft_strstr(env->map[i], " ") != NULL)
			++env->room_line;
		else if (ft_strstr(env->map[i], "-") != NULL)
			++env->link_line;
		++i;
	}
}

void	parsing_map_stdin(t_env *env)
{
	count_part_map(env); // count number lines of map part (ants numbers, room number, link number)
	parsing_ants(env); //get ants number
	parsing_rooms(env); // get rooms

	printf("room_line = %d\n", env->room_line);
	printf("link_line = %d\n", env->link_line);
}
