/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 04:02:53 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 13:57:54 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	is_eqoul_e(char	*s1, char	*s2)
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
	return (1);
}

void	free_tmp(char	**cmd, int i)
{
	char	*tmp;

	while (cmd[i])
	{
		if (cmd[i + 1] == NULL)
			break ;
		tmp = cmd[i];
		cmd[i] = cmd[i + 1];
		cmd[i + 1] = tmp;
		i++;
	}
	free(cmd[i + 1]);
	cmd[i] = NULL;
}

int	check_file(char *file)
{
	if (access(file, W_OK) == -1 && access(file, F_OK) == 0)
	{
		g_data.ret_val = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file, 2);
		ft_putendl_fd(": Permission denied", 2);
		return (-1);
	}
	return (1);
}

void	open_and_dup(char	*file)
{
	int	fd2;

	fd2 = open(file, O_RDWR);
	dup2(fd2, 0);
	close(fd2);
}

int	herdoc_handel2(char	**cmd, int i)
{
	int		fd[2];

	if (cmd[i][0] == '<' && cmd[i][1] == '<')
	{
		pipe(fd);
		write(fd[1], cmd[i] + 3, ft_strlen(cmd[i] + 3));
		write(fd[1], "\n", 1);
		dup2(fd[0], 0);
		free_tmp(cmd, i);
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	else if (cmd[i][0] == '<' && cmd[i][1] != '<')
	{
		if (check_file(cmd[i + 1]) == 1)
		{
			open_and_dup(cmd[i + 1]);
			free_tmp(cmd, i);
			return (1);
		}
		else
			return (-1);
	}
	return (0);
}
