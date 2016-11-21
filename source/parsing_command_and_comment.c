/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command_and_comment.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:24:27 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/21 17:46:56 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_if_is_comment(char *line)
{
	if (line[0] == '#' && ft_strcmp(line, "##start") != 0 && ft_strcmp(line, "##end") != 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int8_t	check_if_is_command(char *line)
{
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
