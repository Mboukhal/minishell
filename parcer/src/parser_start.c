/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:59:58 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/16 14:31:35 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

char	**init_parser(char *s, char **env, int *stat)
{
	t_lexer	*lex;
	char	**data;

	add_history(s);
	lex = init_lexer(s, env, *stat);
	*stat = lex->return_prompt;
	data = get_next(lex, stat);
	return (data);
}

char	**ft_add_str(char **d, char *s)
{
	char	**newstr;
	t_ui32	i;

	i = 0;
	while (d[i++])
		;
	newstr = malloc(sizeof(char *) * (i + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (d[i])
	{
		newstr[i] = init_var(1);
		newstr[i] = my_recat(newstr[i], d[i], ui_strlen(d[i]) + 1);
		free(d[i++]);
	}
	free(d);
	newstr[i] = init_var(1);
	if (*s == ' ' && s[1] == '\\')
		s[1] = '\0';
	newstr[i] = my_recat(newstr[i], s, ui_strlen(s) + 1);
	free(s);
	newstr[++i] = NULL;
	return (newstr);
}

void	free_new(t_lexer *lex)
{
	t_ui32	i;

	i = 0;
	while (lex->cmd[i])
		free(lex->cmd[i++]);
	*lex->cmd = NULL;
}

// space removed frome break
char	**get_next(t_lexer *lex, int *st)
{
	char	*str_token;

	str_token = get_next_token(lex);
	if (!str_token)
		return (free_last(lex, st));
	lex->cmd = ft_add_str(lex->cmd, str_token);
	while (str_token)
	{
		str_token = get_next_token(lex);
		if (!str_token || lex->return_prompt)
			break ;
		if (!(str_token[0] == ' ' && str_token[1] == '\0'))
			lex->cmd = ft_add_str(lex->cmd, str_token);
		else
			free(str_token);
	}
	if (lex->return_prompt)
		return (free_last(lex, st));
	free_last(lex, st);
	return (lex->cmd);
}

t_lexer	*init_lexer(char *str, char **envs, t_ui32 st)
{
	t_lexer		*lex;
	char		*tmp;

	lex = malloc(sizeof(t_lexer));
	if (!lex)
		return (NULL);
	lex->contents = init_var(1);
	tmp = lex->contents;
	lex->contents = my_recat(lex->contents, str, ui_strlen(str) + 1);
	lex->cmd = malloc(sizeof(char *));
	if (!lex->cmd)
		return (NULL);
	*lex->cmd = NULL;
	lex->env = envs;
	lex->i = 0;
	lex->echo = 0;
	lex->export = 0;
	lex->st = st;
	lex->return_prompt = 0;
	lex->last_t = 255;
	lex->c = lex->contents[lex->i];
	return (lex);
}
