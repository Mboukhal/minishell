/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:52:03 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/08 14:10:26 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

char	*chack_dup(char *val)
{
	char	*tmp;
	t_ui32	i;
	t_ui32	j;
	t_ui32	len;

	i = 1;
	tmp = init_var(3);
	*tmp = '-';
	tmp[1] = val[1];
	while (val[++i])
	{
		j = 0;
		while (tmp[++j])
			if (tmp[j] == val[i])
				break ;
		if (tmp[j] != val[i])
		{
			len = ui_strlen(tmp);
			tmp = ft_realloc(tmp, len);
			tmp[len - 1] = val[i];
			tmp[len] = '\0';
		}
	}
	free(val);
	return (tmp);
}

t_token	*lexer_collect_arg(t_lexer *lex)
{
	char	*val;

	val = init_var(1);
	val = my_recat(val, &lex->c, ui_strlen(val) + 1);
	lexer_next(lex);
	while (ft_isalnum(lex->c) && lex->c)
	{
		val = my_recat(val, &lex->c, ui_strlen(val) + 1);
		lexer_next(lex);
	}
	val = chack_dup(val);
	return (init_token(T_OPTION, val));
}
