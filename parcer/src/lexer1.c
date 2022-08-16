/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:30:37 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/16 16:55:08 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

int	check_ss(char c, t_lexer *lex)
{
	if (c == '|')
	{
		lex->echo = 0;
		lex->export = 0;
	}
	if (!(c == '\"' || c == '\\' || c == '\''
			|| c == '|' || c == '-' || c == '<'
			|| c == '>'))
		return (1);
	return (0);
}

static int	check_last(t_lexer *lex)
{
	int	i;

	i = lex->last_t;
	if ((i == 255 || i == 10) && i != 0)
		return (1);
	return (0);
}

// printf("[%c]\n", lex->c);
t_token	*switch_lex(t_lexer *lex)
{
	if (lex->return_prompt || !lex->c)
		return (NULL);
	else if ((check_ss(lex->c, lex) && check_last(lex)))
		return (lexer_collect_str(lex, T_PROG));
	else if (check_ss(lex->c, lex))
		return (lexer_collect_str(lex, T_DQUOT));
	else if (lex->c == '\"')
		return (lexer_collect_str_qouts(lex, lex->c));
	else if (lex->c == '\'')
		return (lexer_collect_str_qouts(lex, lex->c));
	else if (lex->c == '-')
		return (lexer_collect_arg(lex));
	else if (lex->c == '|')
		return (token_collect(lex, T_PIPE));
	else if (lex->c == '\\')
		return (collect_backslash(lex));
	else if (lex->c == '<' || lex->c == '>')
		return (token_collect_redire(lex));
	return (NULL);
}

char	*init_var(t_ui32 size)
{
	char	*s;

	s = malloc(sizeof(char) * size);
	if (!s)
		return (NULL);
	s[size - 1] = '\0';
	return (s);
}
