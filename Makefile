GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = minishell

PROJECT = MINISHELL

SRCS = minishell.c outils/split_cmd.c outils/clean_quotes.c outils/outils.c outils/ft_itoa.c \
			parsing/p_add_space.c parsing/p_count.c parsing/p_lexer.c parsing/p_outils.c parsing/p_verif.c parsing/parsing.c \
			parsing/p_split.c parsing/p_manage_quote_pipe.c  parsing/p_outils_2.c  parsing/p_verif_2.c \
			find_path/find_path.c  find_path/find_path_2.c outils/manage_dollar.c outils/manage_dollar_2.c redir/manage_redir_out.c redir/manage_redir_in.c redir/manage_redir_in_2.c\
			builtins/b_builtins.c builtins/b_cd.c builtins/b_echo.c builtins/b_exit.c builtins/b_env.c builtins/b_outils.c builtins/b_pwd.c \
			builtins/b_export.c builtins/b_export_2.c builtins/b_export_3.c builtins/b_unset.c outils/signaux.c  outils/run_cmd.c outils/run_cmd_2.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = -I./includes -I./includes/readline/include

all: $(NAME)

rl:
	@rm -rf req.sh
	@rm -rf t
	@printf "\033[1;33m"
	@echo "if [[ ! -d "includes/readline" ]]" > req.sh
	@echo "then" >> req.sh
	@echo "\ttouch readline-8.1.tar.gz" >> req.sh
	@echo "\techo "Creating readline library..."" >> req.sh
	@echo "\tcurl -ks https://ftp.gnu.org/gnu/readline/readline-8.1.tar.gz > readline-8.1.tar.gz" >> req.sh
	@echo "\t(tar -xf readline-8.1.tar.gz) >> t"  >> req.sh
	@echo "\tmv readline-8.1 readline" >> req.sh
	@echo "\trm -rf readline-8.1.tar.gz" >> req.sh
	@echo "\tmv readline includes" >> req.sh
	@echo "\tcd includes/readline/" >> req.sh
	@echo "\t(./configure --prefix=$$(pwd)/includes/readline) >> t" >> req.sh
	@echo "\tmake && make install && make clean" >> req.sh
	@echo "\trm -rf t" >> req.sh
	@echo "\tcd ../../" >> req.sh
	@echo "\tclear" >> req.sh
	@echo "\techo "📁 SUCCESS: readline folder has been created!"" >> req.sh
	@echo "fi" >> req.sh
	@sh req.sh
	@rm -rf t
	@rm -rf req.sh
	@stty -echoctl

.c.o: $(SRCS)
	@make rl
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@gcc $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) -lreadline -L./includes/readline/lib -lncurses
	@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(NAME)$(GREEN)" has been created\n"$(RESET)

clean:
	@rm -rf $(OBJS) 
	@rm -rf includes
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
	@printf $(RED)"\r\033[K➜ [READLINE] library folder has been "$(WHITE)"removed"$(RED)"\n"$(RESET)

fclean:
	@rm -rf $(OBJS)
	@rm -rf includes
	@rm -rf $(NAME)
	@printf $(RED)"\r\033[K➜ [READLINE] library folder has been "$(WHITE)"removed"$(RED)"\n"$(RESET)
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"fclean"$(RED)" has been done\n"$(RESET)

re: fclean all

fre:
	@rm -rf $(OBJS) 
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"fclean"$(RED)" has been done\n"$(RESET)
	@make all

.PHONY: all clean fclean re fre rl