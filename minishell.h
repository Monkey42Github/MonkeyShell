#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <signal.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>

# define CHAR " \t"

typedef struct cmd
{
	char		**list_token;
	int			nb_token;
	int			num_cmd;
	struct cmd	*next;
	struct cmd	*before;
	char		*cmd_path;
	int			fd[2];
	int			top_redir;
	char		**cmd_redir;
	int			fd_in;
	int			fd_out;
	int			redir_in;
	int			redir_out;
	int			top_path;
}	t_cmd;

typedef struct minishell{
	char		**env;
	char		*prompt;
	char		*cmd;
	char		**list_token;
	int			nb_cmd;
	int			dollar;
	int			keypipe;
	char		*home;
	t_cmd		*list_cmd;
}t_data_mini;

void	initial_vars_dollar(int *i, int *ii);
void	termios_2(int ctr, t_data_mini *data, char c);
int		ft_strcmp(char *s1, char *s2);
char	ft_mot_command(char *str, int i);
int		verif_quote(char *str, char c, char r);
char	*ft_strchr(const char *s, int c);
void	lexer(t_data_mini *data);
int		ft_parcing_readline(t_data_mini *data);
int		ft_strlen(const char *tab);
int		ft_strcmp_export(char *s1, char *s2);
char	*skeep_qotes(char *str, char c);
char	**ft_split(const char *s);
void	add_space_pipe(t_data_mini *data);
void	add_space_redir(t_data_mini *data);
int		count_p(char *str);
int		v_quote(char *str, char a, char b);
int		count_redir(char *cmd);
int		verif_redir(char *cmd);
char	*ft_strjoin(char const *s1, char const *s2);
int		did_var_exist(t_data_mini *data, char *token);
t_cmd	*init_all_cmd(int nb_cmd, char **token_cmd);
int		get_nb_cmd(char **token_cmd);
void	run_shell(t_data_mini *data);
int		ft_verif_all(t_data_mini *data);
void	supp_char(t_data_mini *data, char c);
int		cmd_empty(char *str);
void	manage_quote_err(t_data_mini *data);
void	manage_pipe(t_data_mini *data);

void	ft_command(t_data_mini *data);
void	ft_clean_all(t_data_mini *data);
void	ft_clean_quotes(t_data_mini *data);
char	*get_cmd_path(char **env, char	*cmd);
char	*ft_strjoin_3(char *s1, char *s2, char *s3);
char	*ft_strcpy(char *dst, const char *src);
void	manage_dollar(t_data_mini *data);
char	*ft_strjoin_33(char *s1, char *s2, char *s3);
void	ft_free_tab(char **tab);
void	manage_redir_out(t_cmd *cmd);
int		is_redir(char **list_token);
char	**get_cmd_redir(char **list_token);
void	ft_open_close_pipe_red(t_cmd *cmd, int i, int nb_cmd);
int		check_if_redir(t_data_mini *data);
char	*rl_gets(char *prompt);
char	*rl_gets_init(t_data_mini *data);
void	ft_run_pipe(t_data_mini *data, int i);
void	close_all_pipe(t_cmd *cmd, int i);
char	*ft_strdup(const char *src);
int		ft_find_path(t_data_mini *data);
char	*ft_itoa(int nb);
int		ft_len_tab(char **list_token);

// builtins
int		ft_is_builtin_1(char *cmd);
int		ft_is_builtin_2(char *cmd);
int		ft_run_builtin_1(t_data_mini *data);
int		ft_run_builtin_2(t_data_mini *data);
char	*get_var_to_add(char	*str);
int		*init_tab(char **env);
void	ft_export_var_bis_2(int i, char \
*token, int top_var_exist, char **new_env);
int		ft_export_var_bis_1(t_data_mini *data, \
char **new_env, int *i, char *token);
int		verif_token_export(char *token);
int		is_only_digit(char *token);
int		is_valid_char(char c);
void	ft_export_var(t_data_mini *data, char *token);
char	*get_var_to_add(char	*str);
char	**malloc_new_env_export(char **env, char *var_to_add);
void	ft_free_tab(char **tab);
char	**ft_test_1(char **env);
char	**ft_split_1(char *s, char c);
int		count_words_1(char *str, char c);
char	*get_new_value(char *var, char **env);
char	*get_var(char *cmd, int *i);

int		ft_search_pwd(t_data_mini *data, char *var);
void	ft_cd(t_data_mini *data);
void	ft_echo(t_data_mini *data);
void	ft_env(t_data_mini *data);
void	ft_pwd(t_data_mini *data);
void	ft_export(t_data_mini *data);
char	**new_env(t_data_mini *data, char *var);
void	ft_unset(t_data_mini *data);
char	*get_var_to_add(char *str);
int		verif_token_export(char *token);
void	ft_export_var(t_data_mini *data, char *token);
void	ft_exit(t_data_mini *data);
void	termios(int ctl);

#endif