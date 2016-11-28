/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:28:57 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/22 21:08:12 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	alloc_tab(t_env *env, char *line, int size)
{
	int		i;
	char	**tmp = NULL;

	i = 0;
	if (env->map == NULL)
		env->map = (char **)malloc(sizeof(char *) * size);
	else
	{
		tmp = (char **)malloc(sizeof(char *) * size -1);
		while (i < size -1)
		{
			tmp[i] = ft_strdup(env->map[i]);
			++i;
		}
		ft_2d_tab_free(env->map, size -1);
		env->map = (char **)malloc(sizeof(char *) * size);
	}
	i = 0;
	while (i < size -1)
	{
		env->map[i] = ft_strdup(tmp[i]);
		++i;
	}
	if (i < size)
		env->map[i] = ft_strdup(line);
	ft_2d_tab_free(tmp, size -1);
}

void	save_map(t_env *env)
{
	char	*line;
	int		i;
	int		ret = 0;

	line = NULL;
	i = 1;
	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		check_error_gnl(&line);
		alloc_tab(env, line, i);
		i++;
		free(line);
	}
	env->nb_lines_map = i - 1; // Why -1 ? because i is instancied at 1
	if (env->nb_lines_map == 1)
	{
		ft_fprintf(2, RED"ERROR\n"END);
		exit(EXIT_FAILURE);
	}
}
