/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/11 23:36:57 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_list(t_room *room)
{
	while (room)
	{
		ft_fprintf(1, "%s, %d, %d\n", room->room_name, room->x, room->y);
		room = room->next;
	}
}

t_room	*get_rooms(char **line, t_ctrl *ctrl)
{
	char		**tab;
	t_room		*room;

	tab = NULL;
	tab = ft_strsplit(*line, ' ');

	room = create_maillon();
	room->room_name = ft_strdup(tab[0]);
	room->x = ft_atoi(tab[1]);
	room->y = ft_atoi(tab[2]);
	room->next = NULL;
	add_head(ctrl, room);
	ft_2d_tab_free(tab, 3);
	return (room);
}


void	parsing_rooms(t_env *env, t_ctrl *ctrl)
{
	char		*line;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		check_error_gnl(&line);
		if (strstr(line, " ") != NULL)
		{
			get_rooms(&line, ctrl);
		}
		/*if (ft_strstr(line, "##start") != NULL)*/
		/*{*/
			
		/*}*/
	}
	(void)env;
}

void	parsing_ants(t_env *env)
{
	uint8_t	i;
	uint8_t	len;
	char	*line;

	i = 0;
	line = NULL;
	get_next_line(STDIN_FILENO, &line);
	check_error_gnl(&line);
	len = ft_strlen(line);
	if (ft_strlen(line) <= 3 && ft_atoi(line) < UINT8_MAX && ft_atoi(line) > 0)
	{
		while (i < len)
		{
			if (line[i] < '0' || line[i] > '9')
				print_error_ants();
			++i;
		}
		env->nb_ants = ft_atoi(line);
	}
	else
		print_error_ants();
}

void	parsing_map_stdin(t_env *env, t_ctrl *ctrl)
{
	parsing_ants(env); // get ants number
	parsing_rooms(env, ctrl); // get rooms
	print_list(ctrl->first);
}
