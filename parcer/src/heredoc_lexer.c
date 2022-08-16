/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:02:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/07/28 21:51:47 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

t_token	lexer_collect_backslash(t_lexer *lex)
{
	t_ui32	i;
	char	*err;

	err = init_var(0);
	i = 0;
	while (lex->c == '\\')
	{
		lexer_next(lex);
		i++;
	}
	if (i > 0)
	{
		if (!(i % 2))
		{
			i /= 2;
			while (i--)
				err = my_recat(err, "\\", ui_strlen(err) + 2);
			err = my_recat(err, ": command not found", ui_strlen(err) + 21);
			print_err(lex, err, 127);
			free(err);
		}
	}
	return (init_token(type, val));
}
