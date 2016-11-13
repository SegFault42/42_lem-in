/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:31:13 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/13 22:28:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct			s_room
{
	char				*room_name;
	uint16_t			x;
	uint16_t			y;
	int					nb_room;
	struct s_room		*next;
}						t_room;

typedef struct			s_ctrl
{
	struct s_room		*first;
}						t_ctrl;

typedef struct			s_env
{
	char				**map;
	int					nb_ants;
	int					nb_rooms;
	int					ants_line;
	int					room_line;
	int					link_line;
	int					nb_lines_map;

}						t_env;
/*
** linked_list.c
*/
void					add_tail(t_ctrl *ctrl, t_room *newu);
t_room					*create_maillon();
void					add_head(t_ctrl *ctrl, t_room *newu);
/*
** parsing.c
*/
void					parsing_map_stdin(t_env *env);
//void					parsing_ants(t_env *env, char *line);
void					parsing_rooms(t_env *env);

void					check_error_gnl(char **line);
void					print_error_ants();

t_room					*get_rooms(char **line, int8_t start);

void					save_map(t_env *env);

#endif
