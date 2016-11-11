/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:46:24 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/11 23:29:06 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_room	*create_maillon()
{
	t_room	*new;

	new = NULL;
	if ((new = (t_room *)malloc(sizeof(t_room))) == NULL)
	{
		ft_fprintf(2, RED"Memory Allocation failure\n"END);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void	add_head(t_ctrl *ctrl, t_room *new)
{
	new->next = ctrl->first;
	ctrl->first = new;
}

void	add_tail(t_ctrl *ctrl, t_room *new)
{
	t_room	*tmp;

	tmp = ctrl->first;
	if (ctrl->first == NULL)
		ctrl->first = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
