#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	is_repeated(int *array, size_t index, int number)
{
	for (size_t i = 0; i < index; i++)
	{
		if (array[i] == number)
			return (1);
	}
	return (0);
}

void	generate_numbers(size_t size, int max)
{
	int current;
	int *numbers;

	numbers = calloc(sizeof(int), size);

	for (size_t i = 0; i < size; i++)
	{
		do
			current = rand() % (max + 1);
		while  (is_repeated(numbers, i, current));
		numbers[i] = current;

		printf("%d ", current);
	}
	puts("");
	
	free(numbers);
}

int main(int argc, char *argv[])
{
	size_t size;
	int max;

	if (argc != 3)
	{
		fprintf(stderr, "USAGE: %s SIZE MAX_NUMBER\n", *argv);
		return (EXIT_FAILURE);
	}

	size = atol(argv[1]);
	max = atoi(argv[2]);

	if (size <= 0 || max <= 0)
	{
		fprintf(stderr, "Wrong CLI arguments\n");
		return (EXIT_FAILURE);
	}

	srand(time(NULL));
	generate_numbers(size, max);
	return (EXIT_SUCCESS);
}
