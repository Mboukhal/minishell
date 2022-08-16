/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:15:17 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/09 18:56:41 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

static int	is_eqoul_p(char	*s1, char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		if (s2[i] == s1[j])
			j++;
		else
			return (0);
		i++;
	}
	return (1);
}

char	*ft_pwd(void)
{
	char	*tmp;
	int		i;

	tmp = getcwd(NULL, 0);
	if (tmp == NULL)
	{
		i = -1;
		while (g_data.env[++i])
		{
			if (is_eqoul_p(g_data.env[i], "PWD") == 1)
				break ;
		}
		printf("%s\n", g_data.env[i] + 4);
		return (0);
	}
	printf("%s\n", tmp);
	free(tmp);
	return (0);
}
