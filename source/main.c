/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/23 19:45:48 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_ants(t_env *env)
{
	int	i;
	int	save_i;
	int	nb_ants;
	int	save_simultanous_ants;
	int	simultanous_ants;

	i = 0;
	nb_ants = 1;
	simultanous_ants = 0;
	save_simultanous_ants = 0;
	while (env->path[i] == NULL)
		++i;
	save_i = i;
	while (i < env->nb_rooms_line)
	{
		++save_simultanous_ants;
		++i;
	}
	i = save_i;
	while (nb_ants <= env->nb_ants)
	{
		while (i < env->nb_rooms_line)
		{
			ft_fprintf(1, "L%d-%s\n", nb_ants, env->path[i]);
			++i;
		}
		i = save_i;
		++nb_ants;
	}
}

int	main(int argc, char **argv)
{
	t_env	env;
	int8_t	ret;

	ret = 0;
	memset(&env, 0, sizeof(env));
	if (argc > 1)
	{
		ft_fprintf(1, "Error\n");
		exit(EXIT_FAILURE);
	}
	save_map(&env);
	ret = parsing_map_stdin(&env);
	if (ret >= EXIT_ERROR_LINK && ret <= EXIT_ERROR_CMD)
		print_error(env.map, env.nb_lines_map, ret);
	get_start_and_end(&env);
	algo(&env);
	print_ants(&env);
	ft_2d_tab_free(env.map, env.nb_lines_map);
	(void)argc;
	(void)argv;
}
