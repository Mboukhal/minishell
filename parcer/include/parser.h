/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:04:58 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/16 12:55:24 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"
# define PS1 "[Minishell V0.1] > "
# define PS2 "> "
# define PSH "HEREDOC> "

typedef struct LEXER_STRUCT	t_parser;

typedef struct s_handle
{
	char	**env;
	char	*pwd;
	pid_t	pid;
	int		ret_val;
	int		in_pipe;
	int		in_process;
	int		cc_var;
}				t_handel;

t_handel					g_data;
int							last_char_test(t_token *val);
char						*cheak_for_heredoc(char *s);
char						**free_last(t_parser *lex, int *st);
t_ui32						token_len(char *s);
char						*itch(int i);

#endif	
