/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:02:44 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/15 16:40:29 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_pipe2(int	*fd, char	**cmd2, int i)
{
	int	pid2;

	pid2 = fork();
	if (pid2 < 0)
		return (0);
	if (pid2 == 0)
	{
		if (i == 0)
			dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		ft_exec(cmd2);
		exit(0);
	}
	return (pid2);
}

int	handel_pipe(char	**cmd, int j, int c)
{
	int		fd[2];
	int		pid1;
	char	**tmp;

	if (pipe(fd) == -1)
		return (0);
	tmp = cat_cmd(cmd + j, '|');
	pid1 = ft_pipe2(fd, tmp, c);
	free(tmp);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	return (pid1);
}

int	*add_pid(int pid, int	*pids, int len)
{
	int	i;
	int	*tmp;

	if (len == 1)
	{
		pids[0] = pid;
		return (pids);
	}
	else
	{
		tmp = pids;
		pids = malloc((len + 1) * sizeof(int));
		i = -1;
		while (++i < len - 1)
			pids[i] = tmp[i];
		pids[i] = pid;
		free(tmp);
		return (pids);
	}
}

void	ft_pipes(char **cmd)
{
	int	i;
	int	*pids;
	int	j;
	int	c;

	j = 0;
	c = 0;
	i = -1;
	pids = malloc(sizeof(int));
	while (cmd[++i])
	{
		if (cmd[i][0] == '|')
		{
			if (is_eqoul_e(cmd[i], "exit"))
				check_for_exit(cmd + i);
			pids = add_pid(handel_pipe(cmd, j, 0), pids, ++c);
			j = i + 1;
		}
	}
	pids = add_pid(handel_pipe(cmd, j, 1), pids, ++c);
	i = 0;
	while (i <= c)
		waitpid(pids[i++], NULL, 0);
	exit(0);
}
