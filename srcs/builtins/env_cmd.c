/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:34:43 by ichejra           #+#    #+#             */
/*   Updated: 2020/12/24 12:49:56 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cmd_env(t_cmds *cmds, t_cmd_list *list)
{
	int	i;

	i = 0;
	if (list->args[1] != NULL)
	{
		print_error(list->args[0], list->args[1], 2);
		return (127);
	}
	else
	{
		while (cmds->envir[i] != NULL)
		{
			if (ft_strchr(cmds->envir[i], '='))
				ft_putendl_fd(cmds->envir[i], 1);
			i++;
		}
	}
	return (0);
}
