/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:40:57 by tsimitop          #+#    #+#             */
/*   Updated: 2024/04/25 16:50:57 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*info;
	char	*prompt;
	char	*prompt_to_use;

	(void)argv;
	if (argc != 1)
		ft_printf("Minishell executable does not use arguments\n");
	info = ft_calloc(sizeof(t_shell), 1);
	prompt = ft_strjoin("minishell_", getenv("USER"));
	if (!prompt)
		return (0);
	prompt_to_use = ft_strjoin(prompt, "$ ");
	if (!prompt_to_use)
		return (free(prompt), 0);
	initialise_basics(argc, env, info);
	minishell_loop(info, prompt_to_use, env); //allocate environment properly
	return (0);
}

void	initialise_basics(int argc, char **env, t_shell *info)
{
	char	cwd[1024];
	info->argc = argc;
	info->env = env; //env not properly initialized?
	info->cwd = getcwd(cwd, sizeof(cwd));
}



// void	is_word()