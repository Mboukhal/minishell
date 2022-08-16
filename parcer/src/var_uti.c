/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_uti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:32:40 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/15 15:17:28 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

char	*collect_var_ret(char *line, char *s, t_lexer *lex, t_ui32 *i)
{
	char	*var;

	var = init_var(1);
	(*i)++;
	while (ft_isalnum(s[*i]) || s[*i] == '_' || s[*i] == '?' )
		var = my_recat(var, &s[(*i)++], ui_strlen(var) + 1);
	if (s[*i] == '\0' || s[*i] == ' ' || s[*i] == '\'')
		var = ft_getenv_lex(var, lex);
	else
		line = my_recat(line, "$", ui_strlen(line) + 1);
	if (var)
	{
		line = my_recat(line, var, ui_strlen(line) + ui_strlen(var) + 1);
		free(var);
	}
	(*i)--;
	return (line);
}

char	*c_var(char *str, t_ui32 *r, t_lexer *l)
{
	char	*val;
	char	*variable;
	t_ui32	i;

	val = init_var(1);
	i = 1;
	while (ft_isalnum(str[i]) || str[i] == '_')
		val = my_recat(val, &str[i++], ui_strlen(val) + 1);
	variable = ft_getenv_lex(val, l);
	*r += i - 1;
	if (!variable)
		return (NULL);
	return (variable);
}

char	*h_var(char *s, t_lexer *l)
{
	char	*str;
	char	*dupi;

	dupi = init_var(1);
	dupi = my_recat(dupi, &s[2], ui_strlen(&s[2]) + 1);
	str = check_var(&s[2], l);
	if (!str)
	{
		free(s);
		free(str);
		return (dupi);
	}
	free(s);
	free(dupi);
	return (str);
}
