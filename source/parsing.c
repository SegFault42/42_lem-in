/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/10 21:13:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common.h"

void	parsing_ants(t_env *env, char **line)
{
	uint8_t	i;

	i = 0;
	printf("%zu\n", ft_strlen(*line));
	if (ft_strlen(*line) <= 3 && ft_atoi(*line) < UINT8_MAX && ft_atoi(*line) > 0)
	{
		while (i < ft_strlen(*line))
		{
			if (ft_isdigit(ft_atoi(line[i])) == 1)
			{
				printf("Ants : bad information\n");
				exit(-1);
			}
			++i;
		}
		env->nb_ants = ft_atoi(*line);
		printf(RED"%d\n"END, env->nb_ants);
	}
	else
	{
		printf("Ants : bad information\n");
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
			parsing_ants(env, &line);
			ants = 1;
		}
		free(line);
	}
}
