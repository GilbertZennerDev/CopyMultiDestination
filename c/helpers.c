#include "header.h"

void	ft_mkdir(char *foldername)
{
	pid_t	pid;
	char	**cmds;

	cmds = malloc(sizeof(char *) * 4);
	cmds[0] = strdup("mkdir");
	cmds[1] = strdup("-p");
	cmds[2] = foldername;
	cmds[3] = NULL;
	pid = fork();
	if (pid == 0)
		execvp(cmds[0], cmds);
	else if (pid > 0)
	{
		free(cmds[0]);
		free(cmds[1]);
		free(cmds);
	}
}
