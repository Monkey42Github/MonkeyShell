#include "../minishell.h"

void	ign(int sig_num)
{
	if (sig_num == SIGQUIT)
		printf("Quit: 3\n");
}

void	handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

void	termios(int ctl)
{
	struct termios	termios_p;
	int				tty;

	tty = ttyslot();
	tcgetattr(tty, &termios_p);
	if (ctl)
	{
		termios_p.c_lflag |= ECHOCTL;
		signal(SIGINT, ign);
		signal(SIGQUIT, ign);
	}
	else
	{
		termios_p.c_lflag &= ~(ECHOCTL);
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
	}
	tcsetattr(tty, TCSANOW, &termios_p);
}
