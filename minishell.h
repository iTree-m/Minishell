/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:09:58 by ichejra           #+#    #+#             */
/*   Updated: 2020/12/17 13:30:42 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

typedef struct		s_pipe
{
	int		backup[3];
	int		fdin;
	int		fdout;
	int		file_num;
	int		*fds;
	int		*pids;
}					t_pipe;

typedef struct		s_cmd_list
{
	char				*data;
	char				**args;
	int					start;
	int					end;
	char				*line;
	int					p;
	char				redir;
	struct s_cmd_list	*next;
	struct s_cmd_list	*prev;
}					t_cmd_list;

typedef struct	s_cmds
{
	int			index;
	char		*oldpwd;
	char		*save_oldpwd;
	int			cd;
	int			minus;
	int			exp_oldp;
	int			num_pipe;
	//char		**exp;
	//int			exp_index;

	///////////////////////
	int			quote;
	int			ignore;
	char		**cmd;
	int			counter;
	int			sep;
	char		**envir;
	char		**env_line;   //uninitialized
	char		*env_arg;
	char		*env_val;
	char		*cmd_line;
	char		*buff;
	char		*pwd;
	char		*join_arg;
	char		*line;
	int			exit_status;
	char		**split_cmd;
	char		**f_parse_line;
	t_cmd_list	*cmd_list;
	t_pipe		pipe;
}				t_cmds;


int			get_next_line(int fd, char **line);
void		parse_list_line(char **line_list, t_cmd_list *list, t_cmds *cmds);
void		parse_line(char	**line, t_cmds *cmds);
t_cmd_list	*list_line_cmds(t_cmd_list *list, char *data, int k);
t_cmd_list	*list_cmds(t_cmd_list *list, char *data, int k);
void		update_list(t_cmd_list **head, t_cmd_list **next ,t_cmd_list *new);
void		add_front(t_cmd_list **head, t_cmd_list *new);
t_cmd_list	*get_cmd(t_cmds *cmds, t_cmd_list *head);
void		cmd_cd(t_cmd_list *list, t_cmds *cmds);

//void		cmd_env(t_cmds *cmds);
int			cmd_env(t_cmds *cmds, t_cmd_list *list);

void	    cmd_pwd(t_cmds *cmds);
void		cmd_echo(t_cmd_list *list);
void		cmd_exit(t_cmds *cmds);
void		print_cmds(t_cmd_list *cmds);
void		cmd_export(t_cmd_list *list, t_cmds *cmds);
void		cmd_unset(t_cmd_list *list, t_cmds *cmds);
void		get_home_env(t_cmds *cmds);
char		**add_to_arr(char **arr, char *value, int opt);
char		**ft_envdup(char **arr);
char		**ft_setenv(char *var, char *path, char **env);
int			ft_getenv(char *name, char **env);
char		**ft_add_to_arr(char *value, char **arr);
char		**ft_get_arr(char *value, char **arr);
char		*ft_get_first(const char *s, int c);

pid_t			exec_child(t_cmds *cmds, t_cmd_list *list);
char	*get_bin_path(char *cmdfile, char **env);
//char		*ft_strcat(char *dest, char *src);


///////////////////////////////////////////////////
//char	*get_bin_path(char *filename, char **env);
//char	*try_path(char *filename, char *dir);
//int		ft_access(char *path, int mode);
///////////////////////////////////////////////////




char		*ft_strcat(char *dest, char *src);	
char		*parse_dollar(t_cmds *cmds, char **line_list);
// int			check_for_q(char *str, int j);
char		*ft_remove_quotes(char *res);
int			is_quote(int c);
char		**split_cmd(char const *str, char c, t_cmds *cmds);
int			quote_activer(int c, int quote);
int			handle_stx_err(char **ln, t_cmds *cmds);
int			check_redir(char **ln, t_cmds *cmds);
int			check_q(char **ln, t_cmds *cmds);
int			get_sy_err();
void		ft_free_str(char **str);
void		free_cmd_list(t_cmds *list);
#endif