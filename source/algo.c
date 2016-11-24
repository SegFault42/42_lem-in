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

void	count_nb_link_by_room(t_env *env)
{
	int	tab[env->nb_rooms_line + 1];
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_memset(tab, 0, env->nb_rooms_line);
	/*while (env->link)*/
	/*{*/
		ft_fprintf(1, "%s\n", env->room[0]);
		/*while (j < env->nb_rooms_line)*/
		/*{*/
			/*if (ft_strcmp(env->link[i], env->room[j]) != 0)*/
			/*{*/
				
			/*}*/
			/*++j;*/
		/*}*/
		/*++i;*/
	/*}*/
}

int8_t	algo(t_env *env)
{
	count_nb_link_by_room(env);
	/*stock_info_room(env);*/
	return (EXIT_SUCCESS);
}
