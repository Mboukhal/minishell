/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:27:46 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 16:56:32 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int	is_eqoul(char	*s1, char	*s2)
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
	if (s1[j] == '=')
		return (1);
	return (0);
}

void	mod_env1(char	**pwds)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while (g_data.env[++i])
	{
		if (is_eqoul(g_data.env[i], "PWD") == 1)
		{
			tmp = pwds[1];
			pwds[1] = ft_strjoin(ft_strdup("PWD="), pwds[1]);
			tmp2 = g_data.env[i];
			g_data.env[i] = pwds[1];
			free(g_data.pwd);
			g_data.pwd = ft_strdup(pwds[1] + 4);
			free(tmp);
			free(tmp2);
		}
	}
}

void	mod_env(char	**pwds)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	mod_env1(pwds);
	i = -1;
	while (g_data.env[++i])
	{
		if (is_eqoul(g_data.env[i], "OLDPWD") == 1)
		{
			tmp = pwds[0];
			pwds[0] = ft_strjoin(ft_strdup("OLDPWD="), pwds[0]);
			tmp2 = g_data.env[i];
			g_data.env[i] = pwds[0];
			free(tmp);
			free(tmp2);
			return ;
		}
	}
	g_data.env = add(ft_strjoin(ft_strdup("OLDPWD="), pwds[0]));
}
