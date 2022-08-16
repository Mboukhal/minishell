/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:31:14 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/16 17:06:46 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/ft_exec.h"

static int	pipe_it(char **data)
{
	int	i;
	int	st;

	g_data.in_pipe = 1;
	i = fork();
	if (i == 0)
		ft_pipes(data);
	waitpid(i, &st, 0);
	if (!g_data.in_process)
		g_data.ret_val = WEXITSTATUS(st);
	free_data(data);
	return (1);
}

static int	exec_condition(char	**data)
{
	int		i;

	if (data)
	{
		i = -1;
		while (data[++i])
		{
			signal(SIGQUIT, sig_handler);
			g_data.in_process = 1;
			if (data[i][0] == '|')
				return (pipe_it(data));
			else if (data[i + 1] == NULL)
				ft_exec(data);
			g_data.in_pipe = 0;
			g_data.in_process = 0;
			signal(SIGQUIT, SIG_IGN);
		}
		free_data(data);
	}
	return (1);
}

static int	check_spase(char *s)
{
	int	i;

	i = -1;
	while (s[++i] == ' ')
		;
	if (s[i] == '|')
	{
		ft_putstr_fd(APP_NAME, 2);
		ft_putstr_fd(": syntax error near unexpected token `|", 2);
		if (s[++i] == '|')
			ft_putendl_fd("|\'", 2);
		else
			ft_putendl_fd("\'", 2);
		g_data.ret_val = 258;
		return (0);
	}
	else if (s[i])
		return (1);
	add_history(s);
	return (0);
}

static int	loop(void)
{
	char	*s;

	signal(SIGINT, sig_handler);
	s = NULL;
	s = readline(PS1);
	if (s)
	{
		if (*s && check_spase(s))
			exec_condition(init_parser(s,
					g_data.env, &g_data.ret_val));
	}
	else
	{
		free(s);
		return (0);
	}
	free(s);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	rl_catch_signals = 0;
	signal(SIGQUIT, SIG_IGN);
	init_global(env);
	g_data.pwd = ft_getenv("PWD");
	while (loop())
		;
	printf("\e[F%sexit\n", PS1);
	return (EXIT_SUCCESS);
}
