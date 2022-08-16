/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:01:30 by mboukhal          #+#    #+#             */
/*   Updated: 2022/07/28 21:51:47 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	ft_strncmp(const char *s1, const char *s2, t_ui32 n)
{
	t_ui32			i;
	unsigned char	*ss1;

	if (n == 0)
		return (0);
	i = 0;
	ss1 = (unsigned char *) s1;
	while (ss1[i] == s2[i] && i <= n && s2[i])
	{
		if (ss1[i] == s2[i] && i + 1 == n)
			return (0);
		i++;
	}
	return (ss1[i] - s2[i]);
}
