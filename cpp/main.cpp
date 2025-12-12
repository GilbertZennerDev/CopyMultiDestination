#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>

void	runFolderFork(std::string src, std::string dest)
{
	unsigned int	i;
	pid_t		pid;
	char		**cmds;

	// cp file dest1 dest2
	cmds = (char **)malloc(sizeof(char *) * 5);
	cmds[0] = strdup("cp");
	cmds[1] = strdup("-r");
	cmds[2] = strdup(src.c_str());
	cmds[3] = strdup(dest.c_str());
	cmds[4] = NULL;
	
	pid = fork();
	if (pid == 0)
		execvp(cmds[0], cmds);
	else
	{
		i = 0;
		wait(NULL);
		while (i < 5)
			free(cmds[i++]);
		free(cmds);
	}
}

int	main(int ac, char **av)
{
	unsigned int			i;
	std::string 			src;
	std::vector<std::string>	dests;

	if (ac < 4)
		return (1);
	src = std::string(av[1]);
	for (int i = 2; i < ac; i++)
		dests.push_back(av[i]);
	i = 0;
	while (i < dests.size())
		runFolderFork(src, dests[i++]);
	return (0);
}
