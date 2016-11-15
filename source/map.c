/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:28:57 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/15 23:35:28 by rabougue         ###   ########.fr       */
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
	int		ret;

	line = NULL;
	i = 1;
		/*printf("%d\n", ret);*/
	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		check_error_gnl(&line);
		alloc_tab(env, line, i);
		i++;
		free(line);
	}
	env->nb_lines_map = i;
	// print tab
	for (int j = 0; j < i -1; j++)
		printf("%s\n", env->map[j]);
}
