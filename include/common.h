/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:31:13 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/19 22:39:29 by rabougue         ###   ########.fr       */
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
	char				**map; // map stored int this char **

	int					nb_ants; // nb ants
	int					nb_rooms; // nb rooms

	int					ants_line; // nb ants_line
	int					room_line; // nb room_line (all line between ants line and before link_line)
	int					link_line; //nb link_line (all line at the first link_line)
	int					room_line_only; // nb room_line only
	int					nb_lines_map; // nb line of all map

	char				**room_list; // all rooms stored in room_list tab
	char				*start;
	char				*end;
}						t_env;
/*
** parsing.c
*/
bool					parsing_map_stdin(t_env *env);
/*
** map.c
*/
void					alloc_tab(t_env *env, char *line, int size);
void					save_map(t_env *env);
/*
** parsing_ants.c
*/
bool					check_ants_valid(t_env *env);
/*
** parsing_room.c
*/
bool					get_rooms(t_env *env);
/*
** main.c
*/
void					check_error_gnl(char **line);
void					print_error_ants(char **map, int y_tab);


#endif
