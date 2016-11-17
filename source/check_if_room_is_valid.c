/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_room_is_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:50:36 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/17 18:24:32 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	check_nb_space(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			++space;
		++i;
	}
	if (space != 2)
	{
		ft_fprintf(2, RED"Room line error : X or Y coord not valid\n"END);
		exit(EXIT_FAILURE);
	}
}

static void	check_forbidden_character(char *str)
{
	if (str[0] == '#' && str[1] != '#')
	{
		ft_fprintf(2, RED"Room line error : -->\e[32m%s\e[31m<-- Description of the room contain invalid caractere (\e[32m#\e[31m)\n"END, str);
		exit(EXIT_FAILURE);
	}
	if (str[0] == 'L')
	{
		ft_fprintf(2, RED"Room line error : -->\e[32m%s\e[31m<-- Description of the room contain invalid caractere (\e[32mL\e[31m)\n"END, str);
		exit(EXIT_FAILURE);
	}
}

static void	check_coord_x_y(char *str)
{
	int	i;
	int	loop;
	int	nb_digit;

	i = 0;
	loop = 0;
	nb_digit = 0;
	while (str[i] != ' ') // iter to coord_x
		++i;
	++i;
	while (loop < 2)
	{
		while (str[i] != ' ' && str[i] != '\0')
		{
			++nb_digit;
			if (ft_isdigit(str[i]) == 0 || nb_digit > 10)
			{
				ft_fprintf(2, RED"Room line error : x or y coord contain invalid caractere\n"END, str);
				exit(EXIT_FAILURE);
			}
			++i;
		}
		++loop;
		nb_digit = 0;
		++i;
	}
}

void	check_if_room_is_valid(char *str)
{
	int	i;

	i = 0;
	check_nb_space(str);
	check_forbidden_character(str);
	check_coord_x_y(str);
	/*while (str[i] != '\0')*/
		/*++i;*/
	/*--i;*/
	/*if (ft_isdigit(str[i]) == 0 || ft_isdigit(str[i - 2]) == 0)*/
	/*{*/
		/*ft_fprintf(2, RED"Room line error : X or Y coord not valid\n"END);*/
		/*exit(EXIT_FAILURE);*/
	/*}*/
}
