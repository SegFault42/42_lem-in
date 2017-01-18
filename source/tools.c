/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2017/01/18 22:04:03 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	protect_argc(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "-help") == 0)
			print_usage();
	}
	if (argc > 3)
		print_usage();
}

int8_t	check_option(t_env *env, char **argv, int argc)
{
	int8_t	option;

	if (argv[1] != NULL && (ft_strcmp(argv[1], "-fs") == 0 ||
	ft_strcmp(argv[1], "-f") == 0))
		option = 1;
	else if (argv[1] != NULL && ft_strcmp(argv[1], "-sound") == 0)
		env->sound = true;
	else if (argv[1] != NULL && argv[2] && ft_strcmp(argv[1], "-time") == 0)
	{
		if (ft_atoi(argv[2]) > 0)
			env->time = ft_atoi(argv[2]);
	}
	if (argc > 1)
		create_file(env, argv[1]);
	return (option);
}
