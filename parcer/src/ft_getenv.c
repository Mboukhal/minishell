/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:37:06 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/14 16:25:59 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

static char	*check_va(char *var, char *res, t_lexer *lex)
{
	if (!var || !(*var))
	{
		free(var);
		res = my_recat(res, "$", 2);
		return (res);
	}
	if (var[0] == '?' && var[1] == 0)
	{
		free(var);
		free(res);
		return (itch(lex->st));
	}
	return (res);
}

// TODO:
char	*ft_getenv_lex(char *var, t_lexer *l)
{
	t_ui32	i;
	t_ui32	len;
	char	*res;

	res = init_var(1);
	res = check_va(var, res, l);
	if (*res != 0)
		return (res);
	i = -1;
	while (l->env[++i])
	{
		len = ui_strlen(var);
		if (!(ft_strncmp(l->env[i], var, len - 1)))
		{
			free(var);
			res = my_recat(res, &l->env[i][len], len
					+ ui_strlen(&l->env[i][len]) + 1);
			return (res);
		}
	}
	free(var);
	free(res);
	return (NULL);
}
