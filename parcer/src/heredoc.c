/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:45:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/15 22:26:03 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heredoc.h"

char	*my_recat(char *d, char *s, t_ui32 size)
{
	d = ft_realloc(d, size + 1);
	ft_strlcat(d, s, size + 1);
	return (d);
}

char	*str_collect(char *str, int count, char c, t_lexer *l)
{
	if (c == '>')
		str = my_recat(str, ">>>", ui_strlen(str) + count);
	else if (c == '<')
		str = my_recat(str, "<<<", ui_strlen(str) + count);
	str = my_recat(str, " ", ui_strlen(str) + 1);
	lexer_skip_spaces(l);
	if (!count)
		str = my_recat(str, &l->c, ui_strlen(str) + 1);
	while (!(l->c == '\\' || l->c == '|' || l->c == '-'
			|| l->c == '<' || l->c == '>')
		&& l->c != ' ' && l->c)
	{
		str = my_recat(str, &l->c, ui_strlen(str) + 1);
		lexer_next(l);
	}
	if (str)
		str = h_var(str, l);
	return (str);
}

char	*check_var(char *s, t_lexer *l)
{
	t_ui32	i;
	char	*line;
	char	*str;

	i = -1;
	str = init_var(1);
	while (s[++i])
	{
		if (s[i] == '$')
		{
			line = c_var(&s[i], &i, l);
			if (line)
			{
				str = my_recat(str, line, ui_strlen(line) + ui_strlen(str) + 1);
				free(line);
			}
			if (s[i] == '\0')
				break ;
		}
		else
			str = my_recat(str, &s[i], ui_strlen(str) + 1);
	}
	return (str);
}

static char	*cot(char *str, t_ui32 *st)
{
	int		i;
	char	*x;

	i = ui_strlen(str) - 2;
	if ((str[0] == '\'' && str[i] == '\'')
		|| (str[0] == '\"' && str[i] == '\"'))
	{
		x = init_var(1);
		x = my_recat(x, &str[1], i);
		free(str);
		*st = 0;
		return (x);
	}
	*st = 1;
	return (str);
}

char	*open_heredoc(t_lexer *l, char *s, char *prompt)
{
	char	*str;
	t_ui32	st;

	signal(SIGINT, sig_had);
	s = str_collect(s, 0, '\0', l);
	str = init_var(1);
	str = my_recat(str, "<< ", 4);
	s = cot(s, &st);
	g_data.cc_var = 0;
	str = here_collect(str, prompt, s);
	free(s);
	if (!(*str))
		return (str);
	else
		str[ui_strlen(str) - 2] = '\0';
	if (st)
		str = check_var(str, l);
	if (str)
		str[ui_strlen(str) - 1] = '\0';
	return (str);
}
