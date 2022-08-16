/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:01:52 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/01 18:09:40 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char	*ft_strjoin(char	*s1, char	*s2)
{
	char	*ptr;
	int		j;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	j = ft_strlen(s2);
	i = ft_strlen(s1);
	ptr = malloc(i + j + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	if (j > 0)
	{
		j = 0;
		while (s2[j])
			ptr[i++] = s2[j++];
	}
	ptr[i] = 0;
	free(s1);
	return (ptr);
}
