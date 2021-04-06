#include <args_cooker.h>

/*
** If there are no arguments, return cleanly
**
*/

t_stacks *args_cooker(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(*stacks));
	if (argc == 1)
		return (0);
	while (*argv)
	{
		if (ft_str_isdigit(*argv))
			return(simple_error());
		if (ft_atoi(*argv) > INT_MAX)
			return(simple_error());
		argv++;
	}
	return (stacks);
}
