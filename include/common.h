#ifndef COMMON_H
# define COMMON_H

# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
#include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct	s_env
{
	uint8_t			nb_ants;
	uint8_t			nb_rooms;

}				t_env;

void	parsing_map_stdin(t_env *env);
void	parsing_map_file(t_env *env);

#endif
