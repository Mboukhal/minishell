/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:42:32 by mait-aad          #+#    #+#             */
/*   Updated: 2022/08/17 13:33:28 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

t_data	*next(t_data	*lst)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	lst->next = new;
	new->next = NULL;
	return (new);
}

t_data	*edit_export(void)
{
	int		i;
	t_data	*head;
	t_data	*tmp;

	i = 0;
	head = (t_data *)malloc(sizeof(t_data));
	tmp = head;
	while (g_data.env[i])
	{
		tmp->vars = ft_split(g_data.env[i], '=');
		tmp->key = tmp->vars[0];
		tmp->val = tmp->vars[1];
		free(tmp->vars);
		next(tmp);
		tmp = next(tmp);
		i++;
	}
	return (head);
}

int	chack_var(char	*s)
{
	if ((s[0] >= 'A' && s[0] <= 'Z')
		|| (s[0] >= 'a' && s[0] <= 'z'))
		return (1);
	return (0);
}

void	add2(char	**data)
{
	int	i;

	i = -1;
	while (data[++i])
	{
		if (chack_var(data[i]) == 1)
			g_data.env = add(data[i]);
		else
		{
			g_data.ret_val = 1;
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(data[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return ;
		}
	}
}

char	*ft_export(char	**data)
{
	int		i;
	t_data	*env_vars;

	i = count(data);
	if (i == 0)
	{
		i = fork();
		if (i == 0)
		{
			env_vars = edit_export();
			while (env_vars->next != NULL)
			{
				if (!env_vars->val)
					printf("declare -x %s\n", env_vars->key);
				else
					printf("declare -x %s=\"%s\"\n", env_vars->key, env_vars->val);
				env_vars = env_vars->next;
			}
			exit(0);
		}
		waitpid(i, NULL, 0);
		return (0);
	}
	add2(data);
	return (0);
}
