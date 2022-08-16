/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:22:32 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/11 22:21:46 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <limits.h>
# include "../ft_exec.h"

typedef struct s_data
{
	char			**vars;
	char			*key;
	char			*val;
	struct s_data	*next;
}		t_data;

int			is_eqoul(char	*s1, char	*s2);
char		*ft_strdup(char	*s1);
char		*ft_pwd(void);
void		ft_cd(char *dir);
void		mod_env(char	**pwds);
char		**add(char *s2);
char		*ft_export(char **in);
char		*ft_echo(char	**inputs, int newlin);
void		add_to_a_file(char	*file);
void		create_and_to_a_file(char	*file);
char		*ft_strjoin(char	*s1, char	*s2);
char		*ft_substr(char const *s, int start, int len);
char		**ft_split(char const *s, char c);
char		*ft_unset(char	**para);
int			ft_strlen(char *str);
void		other(char	**cmd);
void		perr(char *s, int code);
char		*ft_getenv(char *var);
void		ft_print_env(void);
char		*openheredoc(char *s, char *prompt);

#endif