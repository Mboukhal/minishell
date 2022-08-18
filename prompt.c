/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:27:40 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/18 13:15:20 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/ft_exec.h"

char	*prompt(void)
{
	char	*v_prompt;
	char	*tmp;

	v_prompt = init_var(2);
	*v_prompt = '[';
	tmp = itch(g_data.ret_val);
	v_prompt = my_recat(v_prompt, tmp,
			ft_strlen(v_prompt) + ft_strlen(tmp) + 1);
	free(tmp);
	v_prompt = my_recat(v_prompt, "] [", ft_strlen(v_prompt) + 5);
	tmp = ft_getenv("PWD");
	v_prompt = my_recat(v_prompt, tmp,
			ft_strlen(v_prompt) + ft_strlen(tmp) + 1);
	free(tmp);
	v_prompt = my_recat(v_prompt, "] ", ft_strlen(v_prompt) + 4);
	v_prompt = my_recat(v_prompt, PS1,
			ft_strlen(v_prompt) + ft_strlen(PS1) + 1);
	return (v_prompt);
}
