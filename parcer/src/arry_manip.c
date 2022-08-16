/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:10:13 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/16 16:46:26 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static char	**ft_change_last(char **d, char *s, char *last)
{
	char		**newstr;
	t_ui32		i;

	free(last);
	i = 0;
	while (d[i++])
		;
	newstr = malloc(sizeof(char *) * (i + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (d[i + 1])
	{
		newstr[i] = init_var(1);
		newstr[i] = my_recat(newstr[i], d[i], ui_strlen(d[i]) + 1);
		free(d[i++]);
	}
	free(d);
	newstr[i] = init_var(1);
	newstr[i] = my_recat(newstr[i], s, ui_strlen(s) + 1);
	newstr[++i] = NULL;
	free(s);
	return (newstr);
}

static char	*last_str(char **val)
{
	t_ui32	i;

	i = 0;
	while (val[i++])
		;
	return (val[i - 2]);
}

	// printf("\t\ttoken([%s], [%d])\n", t->val, t->e_type);
char	**merge(t_lexer *le, char *s, t_token *t)
{
	char	*tmp;
	char	*last;

	tmp = init_var(1);
	last = last_str(le->cmd);
	if (t->e_type == T_OPTION)
	{
		tmp = my_recat(tmp, s, ui_strlen(tmp) + ui_strlen(s) + 1);
		tmp = chack_dup(tmp);
	}
	else if (t->e_type == T_DQUOT && (le->echo || le->export))
	{
		tmp = my_recat(tmp, last, ui_strlen(tmp) + ui_strlen(last) + 1);
		tmp = my_recat(tmp, s, ui_strlen(s) + ui_strlen(tmp) + 1);
	}
	le->cmd = ft_change_last(le->cmd, tmp, last);
	return (le->cmd);
}
