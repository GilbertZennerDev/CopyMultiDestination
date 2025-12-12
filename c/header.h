#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void	ft_mkdir(char *foldername);
void	ft_loop_foldercreation(int ac, char **av);
void	ft_filefork(char *srcname, char *destname);
void	ft_folderfork(char *srcname, char *destname);
void	ft_runfork(char *srcname, char *destname, bool folder);
void	ft_loop_dests(int ac, char **av, char *srcname, bool folder);
