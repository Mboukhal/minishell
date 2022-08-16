/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:01:07 by mait-aad          #+#    #+#             */
/*   Updated: 2022/07/29 17:19:34 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

static char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char	*s1)
{
	int		i;
	char	*str;
	char	*ptr;

	if (!s1)
		return (0);
	str = (char *)s1;
	i = 0;
	while (str[i])
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (0);
	ft_strcpy(ptr, str);
	ptr [i] = 0;
	return (ptr);
}
