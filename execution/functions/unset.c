/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:17:13 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/14 16:04:08 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char	**rm_va(char *s1)
{
	char	**ptr;
	int		i;
	int		j;

	i = -1;
	while (g_data.env[++i])
		;
	ptr = (char **)malloc(sizeof(char *) * (i));
	i = -1;
	j = -1;
	while (g_data.env[++i])
	{
		if (is_eqoul(g_data.env[i], s1) == 1)
			free (g_data.env[i]);
		else
		{
			ptr[++j] = init_var(1);
			ptr[j] = my_recat(ptr[j], g_data.env[i],
					ft_strlen(g_data.env[i]) + 1);
			free (g_data.env[i]);
		}
	}
	ptr[++j] = NULL;
	free(g_data.env);
	return (ptr);
}

static int	chack_var(char	*s)
{
	if ((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z'))
		return (1);
	return (0);
}

int	is_ex(char	*s)
{
	int	i;

	i = -1;
	while (g_data.env[++i])
	{
		if (is_eqoul(g_data.env[i], s))
			return (1);
	}
	return (0);
}

char	*ft_unset(char	**para)
{
	int	i;

	i = -1;
	while (para[++i])
	{
		if (chack_var(para[i]) == 1 && is_ex(para[i]))
			g_data.env = rm_va(para[i]);
		else if (chack_var(para[i]) == 0)
		{
			printf("minishell: unset: `%s': not a valid identifier\n", para[i]);
			return (0);
		}
		else if (is_ex(para[i]) == 0)
			;
	}
	return (0);
}
