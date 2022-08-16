/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:05:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/05 22:01:22 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include <stdlib.h>
# include "utils.h"

typedef unsigned int	t_ui32;
typedef struct TOKEN_S
{
	enum
	{
		T_PROG,
		T_STR,
		T_VAR,
		T_BLASH,
		T_RREDIR,
		T_LREDIR,
		T_QUOT,
		T_DQUOT,
		T_DOLAR,
		T_OPTION,
		T_PIPE,
		T_HEREDOC,
		T_HBLASH,
		T_EOF,
	}	e_type;
	char	*val;
}	t_token;

t_token	*init_token(int type, char *val);

#endif
