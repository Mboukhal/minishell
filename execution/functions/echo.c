/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:42:48 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 13:30:42 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char	*ft_echo(char	**inputs, int newlin)
{
	int		i;
	char	*out;

	i = -1;
	out = NULL;
	while (inputs[++i])
		printf("%s", inputs[i]);
	if (newlin == 0)
		return (0);
	printf("\n");
	return (NULL);
}
