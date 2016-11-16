/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:31:13 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/16 14:53:26 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct			s_env
{
	char				**map; // map stored int this var

	int					nb_ants; // nb ants
	int					nb_rooms; // nb rooms

	int					ants_line; // nb ants_line
	int					room_line; // nb room_line
	int					link_line; //nb link_line
	int					nb_lines_map; // nb line of all map

	char				**room_list; // all rooms stored in room_list tab
	char				*start;
	char				*end;
}						t_env;
/*
** parsing.c
*/
void					parsing_map_stdin(t_env *env);
//void					parsing_ants(t_env *env, char *line);
void					parsing_rooms(t_env *env);

void					check_error_gnl(char **line);
void					print_error_ants();


void					save_map(t_env *env);

void					check_if_room_is_valid(char *str);

#endif
