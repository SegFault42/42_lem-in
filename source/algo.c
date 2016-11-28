/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:00:29 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/23 20:51:00 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*void	stock_info_room(t_env *env)*/
/*{*/
	/*int	i;*/
	/*int	j;*/

	/*i = 0;*/
	/*j = 0;*/
	/*env->room_link = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);*/
	/*while (i < env->nb_rooms_line)*/
	/*{*/
		/*while (j < env->nb_rooms_line)*/
		/*{*/
			/*if ()*/
		/*}*/
	/*}*/
/*}*/

/*void	count_nb_link_by_room(t_env *env)*/
/*{*/
	/*int	tab[env->nb_rooms_line + 1];*/
	/*int	i;*/
	/*int	j;*/

	/*i = 0;*/
	/*j = 0;*/
	/*ft_memset(tab, 0, env->nb_rooms_line);*/
	
/*}*/

void	looking_for_path(t_env *env)
{
	char	**path;
	char	*cur_room;
	int		i;
	char	**split;
	int		iter;

	i = 0;
	iter = env->nb_rooms_line;
	cur_room = ft_strdup(env->end);
	path = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	while (ft_strcmp(env->start, path[0]) != 0)
	{
	}
}

int8_t	algo(t_env *env)
{
	/*count_nb_link_by_room(env);*/
	/*stock_info_room(env);*/
	looking_for_path(env);
	return (EXIT_SUCCESS);
}
