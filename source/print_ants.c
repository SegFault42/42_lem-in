/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2017/01/18 22:19:56 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_ants_2(t_env *env, int *i, int *nb_ants, int save_i)
{
	while (*nb_ants <= env->nb_ants)
	{
		while (*i < env->nb_rooms_line)
		{
			sleep(env->time);
			if (env->write_file == true)
				ft_fprintf(env->fd_file_bonus, "L%d-%s\n",
				*nb_ants, env->path[*i]);
			ft_fprintf(1, "L%d-%s\n", *nb_ants, env->path[*i]);
			++*i;
		}
		*i = save_i;
		++*nb_ants;
	}
	if (env->sound == true)
		system("afplay ./found.mp3");
}

void	print_ants(t_env *env)
{
	int	i;
	int	save_i;
	int	nb_ants;

	i = 0;
	nb_ants = 1;
	while (env->path[i] == NULL)
		++i;
	save_i = i;
	while (i < env->nb_rooms_line)
	{
		++env->number_step;
		++i;
	}
	i = save_i;
	print_ants_2(env, &i, &nb_ants, save_i);
}
