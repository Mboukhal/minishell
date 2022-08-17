/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:23:38 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 13:57:45 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	herdoc_handel(char	**cmd)
{
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (cmd[++i])
	{
		c = herdoc_handel2(cmd, i);
		if (c)
			i = 0;
	}
	return (c);
}

int	ft_file_ma(char	**cmd)
{
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (cmd[++i])
	{
		if (cmd[i][0] == '>' && cmd[i][1] == '>')
		{	
			c = add_to_a_file(cmd[i + 1]);
			free_tmp(cmd, i);
			free_tmp(cmd, i);
			i = 0;
		}
		else if (cmd[i][0] == '>' && cmd[i][1] != '>')
		{
			c = create_and_to_a_file(cmd[i + 1]);
			free_tmp(cmd, i);
			free_tmp(cmd, i);
			i = 0;
		}
	}
	if (c == -1)
		return (-1);
	return (herdoc_handel(cmd));
}

void	handl_echo(char	**cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	if (i == 1)
	{
		printf("\n");
		return ;
	}
	else if (i == 2)
	{
		if (cmd[1][0] == 'n')
			return ;
	}
	if (cmd[1][0] == '-' && cmd[1][1] == 'n')
		ft_echo(cmd + 2, 0);
	else
		ft_echo(cmd + 1, 1);
}

int	bul(char	**cmd)
{
	if (cmd[0][0] == '\0')
	{
		ft_putendl_fd("Minishell: : command not found", 2);
		g_data.ret_val = 127;
	}
	else if (is_eqoul_e("echo", cmd[0]))
		handl_echo(cmd);
	else if (is_eqoul_e("cd", cmd[0]))
		ft_cd(cmd[1]);
	else if (is_eqoul_e("pwd", cmd[0]))
		ft_pwd();
	else if (is_eqoul_e("exit", cmd[0]))
		check_ff(cmd);
	else if (is_eqoul_e("export", cmd[0]))
		ft_export(cmd +1);
	else if (is_eqoul_e("unset", cmd[0]))
		ft_unset(cmd + 1);
	else if (is_eqoul_e("env", cmd[0]))
		ft_print_env();
	else
		return (0);
	return (1);
}

void	ft_exec(char	**cmd)
{
	int		fd[2];
	int		i;
	int		st;

	fd[0] = dup(0);
	fd[1] = dup(1);
	g_data.ret_val = 0;
	if (ft_file_ma(cmd) == -1)
		return ;
	if (cmd[0] == NULL)
		;
	else if (bul(cmd))
		;
	else
	{
		i = fork();
		if (i == 0)
			other (cmd);
		waitpid(i, &st, 0);
		if (!g_data.in_process)
			g_data.ret_val = WEXITSTATUS(st);
	}
	dup2(fd[0], 0);
	dup2(fd[1], 1);
}
