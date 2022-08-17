/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:41:50 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 15:01:23 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H
# include "functions/func.h"
# include <readline/readline.h>
# include <limits.h>
# include <readline/history.h>
# include "../parcer/include/utils.h"
# include "../parcer/include/parser.h"

unsigned long long		ft_atoi(const char *str);
int		                is_eqoul_e(char	*s1, char	*s2);
void	                ft_putstr_fd(char *s, int fd);
void	                ft_exec(char **cmd);
void	                ft_pipes(char **cmd);
void	                exit_func(char *arg);
void	                check_for_exit(char **cmd);
int		                herdoc_handel2(char	**cmd, int i);
int		                is_eqoul_e(char	*s1, char	*s2);
void	                init_global(char	**e);
void	                free_data(char **data);
void	                sig_handler(int sig);
char	                **cat_cmd(char	**cmd, char c);
int		                count(char **data);
int		                check_ff(char **cmd);
void	                free_tmp(char	**cmd, int i);

#endif
