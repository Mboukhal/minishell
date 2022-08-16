/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:03:20 by mboukhal          #+#    #+#             */
/*   Updated: 2022/07/28 21:58:03 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef unsigned int	t_ui32;
void		*ft_realloc(void *ptr, int size);
t_ui32		ui_strlen(char *s);
t_ui32		ft_strlcat(char *dst, const char *src, t_ui32 dstsize);
int			ft_isalnum(int c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, t_ui32 n);
char		**ft_realloc_cat_doubl(char **ptr, char *s, t_ui32 size);
char		*init_var(t_ui32 size);

#endif
