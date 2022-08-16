/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:28:18 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/16 17:02:51 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

char	*add_sp(char *val, t_lexer *lex, int type)
{
	char	tmp;
	char	tmp2;

	tmp = lex->c;
	tmp2 = lex->contents[lex->i - 1];
	lexer_skip_spaces(lex);
	if (lex->echo && tmp == ' ' && type == T_DQUOT)
		val = my_recat(val, " ", ui_strlen(val) + 1);
	return (val);
}

t_token	*lexer_collect_str(t_lexer *lex, int type)
{
	char	*val;

	val = init_var(1);
	if (type == T_OPTION)
	{
		val = my_recat(val, "-", 2);
		lexer_next(lex);
	}
	while (!(lex->c == '\"' || lex->c == '\\' || lex->c == '\''
			|| lex->c == '|' || lex->c == ' '
			|| lex->c == '>' || lex->c == '<')
		&& lex->c)
	{
		val = my_recat(val, &lex->c, ui_strlen(val) + 1);
		if (lex->export && lex->c == '=')
		{
			lexer_next(lex);
			break ;
		}
		lexer_next(lex);
	}
	val = check_var_s(val, lex);
	val = add_sp(val, lex, type);
	return (init_token(type, val));
}

t_token	*lexer_collect_var(t_lexer *lex)
{
	char	*val;

	val = init_var(1);
	lexer_next(lex);
	while ((ft_isalnum(lex->c) || lex->c == '_' || lex->c == '?') && lex->c)
	{
		val = my_recat(val, &lex->c, ui_strlen(val) + 1);
		lexer_next(lex);
	}
	val = ft_getenv_lex(val, lex);
	if (lex->c == ' ' && (lex->contents[lex->i - 1] != '?'))
		val = my_recat(val, " ", ui_strlen(val) + 1);
	if (lex->contents[lex->i - 1] == '?')
		return (init_token(T_STR, val));
	return (init_token(T_DQUOT, val));
}
