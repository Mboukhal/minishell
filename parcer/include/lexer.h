/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:02:56 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/16 16:50:25 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "token.h"
# include "utils.h"
# include "parser.h"
# include "heredoc.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef unsigned int	t_ui32;

typedef struct LEXER_STRUCT
{
	char		c;
	t_ui32		i;
	t_ui32		echo;
	t_ui32		st;
	t_ui32		export;
	t_ui32		return_prompt;
	int			last_t;
	char		**cmd;
	char		**env;
	char		*contents;
}		t_lexer;

t_lexer		*init_lexer(char *cont, char **envs, t_ui32 st);
t_token		*lexer_next_token(t_lexer *lex);
t_token		*lexer_collect_str(t_lexer *lex, int type);
t_token		*lexer_collect_var(t_lexer *lex);
t_token		*lexer_advance_with_token(t_lexer *lex, t_token *token);
t_token		*lexer_collect_str_qouts(t_lexer *lex, char c);
t_token		*switch_lex(t_lexer *lex);
t_token		*token_collect(t_lexer *lex, int type);
t_token		*collect_redirect(t_lexer *lex, int type);
t_token		lexer_collect_backslash(t_lexer *lex);
t_token		*lexer_collect_arg(t_lexer *lex);
t_token		*collect_backslash(t_lexer *lex);
t_token		*token_collect_redire(t_lexer *lex);
char		**init_parser(char *s, char **env, int *stat);
char		*get_next_token(t_lexer *lex);
char		*open_heredoc(t_lexer *l, char *s, char *prompt);
char		*lexer_char_as_str(t_lexer *lex);
char		**get_next(t_lexer *lex, int *st);
char		*open_get_new(char c);
char		**ft_add_str(char **d, char *s);
char		*chack_dup(char *val);
char		**merge(t_lexer *le, char *s, t_token *t);
char		*str_collect(char *str, int count, char c, t_lexer *l);
void		lexer_next(t_lexer *lex);
int			lexer_skip_spaces(t_lexer *lex);
int			lexer_skip_dup_qout(t_lexer *lex);
char		*print_err(t_lexer *l, char *err, int code);
char		*ft_getenv_lex(char *var, t_lexer *l);
char		*collect_var_ret(char *line, char *s, t_lexer *lex, t_ui32 *i);
char		*c_var(char *str, t_ui32 *r, t_lexer *l);
char		*check_var(char *s, t_lexer *l);
char		*h_var(char *s, t_lexer *l);
char		*add_sp(char *val, t_lexer *lex, int type);
char		*check_var_s(char *s, t_lexer *lex);

#endif

// debug func
// # define LOG(x) printf("[%s][%p]\n", x, x);
// # define LEAK system("echo '\e[31m'; \
// 				leaks minishell | grep \': \
// 				0x\\|leaks for\'; echo '\e[00m'");