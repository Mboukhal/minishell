/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:05:25 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/01 18:19:15 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char	*ft_getenv(char *var)
{
	t_ui32	i;
	t_ui32	len;
	t_ui32	vlen;
	char	*res;

	i = -1;
	res = init_var(1);
	while (g_data.env[++i])
	{
		vlen = ft_strlen(var) + 1;
		if (!ft_strncmp(g_data.env[i], var, ft_strlen(var)))
		{
			len = ft_strlen(&g_data.env[i][vlen]) + 1;
			res = my_recat(res, &g_data.env[i][vlen], len);
			return (res);
		}
	}
	res = my_recat(res, "\n", 2);
	return (res);
}
