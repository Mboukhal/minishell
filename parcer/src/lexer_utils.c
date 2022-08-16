/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:48:03 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/14 15:39:02 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

void	lexer_next(t_lexer *lex)
{
	if (lex->c && ++lex->i < ui_strlen(lex->contents))
		lex->c = lex->contents[lex->i];
}

int	lexer_skip_spaces(t_lexer *lex)
{
	int	i;

	i = 0;
	while (lex->c == ' ' || lex->c == '\n'
		|| lex->c == '\f' || lex->c == '\r'
		|| lex->c == '\v' || lex->c == '\t')
	{
		lexer_next(lex);
		i++;
	}
	return (i);
}

int	lexer_skip_dup_qout(t_lexer *lex)
{
	int	i;

	i = 0;
	if (lex->c == '$')
		return (0);
	lexer_next(lex);
	while (lex->c == '\"')
	{
		lexer_next(lex);
		i++;
	}
	return (i);
}

t_token	*token_collect(t_lexer *lex, int type)
{
	return (lexer_advance_with_token(lex,
			init_token(type, lexer_char_as_str(lex))));
}

	// printf("[%c][%d][%d][%s]\n", 
	//lex->c, lex->i, ui_strlen(lex->contents), lex->contents);
t_token	*lexer_next_token(t_lexer *lex)
{
	while (lex->c && (lex->i < ui_strlen(lex->contents)))
	{
		lexer_skip_spaces(lex);
		if (!lex->c)
			break ;
		return (switch_lex(lex));
	}
	return (NULL);
}
