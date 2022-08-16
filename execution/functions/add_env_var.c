/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:13 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/06 19:08:23 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int	check_for_env(int i)
{
	int	j;

	j = -1;
	while (g_data.env[i][++j])
	{
		if (g_data.env[i][j] == '=')
			return (1);
	}
	return (0);
}

void	ft_print_env(void)
{
	int	i;

	i = -1;
	while (g_data.env[++i])
	{
		if (check_for_env(i))
			printf("%s\n", g_data.env[i]);
	}
}

int	is_eqoul_env(char	*s1, char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i] && s2[i] != '=')
	{
		if (s2[i] == s1[j])
			j++;
		else
			return (0);
		i++;
	}
	if (s1[j] != '=' && s2[i] == '=')
		return (0);
	return (1);
}

char	**mod(char *s2)
{
	char	**ptr;
	int		i;

	i = -1;
	while (g_data.env[++i])
		;
	ptr = (char **)malloc((i + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = -1;
	while (g_data.env[++i])
	{
		ptr[i] = init_var(1);
		if (is_eqoul_env(g_data.env[i], s2) == 1)
			ptr[i] = my_recat(ptr[i], s2, ft_strlen(s2) + 1);
		else
			ptr[i] = my_recat(ptr[i], g_data.env[i],
					ft_strlen(g_data.env[i]) + 1);
		free(g_data.env[i]);
	}
	ptr[i] = NULL;
	free(g_data.env);
	return (ptr);
}

char	**add(char *s2)
{
	char	**ptr;
	int		i;

	i = -1;
	while (g_data.env[++i])
	{
		if (is_eqoul_env(g_data.env[i], s2) == 1)
			return (mod(s2));
	}
	ptr = (char **)malloc((i + 2) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = -1;
	while (g_data.env[++i])
	{
		ptr[i] = init_var(1);
		ptr[i] = my_recat(ptr[i], g_data.env[i], ft_strlen(g_data.env[i]) + 1);
		free(g_data.env[i]);
	}
	ptr[i] = init_var(1);
	ptr[i] = my_recat(ptr[i], s2, ft_strlen(s2) + 1);
	ptr[++i] = NULL;
	free(g_data.env);
	return (ptr);
}
