/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:45:51 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/15 18:14:42 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

char	*ldire(t_lexer *l)
{
	t_ui32	i;
	char	*str;

	i = 0;
	str = init_var(1);
	while (l->c == '<')
	{
		i++;
		lexer_next(l);
	}
	lexer_skip_spaces(l);
	if (!l->c || i >= 4)
	{
		free(str);
		return (print_err(l,
				"syntax error near unexpected token `newline'", 258));
	}
	else if (i == 3 || i == 1)
		str = str_collect(str, i, '<', l);
	else if (i == 2)
		str = open_heredoc(l, str, "> ");
	return (str);
}

char	*rdire(t_lexer *l)
{
	t_ui32	i;
	char	*str;

	i = 0;
	str = init_var(1);
	while (l->c == '>')
	{
		lexer_next(l);
		i++;
	}
	lexer_skip_spaces(l);
	if (!l->c || i >= 3)
	{
		free(str);
		return (print_err(l,
				"syntax error near unexpected token `newline'", 258));
	}
	else if (i == 2)
		str = my_recat(str, ">>", 3);
	else if (i == 1)
		str = my_recat(str, ">", 2);
	return (str);
}

char	*check_heredoc(t_lexer *l, int *type)
{
	char	*str;

	str = NULL;
	if (l->c == '<')
	{
		*type = T_LREDIR;
		str = ldire(l);
	}
	else if (l->c == '>')
	{
		*type = T_LREDIR;
		str = rdire(l);
	}
	return (str);
}

t_token	*token_collect_redire(t_lexer *lex)
{
	int		type;
	char	*str;

	str = check_heredoc(lex, &type);
	return (init_token(type, str));
}
