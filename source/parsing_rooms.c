/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:05:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/21 19:24:41 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_forbidden_charactere(char *line)
{
	int	i;

	i = 0;

	ft_fprintf(1, CYAN"%s\n"END, line);
	/*while (line[i] != '\0')*/
	/*{*/
		/*ft_fprintf(1, CYAN"%c"END, line[i]);*/
		/*if (line[i] == '-')*/
			/*return (EXIT_ERROR_ROOM);*/
		/*++i;*/
	/*}*/
	if (line[0] == '#' || line[0] == 'L') // forbidden charactere
		return (EXIT_ERROR_ROOM);
	return (EXIT_SUCCESS);
}

int8_t	check_split_line(char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	i = ft_count_2d_tab(split);
	if (i != 3)
	{
		ft_2d_tab_free(split, i);
		return (EXIT_ERROR_ROOM);
	}
	ft_2d_tab_free(split, i);
	return (EXIT_SUCCESS);
}

int8_t	check_room_valid(char *line)
{
	if (check_forbidden_charactere(line) == EXIT_ERROR_ROOM)
		return (EXIT_ERROR_ROOM);
	else if (check_split_line(line) == EXIT_ERROR_ROOM)
		return (EXIT_ERROR_ROOM);
	return (EXIT_SUCCESS);
}

int8_t	count_all(t_env *env)
{
	int		i;
	int8_t	ret_check_room;

	i = 1;
	env->index_map = (int *)ft_memalloc(sizeof(int) * env->nb_lines_map); // dont't forget to free !*/
	env->index_map[0] = ANTS;
	while (i < env->nb_lines_map)
	{
		if (ft_strstr(env->map[i], "-") != NULL && env->map[i][0] != '#') // exit function when a line link found
		{
			if (env->map[i][0] != '#') // exit function when a line link found
			{
				if (ft_strchr(env->map[i], ' ') != NULL)
					return (EXIT_ERROR_ROOM);
				env->index_map[i] = LINK;
				++i;
				continue ;
			}
		}
		if (check_if_is_command(env->map[i]) == EXIT_SUCCESS)
		{
			env->index_map[i] = CMD;
			++i;
			continue ;
		}
		if (check_if_is_comment(env->map[i]) == EXIT_SUCCESS)
		{
			env->index_map[i] = CMT;
			++i;
			continue ;
		}
			ret_check_room = check_room_valid(env->map[i]);
			if (ret_check_room == EXIT_ERROR_ROOM)
				return (EXIT_ERROR_ROOM);
			else if (ret_check_room == EXIT_SUCCESS)
				env->index_map[i] = ROOM;
		++i;
	}
	return (EXIT_SUCCESS);
}
