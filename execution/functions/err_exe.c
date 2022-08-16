/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:54:22 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/04 19:05:00 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

void	perr(char *s, int code)
{
	ft_putstr_fd(APP_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	g_data.ret_val = code;
	exit(code);
}
