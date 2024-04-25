/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:09:13 by tsimitop          #+#    #+#             */
/*   Updated: 2024/04/25 15:54:48 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft.h"
# include <fcntl.h>

typedef struct s_shell
{
	int		argc;
	char	**env;
	char	*cwd;
}	t_shell;

void	initialise_basics(int argc, char **env, t_shell *info);


#endif
