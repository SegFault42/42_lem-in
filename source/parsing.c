/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/19 22:39:42 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool	parsing_map_stdin(t_env *env)
{
	if (check_ants_valid(env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	get_rooms(env);
	return (EXIT_SUCCESS);
}
