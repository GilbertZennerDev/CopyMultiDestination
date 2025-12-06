/*
	//else if (strcmp(av[1], "-folder") == 0 && ft_isfolder(srcname))
	//	cp = strdup("/bin/cp -r");
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void	ft_runfork(char *cp, char *srcname, char *destname)
{
	pid_t	pid;
	char	**cmds;

	cmds = malloc(sizeof(char *) * 4);
	cmds[0] = cp;
	cmds[1] = srcname;
	cmds[2] = destname;
	cmds[3] = NULL;
	pid = fork();
	if (pid == 0)
		execvp(cmds[0], cmds);
}

bool	ft_isfolder(char *srcname)
{
	unsigned int	i;

	i = 0;
	while (srcname[i])
	{
		if (srcname[i] == '/')
			return (true);
		++i;
	}
	return (false);
}

void	ft_loop_dests(int ac, char **av, char *cp, char *srcname)
{
	unsigned int	i;
	char			*destname;

	i = 3;
	while (i < ac)
	{
		destname = strdup(av[i++]);
		ft_runfork(cp, srcname, destname);
		free(destname);
	}
}

int	main(int ac, char **av)
{
	char			*cp;
	char			*srcname;

	if (ac < 4)
		return (1);
	srcname = strdup(av[2]);
	if (strcmp(av[1], "-file") == 0)
		cp = strdup("/bin/cp");
	else
		exit(1);
	ft_loop_dests(ac, av, cp, srcname);
	free(cp);
	free(srcname);
	return (0);
}
