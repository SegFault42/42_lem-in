/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2017/01/19 13:19:31 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	create_file(t_env *env, char *argv)
{
	if (ft_strcmp(argv, "-w") == 0)
	{
		system("rm ./lemin.log 2> /dev/null");
		env->write_file = true;
		env->fd_file_bonus = open("./lemin.log", O_RDWR | O_CREAT,
				S_IRUSR | S_IWUSR);
	}
}

char	*fill_print_map(char *s1, char *s2)
{
	s1 = ft_strjoin(s1, s2);
	s1 = ft_strjoin(s1, "\n");
	return (s1);
}

char	*fill_print_map_nbn(char *s1, char *s2)
{
	s1 = ft_strjoin(s1, s2);
	return (s1);
}

void	print_usage(void)
{
	ft_fprintf(1, RED"Usage : ./lem-in < map (Read from stdin)\n"END);
	ft_fprintf(1, RED"        ./lem-in -f map (Read from file)\n"END);
	ft_fprintf(1, RED"        ./lem-in -s map (Print step number)\n"END);
	ft_fprintf(1, RED"        ./lem-in -sound (sound)\n"END);
	ft_fprintf(1, RED"        ./lem-in -time \"number\" (set time in second)\n"
	END);
	ft_fprintf(1, RED"        ./lem-in -help (print usage)\n"END);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	t_env	env;
	int8_t	ret;
	int8_t	option;

	ret = 0;
	option = 0;
	protect_argc(argc, argv);
	ft_memset(&env, 0, sizeof(env));
	option = check_option(&env, argv, argc);
	save_map(&env, option, argv[2]);
	ret = parsing_map_stdin(&env);
	if (ret >= EXIT_ERROR_LINK && ret <= EXIT_ERROR_CMD)
		print_error(env.map, env.nb_lines_map, ret);
	get_start_and_end(&env);
	algo(&env);
	if (env.write_file == true)
		ft_fprintf(env.fd_file_bonus, "%s\n", env.print_map);
	ft_fprintf(1, "%s\n", env.print_map);
	print_ants(&env);
	if (argv[1] != NULL && (ft_strcmp(argv[1], "-fs") == 0 ||
	ft_strcmp(argv[1], "-s") == 0))
		ft_fprintf(1,
		"\nLes fourmis on parcourue %d salles pour atteindre la salle finale\n",
		env.number_step);
	ft_2d_tab_free(env.map, env.nb_lines_map);
}
