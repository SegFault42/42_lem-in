/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/23 19:45:48 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_ants_2(t_env *env, int *i, int *nb_ants, int save_i)
{
	while (*nb_ants <= env->nb_ants)
	{
		while (*i < env->nb_rooms_line)
		{
			ft_fprintf(1, "L%d-%s\n", *nb_ants, env->path[*i]);
			++*i;
		}
		*i = save_i;
		++*nb_ants;
	}
}

void	print_ants(t_env *env)
{
	int	i;
	int	save_i;
	int	nb_ants;
	int	simultanous_ants;

	i = 0;
	nb_ants = 1;
	simultanous_ants = 0;
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
