/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:04:28 by mait-aad          #+#    #+#             */
/*   Updated: 2022/07/01 15:10:19 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

static int	ft_count_wo(const char	*s, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (i);
}

static int	ft_nextc(const char *s, char c, int i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static char	**make_ptr_free(char	**ptr)
{
	int	i;

	i = 0;
	while (*ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
	return (ptr);
}

static char	**ft_that_do_the_job(char const	*s,	char c, int counter, char **ptr)
{
	int		i;
	int		start;
	int		stop;

	i = 0;
	stop = 0;
	start = 0;
	while (i < counter)
	{
		start = ft_nextc(s, c, stop);
		stop = start;
		while (s[stop] != c && s[stop])
			stop++;
		ptr[i] = ft_substr(s, start, stop - start);
		if (ptr[i] == NULL)
			return (make_ptr_free(ptr));
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		counter;

	if (!s)
		return (0);
	else
	{
		counter = ft_count_wo(s, c);
		ptr = (char **)malloc((counter + 1) * sizeof(char *));
		if (!ptr)
			return (0);
		else
			return (ft_that_do_the_job(s, c, counter, ptr));
	}
}
