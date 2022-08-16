/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_or_create_to_afile.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:31:02 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/06 19:18:26 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	add_to_a_file(char	*file)
{
	int		i;

	if (access(file, W_OK) == -1 && access(file, F_OK) == 0)
	{
		printf("minishell: %s: Permission denied", file);
		return ;
	}
	i = open(file, O_CREAT | O_RDWR | O_APPEND, 0666);
	dup2(i, 1);
	close(i);
}

void	create_and_to_a_file(char	*file)
{
	int	i;

	if (access(file, W_OK) == -1 && access(file, F_OK) == 0)
	{
		printf("minishell: %s: Permission denied\n", file);
		return ;
	}
	i = open(file, O_CREAT | O_RDWR | O_TRUNC, 0666);
	dup2(i, 1);
	close(i);
}
