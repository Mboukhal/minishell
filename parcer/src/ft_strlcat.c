/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:45:54 by mboukhal          #+#    #+#             */
/*   Updated: 2022/07/28 21:51:47 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

t_ui32	ui_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i++])
		;
	return (i);
}

t_ui32	ft_strlcat(char *dst, const char *src, t_ui32 dstsize)
{
	t_ui32	i;
	t_ui32	j;
	t_ui32	dl;
	t_ui32	sl;

	i = 0;
	dl = ui_strlen(dst);
	sl = ui_strlen((char *)src);
	if (dstsize == 0 || dstsize <= dl)
		return (sl + dstsize);
	j = dl - 1;
	while (src[i] && i < dstsize - dl - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dl + sl);
}
