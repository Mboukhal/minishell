/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:22:14 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/16 16:56:18 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	last_char_test(t_token *val)
{
	if (val->e_type != T_PIPE
		&& val->e_type != T_BLASH)
		return (1);
	return (0);
}

	// if ((token->e_type == T_QUOT || token->e_type == T_DQUOT)
	// 	&& lex->last_t == 255)
	// 	token->e_type = T_PROG;
	// printf("\t\ttoken1 ([%s], [%d]) [%d]\n", token->val,
			//  token->e_type, lex->export % 2);
char	*cheak_tok(t_token *token, t_lexer *lex, char *str)
{
	if (token->e_type == T_PROG && !ft_strncmp("echo", token->val, 5))
		lex->echo = 1;
	if (token->e_type == T_PROG && !ft_strncmp("export", token->val, 7))
		lex->export = 1;
	if (lex->export)
		lex->export++;
	if ((int)token->e_type == lex->last_t && (token->e_type == T_DQUOT
			|| token->e_type == T_OPTION) && ((!(lex->export % 2)
				&& lex->export) || lex->echo))
	{
		lex->cmd = merge(lex, str, token);
		*str = 0;
		free(token);
		str = my_recat(str, " ", 2);
		return (str);
	}
	lex->last_t = (int)token->e_type;
	free(token);
	if (token->e_type == T_BLASH && token->val[0]
		== ' ' && token->val[1] == '\0')
		str = my_recat(str, "\\ ", 3);
	return (str);
}

char	*itch(int i)
{
	int		j;
	int		c;
	char	*ptr;

	j = 1;
	c = i;
	while (c > 10)
	{
		c = c / 10;
		j = j * 10;
	}
	ptr = (char *)malloc(j + 2);
	c = 0;
	while (j > 0)
	{
		while (j > 0)
		{
			ptr[c++] = i / j + '0';
			i = i - (i / j) * j;
			j = j / 10;
		}
	}
	ptr[c] = '\0';
	return (ptr);
}

char	*get_next_token(t_lexer *lex)
{
	t_token		*token;
	char		*str;

	token = lexer_next_token(lex);
	if (!token)
		return (NULL);
	str = token->val;
	str = cheak_tok(token, lex, str);
	return (str);
}

char	**free_last(t_lexer *lex, int *st)
{
	int	i;

	if (lex->return_prompt)
	{
		*st = lex->return_prompt;
		i = -1;
		while (lex->cmd[++i])
			free(lex->cmd[i]);
		free(lex->cmd);
	}
	free(lex->contents);
	free(lex);
	return (NULL);
}
