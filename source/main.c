/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/19 17:31:56 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_error_ants()
{
	ft_fprintf(2, RED"Ants : bad information\n"END);
	exit(EXIT_FAILURE);
}

void	check_error_gnl(char **line)
{
	if (*line == NULL)
	{
		ft_fprintf(2, RED"GNL_ERROR !\n"END);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_env	env;

	memset(&env, 0, sizeof(env));
	if (argc == 1)
		save_map(&env);
	/*else if (argc == 2)*/
		/*parsing_map_file(&env);*/
	ft_2d_tab_free(env.map, env.ants_line + env.room_line + env.link_line);
	(void)argc;
	(void)argv;
}
