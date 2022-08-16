/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_slash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:52:47 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/11 14:18:59 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

char	*collect_bs(t_lexer *lex)
{
	char	*tmp;

	g_data.cc_var = 0;
	signal(SIGINT, sig_had);
	tmp = readline("> ");
	if (!tmp || !(*tmp) || g_data.cc_var)
		return (NULL);
	else
		tmp = check_var(tmp, lex);
	return (tmp);
}

void	insert(char *va, t_lexer *lex, t_ui32 index)
{
	char	*tmp;
	t_ui32	len;

	len = ui_strlen(&lex->contents[lex->i]) + 1;
	tmp = init_var(1);
	tmp = my_recat(tmp, &lex->contents[lex->i], len);
	lex->contents[index] = '\0';
	len = ui_strlen(lex->contents) + ui_strlen(va) + 1;
	lex->contents = my_recat(lex->contents, va, len);
	len = ui_strlen(lex->contents) + ui_strlen(tmp) + 1;
	lex->contents = my_recat(lex->contents, tmp, len);
	free(tmp);
}

void	cheak_expand(t_lexer *lex, t_ui32 i)
{
	t_ui32	tmp;
	char	*var;
	char	*varx;

	var = init_var(1);
	if ((i % 2) == 0)
	{
		while (lex->c != '$' && lex->c)
			lexer_next(lex);
		tmp = lex->i;
		lexer_next(lex);
		if (!lex->c)
			return ;
		while (lex->c != '|' && lex->c != ' '
			&& lex->c != '<' && lex->c != '>' && lex->c)
		{
			var = my_recat(var, &lex->c, ui_strlen(var) + 1);
			lexer_next(lex);
		}
		varx = ft_getenv_lex(var, lex);
		free(var);
		if (varx)
			insert(varx, lex, tmp);
	}
}

void	check_bs_err(t_lexer *lex)
{
	t_ui32	i;
	t_ui32	first;
	t_ui32	last;
	t_ui32	tmp;

	i = 0;
	first = lex->i;
	tmp = lex->i;
	while (lex->c == '\\')
	{
		lexer_next(lex);
		i++;
	}
	last = lex->i;
	if (i > 1)
		i /= 2;
	first += i;
	while (lex->contents[last])
		lex->contents[first++] = lex->contents[last++];
	lex->contents[first] = '\0';
	lex->i = tmp;
	lex->c = lex->contents[tmp];
}

t_token	*collect_backslash(t_lexer *lex)
{
	char	*val;

	lexer_next(lex);
	if (!lex->c)
	{
		val = collect_bs(lex);
		if (!val)
			return (NULL);
	}
	else
	{
		val = init_var(2);
		check_bs_err(lex);
		*val = lex->c;
		lex->i -= 2;
		lexer_next(lex);
		lexer_next(lex);
		while (lex->c != '|' && lex->c != ' '
			&& lex->c != '<' && lex->c != '>' && lex->c)
		{
			val = my_recat(val, &lex->c, ui_strlen(val) + 1);
			lexer_next(lex);
		}
	}
	return (init_token(T_BLASH, val));
}
