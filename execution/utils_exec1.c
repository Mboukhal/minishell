/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:52:32 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 17:08:42 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	count(char **data)
{
	int		i;

	i = -1;
	while (data[++i])
		;
	return (i);
}

int	is_eqoul_bul(char	*s1, char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else
			return (0);
		i++;
	}
	if (s2[j] != '\0')
		return (0);
	return (1);
}
