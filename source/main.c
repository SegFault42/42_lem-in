/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/10 21:13:44 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common.h"

int	main(int argc, char **argv)
{
	bool	output;
	t_env	env;

	memset(&env, 0, sizeof(env));
	if (argc == 1)
		parsing_map_stdin(&env);
	/*else if (argc == 2)*/
		/*parsing_map_file(&env);*/
	(void)argc;
	(void)argv;
}
