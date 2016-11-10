/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/10 22:57:50 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common.h"

void	parsing_ants(t_env *env, char *line)
{
	uint8_t	i;
	uint8_t	len;

	i = 0;
	len = ft_strlen(line);
	if (ft_strlen(line) <= 3 && ft_atoi(line) < UINT8_MAX && ft_atoi(line) > 0)
	{
		while (i < len)
		{
			if (line[i] < '0' || line[i] > '9')
			{
				ft_fprintf(2, RED"Ants : bad information\n"END);
				exit(-1);
			}
			++i;
		}
		env->nb_ants = ft_atoi(line);
	}
	else
	{
		ft_fprintf(2, RED"Ants : bad information\n"END);
		exit(-1);
	}
}

void	parsing_map_stdin(t_env *env)
{
	char	*line;
	uint8_t	ants;

	line = NULL;
	ants = 0;
	while(get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ants == 0)
		{
			parsing_ants(env, line);
			ants = 1;
		}
		free(line);
	}
}
