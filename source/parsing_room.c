/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:41:41 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/18 22:17:36 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	check_if_start_end_exist(t_env *env, uint8_t start_end)
{
	if (env->start != NULL && start_end == 1)
	{
		ft_fprintf(2, RED"Error : Multiple start !\n"END);
		exit(EXIT_FAILURE);
	}
	if (env->end != NULL && start_end == 2)
	{
		ft_fprintf(2, RED"Error : Multiple end !\n"END);
		exit(EXIT_FAILURE);
	}
}

void	get_start_room(t_env *env, char *line, uint8_t start_end)
{
	int		i;
	uint8_t	len_line;

	i = 0;
	len_line = 0;
	check_if_start_end_exist(env, start_end);
	while (line[i] != ' ')
	{
		++len_line;
		++i;
	}
	if (start_end == 1)
		env->start = ft_strsub(line, 0, len_line);
	else if (start_end == 2)
		env->end = ft_strsub(line, 0, len_line);
}

void	parsing_rooms(t_env *env)
{
	int		i;
	int		j;
	char	**tmp;
	uint8_t	start_end;

	j = 0;
	start_end = 0;
	i = env->ants_line;
	ft_fprintf(STDERR_FILENO, YELLOW"%d\n"END, env->room_line);
	env->room_list = (char **)malloc(sizeof(char *) * env->room_line);
	while (i <= env->room_line)
	{
		if (env->map[i][0] == '#' && ft_strcmp(env->map[i], "##start") != 0 && ft_strcmp(env->map[i], "##end") != 0 && i++)
			continue ; // ignore comment
		if (ft_strcmp(env->map[i], "##start") == 0)
			start_end = 1;
		else if (ft_strcmp(env->map[i], "##end") == 0)
			start_end = 2;
		if (ft_strstr(env->map[i], " ") != NULL)
		{
			if (start_end == 1 || start_end == 2)
			{
				get_start_room(env, env->map[i], start_end);
				start_end = 0;
			}
			check_if_room_is_valid(env->map[i]); // check if current room line is valid (quit if the room line is invalid)
			tmp = ft_strsplit(env->map[i], ' ');
			env->room_list[i - 1] = (char *)ft_memalloc(ft_strlen(tmp[0]) + ft_strlen(tmp[1]) + ft_strlen(tmp[2]) + 2); // alloc tab for 3 string (room name, x, y and 2 separators)
			while (j < 3)
			{
				ft_strcat(env->room_list[i - 1], tmp[j]);
				ft_strcat(env->room_list[i - 1], "#");    /*-> cp all room info in env->room_list*/
				++j;
			}
			j = 0;
			ft_2d_tab_free(tmp, 3); // free tmp tab 
		}
		++i;
	}
	ft_fprintf(2, CYAN"start = %s, end = %s\n"END, env->start, env->end);
}
