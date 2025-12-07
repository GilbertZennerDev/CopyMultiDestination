/*
	//else if (strcmp(av[1], "-folder") == 0 && ft_isfolder(srcname))
	//	cp = strdup("/bin/cp -r");
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
}

void	ft_runfork(char *srcname, char *destname, bool folder)
{
	pid_t	pid;
	char	**cmds;

	printf("Running fork\n");
	cmds = malloc(sizeof(char *) * 4);
	if (folder)
		cmds[0] = strdup("cp -r");
	else
		cmds[0] = strdup("cp");
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

/*

I need to have df/f from df and f
i have df and f, I need to get df/f

t1 = strcat(df, "/")
t2 = strcat(t1, f)
strcat(df, f)
done

*/

void	ft_loop_dests(int ac, char **av, char *srcname, bool folder)
{
	unsigned int	i;
	char			*t1;
	char			*t2;

	i = 3;
	while (i < ac)
	{
		if (folder)
		{
			printf("debug avi: %s %s\n", av[i], av[i+1]);
			strcat(av[i], "/");
			t1 = av[i];		
			strcat(t1, av[i+1]);
			printf("debug t1: %s\n", t1);
			//t2 = strcat(t1, av[i + 1]);
			//printf("debug t2: %s\n", t2);
			ft_runfork(srcname, t2, folder);
			free(t1);
			free(t2);
			i += 2;
		}
		else
		{
			ft_runfork(srcname, av[i++], folder);
		}
	}
}

void	ft_loop_foldercreation(int ac, char **av)
{
	unsigned int	i;
	char			*destname;

	i = 3;
	while (i < ac)
	{
		ft_mkdir(av[i]);
		i += 2;
	}
}

int	main(int ac, char **av)
{
	char			*srcname;

	if (ac < 4)
		return (1);
	srcname = strdup(av[2]);
	if (strcmp(av[1], "-file") == 0)
		ft_loop_dests(ac, av, srcname, false);
	if (strcmp(av[1], "-folder") == 0)
	{
		ft_loop_foldercreation(ac, av);
		ft_loop_dests(ac, av, srcname, true);
	}
	free(srcname);
	return (0);
}
