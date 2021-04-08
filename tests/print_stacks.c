#include <checker.h>
#include <common.h>
#include <args_cooker.h>
#include <processor.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_list		*a;

	stacks = args_cooker(argc, argv);
	if (!stacks)
	{
		printf("Error\n");
		return (0);
	}
	a = stacks->a;
	while (a)
	{
		printf("->| %d |<-\n", (int)a->content);
		a = a->next;
	}
}
