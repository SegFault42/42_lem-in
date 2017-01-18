/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:08:51 by rabougue          #+#    #+#             */
/*   Updated: 2017/01/18 22:25:36 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_error(char **map, int y_tab, int8_t err_num)
{
	if (err_num == EXIT_ERROR_ANTS)
		ft_fprintf(2, RED"Ants : bad information\n"END);
	if (err_num == EXIT_ERROR_ROOM)
		ft_fprintf(2, RED"Room : bad information\n"END);
	if (err_num == EXIT_ERROR_CMD)
		ft_fprintf(2, RED"CMD : bad information\n"END);
	if (err_num == EXIT_ERROR_LINK)
		ft_fprintf(2, RED"LINK : bad information\n"END);
	ft_2d_tab_free(map, y_tab);
	system("afplay ./fail.mp3");
	exit(EXIT_FAILURE);
}

void	check_error_gnl(char **line)
{
	if (*line == NULL)
	{
		ft_fprintf(2, RED"GNL_EXIT_ERROR !\n"END);
		system("afplay ./fail.mp3");
		exit(EXIT_FAILURE);
	}
}

void	print_simple_error(void)
{
	ft_fprintf(2, RED"Error\n"END);
	system("afplay ./fail.mp3");
	exit(EXIT_FAILURE);
}
