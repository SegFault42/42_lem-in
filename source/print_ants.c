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

int	count_max_ants(t_env *env)
{
	int	i;

	i = 0;
	while (env->path[i] == NULL)
		++i;
	return (env->nb_rooms_line - i);
}

void	print_ants(t_env *env)
{
	int	nb_ants;
	int	path;
	int	save_path;
	int	ants;
	int	save_ants;
	/*int	max_ants;*/

	ants = 1;
	save_ants = 1;
	nb_ants = count_max_ants(env);
	save_path = env->nb_rooms_line - nb_ants;
	path = save_path;
	while (ants < env->nb_ants)
	{
		while (ants != 0)
		{
			ft_fprintf(1, "L%d-%s ", ants, env->path[path]);
			--path;
			--ants;
		}
		RC;
		if (save_ants < nb_ants)
			ants = ++save_ants;
		else if (save_ants == nb_ants)
			ants = save_ants;
		sleep(2);
		path = ++save_path;
	}
}

