/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:17:15 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/16 16:50:03 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

t_token	*lexer_advance_with_token(t_lexer *lex, t_token *token)
{
	lexer_next(lex);
	return (token);
}

char	*lexer_char_as_str(t_lexer *lex)
{
	char	*str;

	str = init_var(2);
	*str = lex->c;
	*(str + 1) = '\0';
	return (str);
}

char	*check_var_s(char *s, t_lexer *lex)
{
	t_ui32		i;
	char		*line;

	i = -1;
	line = init_var(1);
	while (s[++i])
	{
		if (s[i] == '$')
		{
			line = collect_var_ret(line, s, lex, &i);
			if (s[i] == '\0')
				break ;
		}
		else
			line = my_recat(line, &s[i], ui_strlen(line) + 1);
	}
	line[ui_strlen(line) - 1] = '\0';
	free(s);
	return (line);
}

static char	*collect_qq(char *val, t_lexer *lex, char c)
{
	while (lex->c != c && lex->c)
	{
		val = my_recat(val, &lex->c, ui_strlen(val) + 1);
		lexer_next(lex);
	}
	return (val);
}

t_token	*lexer_collect_str_qouts(t_lexer *lex, char c)
{
	char	*val;

	lexer_next(lex);
	val = init_var(1);
	val = collect_qq(val, lex, c);
	if (!lex->c)
	{
		free(val);
		return ((t_token *)print_err(lex,
				"syntax error qouts not closed", 127));
	}
	lexer_next(lex);
	val = add_sp(val, lex, T_DQUOT);
	if (c == '\"')
		val = check_var_s(val, lex);
	return (init_token(T_DQUOT, val));
}
