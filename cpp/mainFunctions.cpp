#include "header.h"

void	ft_folderfork(std::string srcname, std::string destname)
{
	unsigned int	i;
	pid_t			pid;
	char			**cmds;	

	cmds = malloc(sizeof(std::string ) * 5);
	cmds[0] = strdup("cp");
	cmds[1] = strdup("-r");
	cmds[2] = srcname;
	cmds[3] = destname;
	cmds[4] = NULL;
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

void	ft_filefork(std::string srcname, std::string destname)
{
	unsigned int	i;
	pid_t			pid;
	char			**cmds;	

	cmds = malloc(sizeof(char *) * 4);
	cmds[0] = strdup("cp");
	cmds[1] = srcname;
	cmds[2] = destname;
	cmds[3] = NULL;
	pid = fork();
	if (pid == 0)
		execvp(cmds[0], cmds);
	else if (pid > 0)
	{
		free(cmds[0]);
		free(cmds);
	}
}

void	ft_runfork(std::string srcname, std::string destname, bool folder)
{
	if (folder)
		ft_folderfork(srcname, destname);
	else
		ft_filefork(srcname, destname);
}

void	ft_loop_dests(int ac, char *av, std::string srcname, bool folder)
{
	unsigned int	i;
	std::string		t1;
	std::string		t2;

	i = 3;
	while (i < ac)
	{
		if (folder)
		{
			t1 = av[i];
			t2 = av[i + 1];
			t1 += "/" + t2;
			ft_runfork(srcname, t1, folder);
			/*free(t1);
			free(t2);*/
			i += 2;
		}
		else
		{
			ft_runfork(srcname, av[i++], folder);
		}
	}
}

void	ft_loop_foldercreation(int ac, char *av)
{
	unsigned int	i;

	i = 3;
	while (i < ac)
	{
		ft_mkdir(av[i]);
		i += 2;
	}
}
