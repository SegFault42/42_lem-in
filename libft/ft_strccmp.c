/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:54:55 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/19 22:17:12 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strccmp(const char *s1, const char *s2, char c)
{
	int				i;
	int				j;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	j = 0;
	while (s2[j] != c)
		++j;
	++j;
	while (ss1[i] != '\0')
	{
		if (ss2[j] != ss1[i])
			return (ss1[i] - ss2[j]);
		i++;
		j++;
	}
	return (0);
}
