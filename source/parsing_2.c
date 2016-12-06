/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/23 17:54:44 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	alloc_room_link_cmt_cmd(t_env *env)
{
	env->room = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	env->link = (char **)ft_memalloc(sizeof(char *) * env->nb_link_line);
	env->cmd = (char **)ft_memalloc(sizeof(char *) * env->nb_cmd_line);
	env->cmt = (char **)ft_memalloc(sizeof(char *) * env->nb_cmt_line);
	if (fill_room_link_cmt_cmd(env) == EXIT_ERROR_CMD)
		return (EXIT_ERROR_CMD);
	return (EXIT_SUCCESS);
}

int8_t	stock_all(t_env *env)
{
	if (alloc_room_link_cmt_cmd(env) == EXIT_ERROR_CMD)
		return (EXIT_ERROR_CMD);
	return (EXIT_SUCCESS);
}
