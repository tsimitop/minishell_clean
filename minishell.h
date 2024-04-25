/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:09:13 by tsimitop          #+#    #+#             */
/*   Updated: 2024/04/25 17:02:51 by tsimitop         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>

typedef enum s_type
{
	WORD,
	PIPE,
	S_QUOTE,
	D_QUOTE,
	S_LESS,
	S_MORE,
	D_LESS,
	D_MORE
}	t_type;

typedef struct s_token //token, not token
{
	char			*input;
	int				len;
	int				i;
	t_type			token_type;
	struct s_token	*next;
} t_token;

typedef struct s_shell
{
	int		argc;
	char	**env;
	char	*cwd;
	t_token	**first_token_node;
}	t_shell;

void	initialise_basics(int argc, char **env, t_shell *info);
void	minishell_loop(t_shell *info, char *prompt, char **env);

//set_nodes
void	input_types(char *inpt, t_shell *info, t_token *first_token);
int		set_token_word(char *inpt, int i, t_token *token);
int		set_token_not_word(char *inpt, int i, t_token *token);

//utils
void	token_add_back(t_token **first_token, t_token *new);
t_token	*token_last(t_token *token);
int		skip_whitespace(char *inpt, int i);

//pipex
char	*find_path(char *argv, char **env);
char	*get_directory_name(char *argv);
char	*iter_env(char *path, char *argv);
void	execute(char *cmd, char *argv, char **env);
char	*find_cmd_in_env(char *cmd, char **env);
void	close_fd(int *fd);
void	handle_error(char *str);
void	handle_error_free(char *str);

//yun
int	inputis(char *inpt, char *string);

//checks
void	print_token(t_token *token);
void	print_linked_tokens(t_token *token);

#endif
