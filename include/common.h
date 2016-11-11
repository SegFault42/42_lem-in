#ifndef COMMON_H
# define COMMON_H

# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct	s_room
{
	char				*room_name;
	uint16_t			x;
	uint16_t			y;
	struct s_room		*next;
}						t_room;

typedef struct			s_ctrl
{
	struct s_room		*first;
}						t_ctrl;

typedef struct			s_env
{
	uint8_t				nb_ants;
	uint8_t				nb_rooms;

}						t_env;
/*
** linked_list.c
*/
void	add_tail(t_ctrl *ctrl, t_room *newu);
t_room					*create_maillon();
void					add_head(t_ctrl *ctrl, t_room *newu);
/*
** parsing.c
*/
void					parsing_map_stdin(t_env *env,  t_ctrl *ctrl);
//void					parsing_ants(t_env *env, char *line);
void					parsing_rooms(t_env *env, t_ctrl *ctrl);

void					check_error_gnl(char **line);
void					print_error_ants();

t_room					*get_rooms(char **line, t_ctrl *ctrl);

#endif
