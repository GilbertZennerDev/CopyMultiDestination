#include "header.hpp"

int	main(int ac, char **av)
{
	std::string srcname;

	if (ac < 4)
		return (1);
	CPM cpm;
	srcname = av[2];
	//srcname = strdup(av[2]);
	if (av[1] == "-file")
		ft_loop_dests(ac, av, srcname, false);
	/*if (strcmp(av[1], "-folder") == 0)
	{
		ft_loop_foldercreation(ac, av);
		ft_loop_dests(ac, av, srcname, true);
	}
	free(srcname);*/
	return (0);
}
