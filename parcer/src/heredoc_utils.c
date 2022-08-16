/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:42:48 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/11 14:12:28 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heredoc.h"

void	sig_had(int sig)
{
	if (sig == 2)
		g_data.cc_var = 1;
	return ;
}

char	*here_collect(char *str, char *prompt, char *s)
{
	char		*tmp;

	while (1)
	{
		tmp = readline(prompt);
		if (!tmp || g_data.cc_var)
		{
			free(tmp);
			*str = 0;
			printf("\e[F\e[2K");
			return (str);
		}
		if ((!ft_strncmp(tmp, s, ui_strlen(s))
				&& ui_strlen(tmp) == ui_strlen(s)))
			break ;
		str = my_recat(str, tmp, ui_strlen(str) + ui_strlen(tmp));
		free(tmp);
		str = my_recat(str, "\n", ui_strlen(str) + 1);
	}
	free(tmp);
	return (str);
}
