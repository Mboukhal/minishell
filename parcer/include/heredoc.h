/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:12:42 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/11 13:59:52 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include "lexer.h"
# define    APP_NAME    "Minishell" 

char	*my_recat(char *d, char *s, t_ui32 size);
void	sig_had(int sig);
char	*here_collect(char *str, char *prompt, char *s);

#endif
