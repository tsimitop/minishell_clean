/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:52:09 by tsimitop          #+#    #+#             */
/*   Updated: 2024/04/25 17:06:10 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_loop(t_shell *info, char *prompt, char **env)
{
	t_token	*token;
	char	*input_str;
	char	*full_path;
	char 	*cmd;

	while (1)
	{
		if (prompt)
			input_str = readline(prompt);
		if (inputis(input_str, "exit"))
			exit(0);
		if (!inputis(input_str, ""))
			add_history(input_str);
		token = *(info->first_token_node);
		input_types(input_str, info, token);
		// funtion to create tree or bigger linked list
		//new function to do the rest of this working with tree or bigger linked list
		cmd = get_directory_name(input_str); //copy from pipex
		if (!cmd)
		{
			perror("cmd not allocated");
			exit(1);
		}
		if (find_cmd_in_env(cmd, env))	//get from partner
		{
			full_path = find_cmd_in_env(cmd, env); //copy from pipex
			execute(full_path, input_str, info->env); //copy from pipex
			perror("execution failed"); //free stuff
		}
		else
			ft_printf("minishell: %s: command not found\n", input_str);
	}
}