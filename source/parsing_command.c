/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:09:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/22 18:19:49 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_nb_cmd(t_env *env)
{
	if (env->nb_cmd_line != 2)
		return (EXIT_ERROR_CMD);
	return (EXIT_SUCCESS);
}

int8_t	check_if_is_command(char *line)
{
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
