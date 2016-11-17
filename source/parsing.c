/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/17 13:18:50 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	get_start_room(t_env *env, char *line, uint8_t start_end)
{
	int		i;
	uint8_t	len_line;

	i = 0;
	len_line = 0;
	ft_fprintf(2, YELLOW"%s\n"END, line);
	while (line[i] != ' ')
	{
		++len_line;
		++i;
	}
	if (start_end == 1 && env->start == NULL)
		env->start = ft_strsub(line, 0, len_line);
	else
	{
		ft_fprintf(2, RED"Multiple start room\n"END);
		exit(EXIT_FAILURE);
	}
	if (start_end == 2 && env->end == NULL)
		env->end = ft_strsub(line, 0, len_line);
	else
	{
		ft_fprintf(2, RED"Multiple end room\n"END);
		exit(EXIT_FAILURE);
	}
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
	env->room_list = (char **)malloc(sizeof(char *) * env->room_line);
	while (i <= env->room_line)
	{
		if (ft_strstr(env->map[i], "##start") != NULL)
			start_end = 1;
		else if (ft_strstr(env->map[i], "##end") != NULL)
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
			printf(ORANGE"%s\n"END, env->room_list[i-1]);
		}
		++i;
	}
	ft_fprintf(2, CYAN"start = %s, end = %s\n"END, env->start, env->end);
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
		if (ft_strstr(env->map[i], "#") != NULL ||
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
	if (env->start == NULL || env->end == NULL)
	{
		ft_fprintf(2, RED"Start or end missing !\n"END);
		exit(EXIT_FAILURE);
	}
	printf("room_line = %d\n", env->room_line);
	printf("link_line = %d\n", env->link_line);
	/*sleep(10);*/
}
