/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:36:06 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 17:10:44 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_exec.h"

static int	cheak_exit_val(char	*cmd)
{
	unsigned long long	res;
	int					i;

	i = -1;
	while (cmd[++i] == '0')
		;
	if (!cmd[i])
		return (0);
	res = ft_atoi(cmd);
	if (!res || res > LONG_LONG_MAX)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	return ((char)res);
}

void	check_for_exit(char **cmd)
{
	int	e;

	e = 0;
	if (cmd)
	{
		if (is_eqoul_e(cmd[0], "exit"))
		{
			if (cmd[1])
			{
				e = cheak_exit_val(cmd[1]);
				ft_putstr_fd("exit\n", 2);
				exit(e);
			}
			else
			{
				ft_putstr_fd("exit\n", 2);
				exit(g_data.ret_val);
			}
		}
	}
}
