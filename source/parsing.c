/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/21 20:44:17 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	fill_room_link_cmt_cmd(t_env *env)
{
	int	i;
	int	browse_tab;
	int	loop;
	int	iter[4];

	i = 0;
	browse_tab = 0;
	loop = 0;
	ft_memset(iter, 0, sizeof(int) * 4);
	while (i < env->nb_lines_map)
	{
		if (env->index_map[i] == ROOM)
		{
			env->room[iter[0]] = ft_strdup(env->map[i]);
			ft_fprintf(1, YELLOW"%s\n"END, env->room[iter[0]]);
			++iter[0];
		}
		else if (env->index_map[i] == LINK)
		{
			env->link[iter[1]] = ft_strdup(env->map[i]);
			ft_fprintf(1, ORANGE"%s\n"END, env->link[iter[1]]);
			++iter[1];
		}
		else if (env->index_map[i] == CMD)
		{
			env->cmd[iter[2]] = ft_strdup(env->map[i]);
			ft_fprintf(1, RED"%s\n"END, env->cmd[iter[2]]);
			++iter[2];
		}
		else if (env->index_map[i] == CMT)
		{
			env->cmt[iter[3]] = ft_strdup(env->map[i]);
			ft_fprintf(1, PURPLE"%s\n"END, env->cmt[iter[3]]);
			++iter[3];
		}
		++i;
	}
}

void	alloc_room_link_cmt_cmd(t_env *env)
{
	/*int	i;*/

	/*i = 0;*/
	/*while (i < env->nb_lines_map)*/
	/*{*/
		/*if (env->index_map[i] == ROOM)*/
			/*++env->nb_rooms_line;*/
		/*else if (env->index_map[i] == LINK)*/
			/*++env->nb_link_line;*/
		/*else if (env->index_map[i] == CMD)*/
			/*++env->nb_cmd_line;*/
		/*else if (env->index_map[i] == CMT)*/
			/*++env->nb_cmt_line;*/
		/*++i;*/
	/*}*/
	env->room = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	env->link = (char **)ft_memalloc(sizeof(char *) * env->nb_link_line);
	env->cmd = (char **)ft_memalloc(sizeof(char *) * env->nb_cmd_line);
	env->cmt = (char **)ft_memalloc(sizeof(char *) * env->nb_cmt_line);
	fill_room_link_cmt_cmd(env);
}

void	stock_all(t_env *env)
{
	alloc_room_link_cmt_cmd(env); // don't forget to free all !
}

