#include "header.h"

int	main(int ac, char **av)
{
	char	*srcname;

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
