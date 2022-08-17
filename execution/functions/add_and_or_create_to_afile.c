/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_or_create_to_afile.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:31:02 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 13:44:10 by mait-aad         ###   ########.fr       */
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

int	add_to_a_file(char	*file)
{
	int		i;

	if (access(file, W_OK) == -1 && access(file, F_OK) == 0)
	{
		g_data.ret_val = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file, 2);
		ft_putendl_fd(": Permission denied", 2);
		return (-1);
	}
	i = open(file, O_CREAT | O_RDWR | O_APPEND, 0666);
	dup2(i, 1);
	close(i);
	return (1);
}

int	create_and_to_a_file(char	*file)
{
	int	i;

	if (access(file, W_OK) == -1 && access(file, F_OK) == 0)
	{
		g_data.ret_val = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file, 2);
		ft_putendl_fd(": Permission denied", 2);
		return (-1);
	}
	i = open(file, O_CREAT | O_RDWR | O_TRUNC, 0666);
	dup2(i, 1);
	close(i);
	return (1);
}
