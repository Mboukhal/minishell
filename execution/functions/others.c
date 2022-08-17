/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:52:03 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 17:10:59 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

static int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

unsigned long long	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					signe;

	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			signe = -1;
	result = 0;
	while (ft_isnum(*str) && *str)
	{
		result *= 10;
		result += *(str++) - 48;
	}
	return (result * signe);
}

char	*ft_strcpy(char *s1, char *s2)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = (char *)malloc(ft_strlen(s1)+ ft_strlen(s2) +3);
	i = -1;
	while (s1[++i])
		tmp[i] = s1[i];
	j = 0;
	tmp[i] = '/';
	i++;
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = 0;
	return (tmp);
}

void	other(char	**cmd)
{
	int			i;
	int			ret;
	struct stat	*buf;
	char		*tmp;
	char		**dirs;

	dirs = ft_split(ft_getenv("PATH"), ':');
	buf = malloc(sizeof(struct stat));
	if (access(cmd[0], F_OK) == 0)
		execve(cmd[0], cmd, g_data.env);
	i = -1;
	while (dirs[++i])
	{
		tmp = ft_strcpy(dirs[i], cmd[0]);
		ret = stat(tmp, buf);
		if (ret == 0)
			break ;
		free(tmp);
	}
	if (ret == -1)
		perr(cmd[0], 127);
	execve(tmp, cmd, g_data.env);
}
