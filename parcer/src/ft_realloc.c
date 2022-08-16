/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:35:09 by mboukhal          #+#    #+#             */
/*   Updated: 2022/07/28 21:51:47 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	*ft_realloc(void *ptr, int size)
{
	char	*tmp;
	int		i;
	char	*p;

	p = (char *) ptr;
	tmp = malloc(size * sizeof(char));
	if (!tmp)
		return (NULL);
	i = -1;
	while (p[++i])
		tmp[i] = p[i];
	tmp[i] = p[i];
	free(p);
	return (tmp);
}

static void	set_new_buff(char **ptr, t_ui32 *i, char **tmp)
{
	t_ui32	len;

	while (ptr[*i])
	{
		len = ui_strlen(ptr[*i]) + 1;
		tmp[*i] = init_var(len);
		ft_strlcat(tmp[*i], ptr[*i], len);
		free(ptr[(*i)++]);
	}
	free(ptr);
}

char	**ft_realloc_cat_doubl(char **ptr, char *s, t_ui32 size)
{
	char		**tmp;
	t_ui32		i;
	t_ui32		len;

	tmp = malloc((size + 1) * sizeof(char *));
	if (!tmp)
		return (NULL);
	i = 0;
	if (size > 1)
		set_new_buff(ptr, &i, tmp);
	len = ui_strlen(s);
	tmp[i] = init_var(len + 1);
	ft_strlcat(tmp[i++], s, len + 1);
	tmp[i] = NULL;
	return (tmp);
}
