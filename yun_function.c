/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yun_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:45:07 by tsimitop          #+#    #+#             */
/*   Updated: 2024/04/25 16:45:25 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	inputis(char *inpt, char *string)
{
	int	len;

	len = 0;
	if (ft_strlen(inpt) < ft_strlen(string))
		len = ft_strlen(string);
	else
		len = ft_strlen(inpt);
	if (ft_strncmp(inpt, string, len) == 0)
		return (1);
	else
		return (0);
}

