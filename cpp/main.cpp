#include <string>
#include <vector>
#include <iostream>
#include <sys/wait.h>
using namespace std;

void	runFileFork(string src, string dest)
{
	pid_t		pid;
	vector<char *>	cmds;
	char		**cmd_c;

	cmds.push_back((char *) string("cp").c_str());
	cmds.push_back((char *) src.c_str());
	cmds.push_back((char *) dest.c_str());
	cmds.push_back(NULL);
	cmd_c = &cmds[0];
	pid = fork();
	if (pid == 0)
		execvp(cmd_c[0], cmd_c);
	else
		wait(NULL);
}

int	main(int ac, char **av)
{
	unsigned int	i;
	string		src;
	vector<string>	dests;

	if (ac < 4) return (1);
	src = string(av[1]);
	for (i = 2; i < ac; i++) dests.push_back(av[i]);
	i = 0;
	while (i < dests.size())
		runFileFork(src, dests[i++]);
	return (0);
}
